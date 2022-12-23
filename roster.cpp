#include "roster.h"

//Destructor
Roster::~Roster()
{
    cout << "Calling Destructor" << endl << endl;
    for (int i = 0; i < rosterLength; i++)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

void Roster::Parse(string dataRow) {

    int rhs = dataRow.find(',');
    string sID = dataRow.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = dataRow.find(',', lhs);
    string sFName = dataRow.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = dataRow.find(',', lhs);
    string sLName = dataRow.substr(lhs, rhs - lhs);

    lhs = rhs + 1; 
    rhs = dataRow.find(",", lhs);
    string sEmail = dataRow.substr(lhs, rhs - lhs);

    lhs = rhs + 1; 
    rhs = dataRow.find(",", lhs);
    int sAge = stoi(dataRow.substr(lhs, rhs - lhs));

    lhs = rhs + 1; 
    rhs = dataRow.find(",", lhs);
    int daysInCourse1 = stod(dataRow.substr(lhs, rhs - lhs));

    lhs = rhs + 1; 
    rhs = dataRow.find(",", lhs);
    int daysInCourse2 = stod(dataRow.substr(lhs, rhs - lhs));

    lhs = rhs + 1; 
    rhs = dataRow.find(",", lhs);
    int daysInCourse3 = stod(dataRow.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = dataRow.find(",", lhs);

    DegreeType degreeprogram = SECURITY;

    if (dataRow.at(lhs) == 'S' && dataRow.at(lhs + 1) == 'E') degreeprogram = SECURITY;
    else if (dataRow.at(lhs) == 'S' && dataRow.at(lhs + 1) == 'O') degreeprogram = SOFTWARE;
    else if (dataRow.at(lhs) == 'N') degreeprogram = NETWORK;

    add(sID, sFName, sLName, sEmail, sAge, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeprogram) {
    int dayArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, dayArray, degreeprogram);
}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->GetID() == studentID) {
            found = true;
            if (i < rosterLength - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[rosterLength - 1];
                classRosterArray[rosterLength - 1] = temp;
            }
            lastIndex--;
        }
    }
    if (!found) {
        cout << "No student with the entered ID found." << endl;
    }
    else if (found) {
        cout << studentID << " removed from roster." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->Print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    int daysSum = 0;
    int daysAverage = 0;
    for (int i = 0; i < rosterLength; i++) {
        if (classRosterArray[i]->GetID() == studentID) {
            daysSum += classRosterArray[i]->GetDays()[0];
            daysSum += classRosterArray[i]->GetDays()[1];
            daysSum += classRosterArray[i]->GetDays()[2];
            daysAverage = daysSum / 3;
            cout << "The average days for student " << studentID << " to complete a course is: " << daysAverage << endl;
        }
    }
}

void Roster::printInvalidEmails() {

    bool anyInvalids = false;
    cout << "Printing Invalid E-mails..." << endl;

    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i]->GetEmail();
        if (email.find("@") == string::npos || email.find(" ") != string::npos || email.find(".") == string::npos) {

            anyInvalids = true;

            cout << classRosterArray[i]->GetEmail() << endl;

        }
    }
    if (!anyInvalids) {
        cout << "No invalid E-mails.";
    }

}

void Roster::printByDegreeProgram(DegreeType degree) {
    string currDegree;
    if (degree == 0) {
        currDegree = "Security";
    }
    else if (degree == 1) {
        currDegree = "Network";
    }
    else if (degree == 2) {
        currDegree = "Software";
    }

    cout << "Printing all " << currDegree << " students..." << endl;

    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->GetDegree() == degree) classRosterArray[i]->Print();
    }
    cout << endl;

}