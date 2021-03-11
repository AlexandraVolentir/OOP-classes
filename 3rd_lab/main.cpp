
#include <iostream>
#include "Math.h"
#include "Canvas.h"

using namespace std;
int main()
{
	cout << Math::Add(50, 80) << endl;
	cout << Math::Add(59, 80, 20) << endl;
	cout << Math::Add(59.5, 80.5) << endl;
	cout << Math::Add(50.5, 80.5, 20.3) << endl;
	cout << Math::Mul(50, 20) << endl;
	cout << Math::Mul(50.4, 20.2) << endl;
	cout << Math::Mul(50.4, 80.2, 50.5) << endl;
	cout << Math::Add(10, 40, 60, 80, 59, 81, 1, 5, 8, 9, 20) << endl;
	cout << Math::Add("60", "80");


	Canvas d(30, 30);
	d.DrawCircle(6, 6, 4, '@');
	d.FillCircle(15, 15, 3, '%');
	d.DrawRect(2, 12, 7, 15, '*');
	d.FillRect(4, 20, 10, 24, '&');
	d.SetPoint(2, 16, 'g');
	d.Print();
	d.Clear();
	d.DrawLine(7, 20, 20, 7, '/');
	d.Print();
	return 0;
}
