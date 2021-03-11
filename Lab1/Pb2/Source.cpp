#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int i, j;
	char aux[100], b[100], c[100], * p;
	cin.getline(c, 100);
	strcpy(aux, c);

	for (i = 20; i >= 1; i--) {
		strcpy(c, aux);
		p = strtok(c, " ");
		while (p)
		{
			strcpy(b, p);
			if (strlen(b) == i)
				cout << b << endl;
			p = strtok(NULL, " ");
		}
	}

	return 0;
}