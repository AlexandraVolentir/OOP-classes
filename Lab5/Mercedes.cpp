#include "Mercedes.h"
Mercedes::Mercedes()
{
	FuelCapacity = 40;
	FuelConsumption = 7;
	AverageSpeedOnRain = 80;
	AverageSpeedOnSnow = 50;
	AverageSpeedOnSunny = 180;
}
int Mercedes::getFuelCapacity()
{
	return FuelCapacity;
}
int Mercedes::getFuelConsumption()
{
	return FuelConsumption;
}
int Mercedes::getAverageSpeed(Weather thisWeather)
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
void Mercedes::print()
{
	std::cout << "Mercedes ";
}