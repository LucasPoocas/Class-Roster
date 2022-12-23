#pragma once
#include "student.h"
#include <array>


class Roster {
public:
	void Parse(string dataRow);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeType degree);
	~Roster();

public:
	int lastIndex = -1;
	const static int rosterLength = 5;
	Student* classRosterArray[rosterLength];
};