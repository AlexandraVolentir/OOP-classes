#pragma once
#include "WeatherEnum.h"
#include <iostream>
class Car
{
protected:
	int FuelCapacity = 0;
	int FuelConsumption = 0;
	int AverageSpeedOnRain = 0;
	int AverageSpeedOnSunny = 0;
	int AverageSpeedOnSnow = 0;
public:
	virtual void print() = 0;
	virtual int getFuelCapacity() = 0;
	virtual int getFuelConsumption() = 0;
	virtual int getAverageSpeed(Weather thisWeather) = 0;
};
