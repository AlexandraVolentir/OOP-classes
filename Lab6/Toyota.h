#pragma once
#include "Car.h"
class Toyota : public Car
{
public:
	Toyota();
	int getFuelCapacity();
	int getFuelConsumption();
	int getAverageSpeed(Weather thisWeather);
	void print();
};

