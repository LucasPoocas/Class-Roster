#include "student.h"

//--Constructors--
Student::Student() {
	id = "-1" ;
	firstname = "NoFirstName";
	lastname = "NoLastName";
	email = "NoEmail";
	age = -1;
	for (int i = 0; i < toComplete; i++) days[i] = 0;
	degree = DegreeType::SOFTWARE;
}

Student::Student(string id, string firstname, string lastname, string email, int age, int days[], DegreeType degree) {
	this->id = id;
	this->firstname = firstname;
	this->lastname = lastname;
	this->email = email;
	this->age = age;
	for (int i = 0; i < toComplete; i++)  this->days[i] = days[i];
	this->degree = degree;
}

//--Print Function--
void Student::Print() {
	cout << id << '\t' << "First Name: " << firstname << '\t' <<
		"Last Name: " << lastname << '\t' << "E-Mail: " << email << '\t' << "Age: " << age << '\t';
	cout << "Days in course: " << GetDays()[0] << ", " << GetDays()[1] << ", " << GetDays()[2] << '\t';
	cout << "Student Degree: ";
	if (degree == 0) {
		cout << "Security";
	}
	else if (degree == 1) {
		cout << "Network";
	}
	else if (degree == 2) {
		cout << "Software";
	}
	else {
		cout << "INVALID DEGREE";
	}
	cout << endl;
}


//--Setters--
void Student::SetID(string studentID) {id = studentID;}
void Student::SetFirstName(string studentFirstName) {firstname = studentFirstName;}
void Student::SetLastName(string studentLastName) {lastname = studentLastName;}
void Student::SetEmail(string studentEmail) {email = studentEmail;}
void Student::SetAge(int studentAge) {age = studentAge;}
void Student::SetDays(int days[]) {
	for (int i = 0; i < toComplete; i++) this->days[i] = days[i];
}
void Student::SetDegree(DegreeType studentDegree) {degree = studentDegree;}


//--Getters--
string Student::GetID() {return id;}
string Student::GetFirstName() {return firstname;}
string Student::GetLastName() {return lastname;}
string Student::GetEmail() {return email;}
int Student::GetAge() {return age;}
int* Student::GetDays() {return days;}
DegreeType Student::GetDegree() {return degree;}