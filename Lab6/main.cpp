#include <iostream>
#include "Car.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mercedes.h"
#include "Mazda.h"
#include "Toyota.h"
#include "Circuit.h"

int main()
{

	Circuit c;

	c.setLength(100);

	c.setWeather(Weather::Rain);

	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());

	c.Race();

	c.ShowFinalRanks();

	c.ShowWhoDidNotFinish();

	return 0;
}