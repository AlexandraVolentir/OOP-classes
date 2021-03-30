#pragma once
#include "Car.h"
class Circuit
{
	int Participants = 0;
	Car* Cars[200];
	int Length;
	Weather weather;
	int Losers = 0;
	int Winners = 0;
	Car* CarLoser[200];
	Car* CarWinner[200];
public:
	void AddCar(Car* car1);
	void setLength(int length);
	void Race();
	void setWeather(Weather thisweather);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

