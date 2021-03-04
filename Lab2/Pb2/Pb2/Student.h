#pragma once
#include "global.h"
class Student
{
	char* name;
	float mathGrade;
	float enGrade;
	float historyGrade;

public:
	//constructors
	Student(char* name, float mathGrade, float enGrade, float historyGrade);

	//Mutators
	void setNameStudent(char* name);
	void setMathGrade(float grade);
	void setEnGrade(float grade);
	void setHistoryGrade(float grade);

	//Accessors
	char* getNameStudent();
	float getMathGrade();
	float getEnGrade();
	float getHistoryGrade();

	//Facilitators
	float avgGrade();
};

