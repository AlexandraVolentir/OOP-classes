#pragma once
#include "Car.h"
class Mercedes : public Car
{
public:
	Mercedes();
	int getFuelCapacity();
	int getFuelConsumption();
	int getAverageSpeed(Weather thisWeather);
	void print();
};

