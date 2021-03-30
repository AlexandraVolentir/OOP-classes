#include "Ford.h"
Ford::Ford()
{
	FuelCapacity = 70;
	FuelConsumption = 5;
	AverageSpeedOnRain = 90;
	AverageSpeedOnSnow = 40;
	AverageSpeedOnSunny = 150;
}
int Ford::getFuelCapacity()
{
	return FuelCapacity;
}
int Ford::getFuelConsumption()
{
	return FuelConsumption;
}
int Ford::getAverageSpeed(Weather thisWeather)
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
void Ford::print()
{
	std::cout << "Ford ";
}