#pragma once
#include <map>
template<class K, class V>
class Pair
{
public:
	K Key;
	V Value;
	int index;
public:
	void addElement(const K& key, const V& value)
	{
		Key = key;
		Value = value;
	}
	void addKey(const K& key)
	{
		Key = key;
	}
	void addValue(const V& value)
	{
		Value = value;
	}

};