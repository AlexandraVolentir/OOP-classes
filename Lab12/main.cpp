#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "MyVector.h"

int main()
{
	std::vector<std::string> vector_of_strings = {"ginger", "sky", "heaven", "green", "header"};
	auto Sort = [](std::string a, std::string b) 
	{
		if (a.length() != b.length())
			return (a.length() < b.length());
		else
			return (a < b);
	};
	
	std::sort(vector_of_strings.begin(), vector_of_strings.end(), Sort);
	for (auto& s : vector_of_strings)
		std::cout << s << std::endl;

	auto iterate_function = [](int& a) -> int 
	{ 
		a += 190; return a; 
	};
	
	auto filter_function = [](int a) -> int
	{
		if (a % 5 == 0) { return 1; }
		return 0;
	};

	MyVector obj;
	obj.Add(5);
	obj.Add(90);
	obj.Add(7);
	obj.Add(25);
	obj.Add(49);
	obj.Add(30);
	obj.Add(68);
	std::cout << "Array-ul dupa introducerea elementelor: ";
	obj.PrintArray();
	
	std::cout << "Array ul dupa stergerea elementului cu indexul 2 ";
	obj.Delete(2);
	obj.PrintArray();
	
	std::cout << "Array-ul dupa functia iterate, care incrementeaza cu 190 ";
	obj.Iterate(iterate_function);
	obj.PrintArray();

	std::cout << "Array-ul dupa functia filtru ce elmina elementele divizibile cu 5 ";
	obj.Filter(filter_function);
	obj.PrintArray();

}