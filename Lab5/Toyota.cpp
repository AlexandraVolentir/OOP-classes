#include "Toyota.h"
Toyota::Toyota()
{
	FuelCapacity = 20;
	FuelConsumption = 4;
	AverageSpeedOnRain = 70;
	AverageSpeedOnSnow = 30;
	AverageSpeedOnSunny = 120;
}
int Toyota::getFuelCapacity()
{
	return FuelCapacity;
}
int Toyota::getFuelConsumption()
{
	return FuelConsumption;
}
int Toyota::getAverageSpeed(Weather thisWeather)
{
	if (thisWeather == Rain)
	{
		return AverageSpeedOnRain;
	}
	else
		if (thisWeather == Sunny)
		{
			return AverageSpeedOnSunny;
		}
		else
		{
			return AverageSpeedOnSnow;
		}
}
void Toyota::print()
{
	std::cout << "Toyota ";
}
