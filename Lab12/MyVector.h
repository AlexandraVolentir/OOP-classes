#pragma once
class MyVector
{
	int* vector;
	size_t size;
	size_t count;
public:
	MyVector();
	MyVector(size_t size);
	MyVector(MyVector& other);
	bool Add(int); // return true if the value was added. As a result, the size of the vector increases with one.
	bool Delete(int index); // returns true if the value from the index was removed. As a result, the size of the vector decreases with one.
	void Iterate(int(*iterator)(int &a));
	void Filter(int(*rmv)(int a));
	void PrintArray();
};

