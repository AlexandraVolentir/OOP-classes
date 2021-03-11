#include "Math.h"
#include <stdarg.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS //for strcpy

using namespace std;

int Math::Add(int x, int y)
{
	return x + y;
}

int  Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int  Math::Add(double x, double y)
{
	return x + y;
}

int  Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int  Math::Mul(int x, int y)
{
	return x + y;
}

int  Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int  Math::Mul(double x, double y)
{
	return x * y;
}

int  Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int  Math::Add(int count, ...) 
{
	int s = 0;
	va_list lista;
	va_start(lista, count);
	for (int i = 0; i < count; i++)
		s = s + va_arg(lista, int);
	va_end(lista);
	return s;
}

char* Math::Add(const char* x, const char* y)
{
	if (x == nullptr || y == nullptr)
		return nullptr;
	if (x == "")
		return (char*)y;
	if (y == "")
		return (char*)x;

	int len = max(strlen(x), strlen(y)) + 1;
	char* result = new char[len + 2]{};
	char* a = new char[strlen(x) + 1], *b = new char[strlen(y) + 1];

	strcpy(a, x);
	strcpy(b, y);
	_strrev(a);
	_strrev(b);

	for (int i = strlen(a); i < len; i++)
		a[i] = '0';
	for (int i = strlen(b); i < len; i++)
		b[i] = '0';

	for (int i = 0; i <= len; i++)
	{
		result[i] += a[i] + b[i] - '0';
		if (result[i] > 9 + '0')
		{
			result[i] -= 10;
			result[i + 1]++;
		}
	}

	result[len] = 0;
	if (result[len - 1] == '0')
		result[len - 1] = 0;

	_strrev(result);

	return result;
}
