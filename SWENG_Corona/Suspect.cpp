#include"PersonState.h"
#include"Suspect.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
Suspect::Suspect(int encounter_id, int sickId, string sickfName, string sickLName)
{
	this->encounter_id = encounter_id;
	this->sick_id = sickId;
	this->sick_firstName = sickfName;
	this->sick_lastName = sickLName;
}
int Suspect::getEncounterId()
{
	return this->encounter_id;
}
void Suspect::show()
{
	cout << left << setw(4) << encounter_id;
	cout << left << setw(11) << sick_id;
	cout << left << setw(10) << sick_firstName;
	cout << left << setw(10) << sick_lastName;
	cout << left << setw(10) << this->person->getfirstname();
	cout << left << setw(10) << this->person->getlastname();
	cout << left << setw(14) << this->person->getphone() << endl;
}
int Suspect::getSourceId()
{
	return this->sick_id;
}