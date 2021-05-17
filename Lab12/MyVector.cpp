#include "MyVector.h"

#include <iostream>

MyVector::MyVector():size(1), count(0)
{
	vector = new int;
}

MyVector::MyVector(size_t size):size(size), count(0)
{
	vector = new int [size];
}

MyVector::MyVector(MyVector& other)
{
	size = other.size;
	count = other.count;
	vector = new int[size];

	for (int i = 0; i < count; i++)
	{
		vector[i] = other.vector[i];
	}
}

bool MyVector::Add(int number)
{
	if (size == count)
	{
		MyVector tmp = *this;
		size *= 2;

		delete[] vector;
		vector = new int [size];
		for (int i = 0; i < count; i++)
			vector[i] = tmp.vector[i];
		
	}

	vector[count++] = number;
	return 1;
}

bool MyVector::Delete(int index)
{
	MyVector tmp = *this;
	delete[] vector;
	vector = new int[size];
	for (int i = 0; i < index; i++)
	{
		vector[i] = tmp.vector[i];
	}
	for (int i = index; i < count; i++)
	{
		vector[i] = tmp.vector[i + 1];
	}
	count--;
	return 1;
	
}

void MyVector::Iterate(int(*iterator)(int& a))
{
	for (int i = 0; i < count; i++)
	{
		vector[i] = iterator(vector[i]);
	}
}

void MyVector::Filter(int(*rmv)(int a))
{
	int var = count;
	for (int i = var - 1; i >= 0; i--)
		if (rmv(vector[i])) 
		{ 
			this->Delete(i); 
		}
}




void MyVector::PrintArray()
{
	std::cout << "\n";
	for (int i = 0; i < count; i++)
	{
		std::cout << vector[i] << std::endl;
	}
	std::cout << "\n";
}

