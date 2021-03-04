#include <iostream>
#include "Student.h"
#include "global.h"

using namespace std;
int main()
{
	Student s1((char*)"Alexandra", 10, 9, 8);
	Student s2((char*)"Victor", 5, 10, 3);
	
	cout << "Avg mark of 1st student: " << s1.avgGrade() << endl;
	cout << "Avg mark of 2nd student: " << s2.avgGrade() << endl;

}