#include "Mazda.h"
Mazda::Mazda()
{
	FuelCapacity = 40;
	FuelConsumption = 8;
	AverageSpeedOnRain = 50;
	AverageSpeedOnSnow = 45;
	AverageSpeedOnSunny = 130;
}
int Mazda::getFuelCapacity()
{
	return FuelCapacity;
}
int Mazda::getFuelConsumption()
{
	return FuelConsumption;
}
int Mazda::getAverageSpeed(Weather thisWeather)
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
void Mazda::print()
{
	std::cout << "Mazda ";
}