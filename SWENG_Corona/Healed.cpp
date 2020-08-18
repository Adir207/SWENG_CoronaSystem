#include"Healed.h"
#include"PersonState.h"
#include"Lab.h"
#include<iostream>
#include<string>
using namespace std;
Healed::Healed(Date* dateToday)
{
	this->healedDate = dateToday;
}
Date* Healed::getHealedDate()
{
	return this->healedDate;
}

void Healed::show()
{
	cout << this->person->getpersonid() << "  " << this->person->getfirstname() << "  " << this->person->getlastname() << "  " << this->person->getbirthdate().d << "/" << this->person->getbirthdate().m << "/" << this->person->getbirthdate().y << "  " << this->person->getphone() << "  " << this->person->getemail() << "  " << this->person->getcity() << "  " << this->person->getstreet() << "  " << this->person->gethousenumber() << "  " << this->person->getapartment() << "  " << this->person->gethouseresidents() << "\n";
}
void Healed::showRoutes()
{
	for (int i = 0; i < (int)this->routes.size(); i++)
	{
		this->routes[i]->showRoute();
	}
}
void Healed::showLabResults()
{
	cout << "** LAB RESULT BEGIN **\n";
	for (int i = 0; i < (int)this->labResults.size(); i++)
	{
		this->labResults[i]->showLabResult();
	}
	cout << "** LAB RESULT END **\n";
}