#include <cstring>
#include <iostream>
#include <stdarg.h>

#include "Sort.h"

Sort::Sort (unsigned int count, int min, int max) : size(count)
{
	if (min == max)
	{
		printf ("The minimum value cannot be equal to the maximum value\n");
		max++;
	}
	if (min > max)
		std::swap (min, max);

	vector = new int[size];

	for (int i = 0; i < size; i++)
		vector[i] = rand () % (max - min) + min;
}
Sort::Sort (int* array, unsigned int count) : size(count)
{
	vector = new int[size];

	for (int i = 0; i < size; i++)
		vector[i] = array[i];
}
Sort::Sort (const char* string) : size(1)
{
	for (int i = 0; i < strlen (string); i++)
		if (string[i] == ',')
			size++;

	char* temp = new char[strlen (string) + 1];
	strcpy (temp, string);

	vector = new int[size + 1];
	int i = 0;

	char* p = strtok (temp, ",");
	while (p)
	{
		vector[i++] = atoi (p);
		p = strtok (nullptr, ",");
	}

	delete[] temp;
}
Sort::Sort (unsigned int size, ...) : size(size)
{
	vector = new int[size];

	va_list arg;
	va_start (arg, size);

	for (int i = 0; i < size; i++)
		vector[i] = va_arg (arg, int);

	va_end (arg);
}
Sort::~Sort ()
{
	size = 0;
	delete[] vector;
}

void Sort::bubbleSort (bool ascendent)
{
	bool swapped = true;

	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < size - 1; i++)
			if (vector[i] > vector[i + 1])
			{
				std::swap (vector[i], vector[i + 1]);
				swapped = true;
			}
	}

	if (!ascendent)
		reverse ();
}
void Sort::insertSort (bool ascendent)
{
	for (int i = 1; i < size; i++)
	{
		int key = vector[i], j = i - 1;
		while (j>= 0 && vector[j] > key)
		{
			vector[j + 1] = vector[j];
			j--;
		}
		vector[j + 1] = key;
	}

	if (!ascendent)
		reverse ();
}
int qsPartition (int* array, int low, int high)
{
	int pivot = array[high], i = low;

	for (int j = low; j < high; j++)
		if (array[j] < pivot)
		{
			std::swap (array[i], array[j]);
			i++;
		}
	std::swap (array[i], array[high]);

	return i;
}
void qsNoReverse (int* array, int low, int high)
{
	if (low < high)
	{
		int pivot = qsPartition (array, low, high);

		qsNoReverse (array, low, pivot - 1);
		qsNoReverse (array, pivot + 1, high);
	}
}
void Sort::quickSort (int low, int high, bool ascendant)
{
	qsNoReverse (vector, low, high);

	if (!ascendant)
		reverse ();
}
void Sort::reverse ()
{
	for (int i = 0; i < size / 2; i++)
		std::swap (vector[i], vector[size - i - 1]);
}

int Sort::getElementCount ()
{
	return size;
}

int Sort::getElementFromIndex (unsigned int index)
{
	if (index < size)
		return vector[index];
	else
	{
		printf ("Out of range\n");
		return -1;
	}
}
void Sort::print ()
{
	for (int i = 0; i < size; i++)
		printf ("%d ", vector[i]);
	printf ("\n");
}

void Sort::merge (Sort& list)
{
	this->quickSort (0, size - 1, true);
	list.quickSort (0, list.getElementCount () - 1, true);

	int* copie = new int[size];
	for (int i = 0; i < size; i++)
		copie[i] = vector[i];

	vector = new int[size + list.size];

	int i = 0, j = 0, k = 0;
	while (i < size && j < list.size)
		if (copie[i] < list.vector[j])
			vector[k++] = copie[i++];
		else
			vector[k++] = list.vector[j++];
	while (i < size)
		vector[k++] = copie[i++];
	while (j < list.size)
		vector[k++] = list.vector[j++];

	size += list.size;
	delete[] copie;
}
