#pragma once
#include <iostream>
#include "Pair.h"

template<class K, class V>
class Map : public Pair<K, V>
{
private:
	int existsKey(K key);
	int existsValue(V val);
public:
	Pair<K, V> myMap[10];
	int currentIndex = 0;
	inline static int i = 0;
public:
	V& operator[] (const K& key);
	void print();
	Pair<K, V>* begin();
	Pair<K, V>* end();
	void SetValueToKey(const K& key, const V& val);
	bool Get(const K& key, V& value);
	int Count();
	void Clear();
	bool Delete(const K& key);
	K getKey(int poz);
	bool Includes(Map<K, V>& map);
};
template<class K, class V>
int Map<K, V>::existsKey(K key)
{
	for (int i = 0; i < currentIndex; i++)
	{
		if (myMap[i].Key == key)
		{
			return i;
		}
	}
	return -1;
}
template<class K, class V>
int Map<K, V>::existsValue(V val)
{
	for (int i = 0; i < currentIndex; i++)
	{
		if (myMap[i].Value == val)
		{
			return i;
		}
	}
	return -1;
}

template<class K, class V>
V& Map<K, V>::operator[] (const K& key)
{
	int poz = existsKey(key);
		if (poz != -1)
		{
			return myMap[poz].Value;
		}
	myMap[currentIndex].addKey(key);
	myMap[currentIndex].index = currentIndex;
	return myMap[currentIndex++].Value;
}
template<class K, class V>
void Map<K, V>::print()
{
	for (int i = 0; i < currentIndex; i++)
	{
		std::cout << myMap[i].Key << " " << myMap[i].Value << " \n";
	}
}
template<class K, class V>
Pair<K, V>* Map<K, V>::begin()
{
	return &myMap[0];
}
template<class K, class V>
Pair<K, V>* Map<K, V>::end()
{
	return &myMap[currentIndex];
}
template<class K, class V>
void Map<K, V>::SetValueToKey(const K& key, const V& val)
{
	bool thereIsAKey = false;
	for (int i = 0; i < currentIndex; i++)
	{
		if (myMap[i].Key == key)
		{
			myMap[i].addValue(val);
			thereIsAKey = true;
		}
	}
	if (!thereIsAKey)
	{
		myMap[currentIndex].index = currentIndex;
		myMap[currentIndex++].addElement(key, val);
	}
}
template<class K, class V>
bool Map<K, V>::Get(const K& key, V& value)
{
	int poz = existsKey(key);
	if (poz != -1)
	{
		value = myMap[poz].Value;
		return true;
	}
	return false;
}
template <class K, class V>
int Map<K, V>::Count()
{
	return currentIndex;
}
template<class K, class V>
void Map<K, V>::Clear()
{
	for (int i = currentIndex - 1; i >= 0; i--)
	{
		myMap[i].Key = myMap[i + 1].Key;
		myMap[i].Value = myMap[i + 1].Value;
	}
	currentIndex = 0;
}
template<class K, class V>
bool Map<K, V>::Delete(const K& key)
{
	int poz = existsKey(key);
	if (poz != -1)
	{
		currentIndex--;
		for (int i = poz; i < currentIndex; i++)
		{
			myMap[i].Key = myMap[i + 1].Key;
			myMap[i].Value = myMap[i + 1].Value;
		}
		return true;
	}
	return false;
}
template<class K, class V>
K Map<K, V>::getKey(int poz)
{
	return myMap[poz].Key;
}
template<class K, class V>
bool Map<K, V>::Includes(Map<K, V>& mapp)
{
	int elementsOfMap = mapp.Count();
	if (elementsOfMap > currentIndex)
	{
		elementsOfMap = currentIndex;
	}
	for (int i = 0; i < elementsOfMap; i++)
	{
		if (mapp.getKey(i) != myMap[i].Key)
		{
			return false;
		}
	}
	return true;
}