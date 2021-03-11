#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	ifstream f("f1.in");
	ofstream g("f1.out");
	char c[100], * p, a[100], b[100]; int i, j, x, sum = 0;
	while (f.getline(c, 100))
	{
		p = strtok(c, " ");
		//sum=0;
		while (p)
		{
			strcpy(b, p); x = 0;
			for (i = 0; i <= strlen(b) - 1; i++)
			{
				int a = b[i] - '0';
				x = x * 10 + a;
			}
			sum = sum + x;

			p = strtok(NULL, " ");

		}
		g << sum << endl;
	}


	f.close(); g.close();

	return 0;
}