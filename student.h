#pragma once
#include <string>
#include <array>
#include <iostream>
#include "degree.h"
using namespace std;

class Student {

public:
	//used to create array variable further down
	const static int toComplete = 3;
public:
	Student();
	Student(string id, string firstname, string lastname, string email, int age, int days[], DegreeType degree);
	void Print();

	void SetID(string studentID);
	void SetFirstName(string studentFirstName);
	void SetLastName(string studentLastName);
	void SetEmail(string studentEmail);
	void SetAge(int studentAge);
	void SetDays(int days[]);
	void SetDegree(DegreeType studentDegree);

	string GetID();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDays();
	DegreeType GetDegree();


private:
	string id;
	string firstname;
	string lastname;
	string email;
	int age;
	int days[toComplete];
	DegreeType degree;
};