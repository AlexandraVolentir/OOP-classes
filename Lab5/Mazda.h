#pragma once
#include "Car.h"
class Mazda : public Car
{
public:
	Mazda();
	int getFuelCapacity();
	int getFuelConsumption();
	int getAverageSpeed(Weather thisWeather);
	void print();
};

