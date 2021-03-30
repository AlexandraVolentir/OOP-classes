#include "Dacia.h"
Dacia::Dacia()
{
	FuelCapacity = 30;
	FuelConsumption = 2;
	AverageSpeedOnRain = 60;
	AverageSpeedOnSnow = 50;
	AverageSpeedOnSunny = 100;
}
int Dacia::getFuelCapacity()
{
	return FuelCapacity;
}
int Dacia::getFuelConsumption()
{
	return FuelConsumption;
}
int Dacia::getAverageSpeed(Weather thisWeather)
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
void Dacia::print()
{
	std::cout << "Dacia ";
}
