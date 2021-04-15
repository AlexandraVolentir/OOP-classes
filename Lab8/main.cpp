#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <utility>

std::string toLower(std::string& word)
{
	for (std::string::iterator it = word.begin(); it != word.end(); it++)
	{
		if (isupper(*it))
		{
			*it += 32;
		}
	}
	return word;
}
struct Comparator
{
	bool operator()(std::pair<std::string, int> a, std::pair<std::string, int> b)
	{
		if (a.second != b.second)
		{
			return (a.second < b.second);
		}
		return (a.first > b.first);
	}
};
int main()
{
	std::ifstream file("sentence.txt");
	std::string sentence;
	std::getline(file, sentence);
	//std::cout << sentence;
	std::map<std::string, int> Words;
	std::map<std::string, int>::iterator it;
	std::string delimiters = " .,?!";
	size_t begin, position = 0;

	/*creez priority queue care are ca elemente un pair de string si int, folosind ca subclasa un vector si functia comparator ca sa sorteze*/
	std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Comparator > SetPriority;

	while ((begin = sentence.find_first_not_of(delimiters, position)) != std::string::npos)
	{
		position = sentence.find_first_of(delimiters, begin);
		std::string word = sentence.substr(begin, position - begin);
		word = toLower(word);
		Words[word]++;
	}
	for (it = Words.begin(); it != Words.end(); it++)
	{
		SetPriority.push(make_pair(it->first, it->second));
		std::cout << it->first << " : " << it->second << "\n";
	}
	std::cout << "------------------\n";
	while (!SetPriority.empty())
	{
		std::cout << SetPriority.top().first << " => " << SetPriority.top().second << "\n";
		SetPriority.pop();
	}
	return 0;
}