#include "Number.h"

Number::Number(const char* value, int base)
{
	this->base = base;

	int i = 0, nr = 0;

	strcpy_s(this->number, value);
}

Number::Number(const Number& TempNumber)
{
	strcpy_s(this->number, TempNumber.number);
	this->base = TempNumber.base;
}

Number::Number(int n)
{
	Number::TransformFromBaseTen(n, 10, this->number);
	this->base = 10;
}

Number::~Number()
{

}

void Number::SwitchBase(int newBase)
{
	Number::TransformFromBaseTen(Number::TransformToBaseTen(this->number, this->base), newBase, this->number);
}

int Number::TransformToBaseTen(char* value, int prevBase)
{
	int i = 0, nr = 0, aux = 0;;

	while (value[i] != NULL)
	{
		if (value[i] >= 'A' && value[i] <= 'X')
		{
			aux = value[i] - 'A' + 10;
		}
		else
		{
			aux = value[i] - '0';
		}

		nr = nr * prevBase + aux;
		i++;
	}

	return nr;
}

void Number::TransformFromBaseTen(int value, int base, char* returned)
{
	char aux[100];

	int i = 0, j = 0, rest = 0;

	while (value != 0)
	{
		rest = value % base;

		if (rest >= 10)
		{
			aux[i] = 'A' + (rest - 10);
		}
		else
		{
			aux[i] = '0' + rest;
		}

		value = value / base;
		i++;
	}

	i--;

	while (i >= 0)
	{
		returned[j] = aux[i];

		j++;
		i--;
	}
	returned[j] = '\0';
}

void Number::Print()
{
	std::cout << (this->number) << '\n';
}

int Number::GetDigitsCount()
{
	int nr = 0;

	while ((this->number)[nr] != '\0')
	{
		nr++;
	}

	return nr;
}

int Number::GetBase()
{
	return this->base;
}

char Number::operator [](int index)
{
	return (this->number)[index];
}

Number& Number::operator-- ()
{
	strcpy_s(this->number, this->number + 1);

	return (*this);
}

Number& Number::operator-- (int)
{
	this->number[this->GetDigitsCount() - 1] = '\0';

	return (*this);
}

Number& operator +(Number& n1, Number& n2)
{
	int maxBase = 0;
	int sum = Number::TransformToBaseTen(n1.number, n1.base) + Number::TransformToBaseTen(n2.number, n2.base);

	if (n1.base > n2.base)
	{
		maxBase = n1.base;
	}
	else
	{
		maxBase = n2.base;
	}

	char aux[100];
	Number::TransformFromBaseTen(sum, maxBase, aux);

	Number n(aux, maxBase);

	return n;
}

Number& operator -(Number& n1, Number& n2)
{
	int maxBase = 0;
	int sum = Number::TransformToBaseTen(n1.number, n1.base) - Number::TransformToBaseTen(n2.number, n2.base);

	if (n1.base > n2.base)
	{
		maxBase = n1.base;
	}
	else
	{
		maxBase = n2.base;
	}

	char aux[100];
	Number::TransformFromBaseTen(sum, maxBase, aux);

	Number n(aux, maxBase);

	return n;
}

bool operator >(Number& n1, Number& n2)
{

	int a = Number::TransformToBaseTen(n1.number, n1.base);
	int b = Number::TransformToBaseTen(n2.number, n2.base);

	return (a > b);
}

bool operator <(Number& n1, Number& n2)
{

	int a = Number::TransformToBaseTen(n1.number, n1.base);
	int b = Number::TransformToBaseTen(n2.number, n2.base);

	return (a < b);
}

bool operator ==(Number& n1, Number& n2)
{

	int a = Number::TransformToBaseTen(n1.number, n1.base);
	int b = Number::TransformToBaseTen(n2.number, n2.base);

	return (a < b);
}

Number& Number::operator= (int n)
{
	TransformFromBaseTen(n, this->base, this->number);
	return (*this);
}
