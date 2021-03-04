#include "Student.h"
#include "global.h"
#include <iostream>
#include <string>

//constructors
Student::Student(char* name, float math, float en, float his)
{
	setNameStudent(name);
	setMathGrade(math);
	setEnGrade(en);
	setHistoryGrade(his);
}

//Mutators
void Student::setNameStudent(char* name)
{
	this->name = name;
}
void Student::setMathGrade(float grade)
{
	if (grade >= 1 && grade <= 10)
	{
		mathGrade = grade;
	}
	else mathGrade = 1;
}
void Student::setEnGrade(float grade)
{
	if (grade >= 1 && grade <= 10)
	{
		enGrade = grade;
	}
	else enGrade = 1;
}
void Student::setHistoryGrade(float grade)
{
	if (grade >= 1 && grade <= 10)
	{
		historyGrade = grade;
	}
	else historyGrade = 1;

}

//Accessors
char* Student::getNameStudent()
{
	return name;
}
float Student::getMathGrade()
{
	return mathGrade;
}
float Student::getEnGrade()
{
	return enGrade;
}
float Student::getHistoryGrade()
{
	return historyGrade;
}

//Facilitators
float Student::avgGrade()
{
	return (mathGrade + enGrade + historyGrade) / 3;
}

