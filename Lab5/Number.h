#pragma once
#include <cstring>
#include <iostream>

class Number
{
	char number[100];
	int base;
	// add data members

	static int TransformToBaseTen(char* value, int prevBase);
	static void TransformFromBaseTen(int value, int base, char* returned);

public:

	Number(const char* value, int base); // where base is between 2 and 16

	~Number();


	// add operators and copy/move constructor

	Number(const Number& TempNumber);
	Number(int n);

	char operator [](int index);

	Number& operator-- ();
	Number& operator-- (int);

	Number& operator= (int n);

	friend Number& operator +(Number& n1, Number& n2);
	friend Number& operator -(Number& n1, Number& n2);

	friend bool operator > (Number& n1, Number& n2);
	friend bool operator < (Number& n1, Number& n2);
	friend bool operator == (Number& n1, Number& n2);

	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

};