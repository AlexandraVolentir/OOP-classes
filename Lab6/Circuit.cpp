#include "Circuit.h"
void Circuit::AddCar(Car* car1)
{
	Cars[Participants++] = car1;
}
void Circuit::setLength(int length)
{
	Length = length;
}
void Circuit::setWeather(Weather thisWeather)
{
	weather = thisWeather;
}
void Circuit::Race()
{
	for (int i = 0; i < Participants; i++)
	{
		if (Length / Cars[i]->getFuelConsumption() > Cars[i]->getFuelCapacity())
		{
			CarLoser[Losers++] = Cars[i];
		}
		else
		{
			CarWinner[Winners++] = Cars[i];
		}
	}
}
void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < Winners; i++)
	{
		for (int j = i + 1; j < Winners; j++)
		{
			if (Cars[i]->getAverageSpeed(weather) < Cars[j]->getAverageSpeed(weather))
			{
				Car* aux = CarWinner[i];
				CarWinner[i] = CarWinner[j];
				CarWinner[j] = aux;
			}
		}
	}
	std::cout << "Winners: \n";
	for (int i = 0; i < Winners; i++)
	{
		std::cout << i + 1 << "-";
 		CarWinner[i]->print();
		std::cout << (float)Length / CarWinner[i]->getAverageSpeed(weather) << "\n";
	}
}
void Circuit::ShowWhoDidNotFinish()
{
	std::cout << "Losers: \n";
	for (int i = 0; i < Losers; i++)
	{
		std::cout << i+1 << "-";
		CarLoser[i]->print();
		std::cout << "\n";
	}
}