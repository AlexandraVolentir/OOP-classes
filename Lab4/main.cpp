#include <stdlib.h>
#include <time.h>

#include "Sort.h"

int main ()
{
	srand (time (0));

	Sort vector1 (5, 10, 99);
	vector1.print ();
	vector1.bubbleSort (true);
	vector1.print ();

	int vec[] = { -1, 5, -9, 0, 30, 45, 99, 54 };
	Sort vector2 (vec, sizeof (vec) / 4);
	vector2.print ();
	vector2.insertSort ();
	vector2.print ();

	Sort vector3 (5, 10, 99, 11, -12, 3);
	vector3.print ();
	vector3.quickSort (0, vector3.getElementCount () - 1, false);
	vector3.print ();

	Sort vector4 (3, 100, 1);
	vector4.print ();
	vector4.merge (vector1);
	vector4.print ();

	Sort vector5 ("10,30,50,9");
	vector5.print ();
	
	return 0;
}
