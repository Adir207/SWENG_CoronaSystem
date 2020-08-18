#include"PersonState.h"
#include"Lab.h"
#include<iostream>
#include<string>
#include"RouteAddress.h"
#include"RouteSite.h"
#include"QuarantinedSuspects.h"
using namespace std;
QuarantinedSuspect::QuarantinedSuspect(Date* dateToday, int encounterId, int sourceId)
{
	this->quarantineDate = dateToday;
	this->encounter_id = encounterId;
	this->sourceId = sourceId;
}
Date* QuarantinedSuspect::getQuarantineDate()
{
	return this->quarantineDate;
}
int QuarantinedSuspect::getEncounterId()
{
	return this->encounter_id;
}
void QuarantinedSuspect::show()
{
	cout << this->person->getpersonid() << "  " << this->person->getfirstname() << "  " << this->person->getlastname() << "  " << this->person->getbirthdate().d << "/" << this->person->getbirthdate().m << "/" << this->person->getbirthdate().y << "  " << this->person->getphone() << "  " << this->person->getemail() << "  " << this->person->getcity() << "  " << this->person->getstreet() << "  " << this->person->gethousenumber() << "  " << this->person->getapartment() << "  " << this->person->gethouseresidents() << "\n";
}
void QuarantinedSuspect::addLabResult(int labid, int testid, Date date, string result)
{
	for (int i = 0; i < (int)this->labResults.size(); i++)
	{
		if (this->labResults[i]->getlabid() == labid && this->labResults[i]->gettestid() == testid)
		{
			this->labResults[i]->setdate(date);
			this->labResults[i]->setresult(result);
			return;
		}
	}
	if (labResults.empty())
		this->labResults.insert(this->labResults.begin(), new Lab(labid, testid, date, result));
	else
		this->labResults.insert(this->labResults.end(), new Lab(labid, testid, date, result));
}
void QuarantinedSuspect::showRoutes()
{
	for (int i = 0; i < (int)this->routes.size(); i++)
	{
		this->routes[i]->showRoute();
	}
}
void QuarantinedSuspect::addRouteSite(Date date, string time, string sitename)
{
	Route* route = new RouteSite();
	route->createRoute(date, time, sitename);
	this->routes.insert(this->routes.begin(), route);
}
void QuarantinedSuspect::addRouteAddress(Date date, string time, string sitename, string city, string street, int number)
{
	Route* route = new RouteSite();
	route->createRoute(date, time, sitename);
	Route* routeAddress = new RouteAddress(route, city, street, number);
	this->routes.insert(this->routes.begin(), routeAddress);
}
void QuarantinedSuspect::showLabResults()
{
	cout << "** LAB RESULT BEGIN **\n";
	for (int i = 0; i < (int)this->labResults.size(); i++)
	{
		this->labResults[i]->showLabResult();
	}
	cout << "** LAB RESULT END **\n";
}
void QuarantinedSuspect::setSourceId(int sourceId)
{
	this->sourceId = sourceId;
}
int QuarantinedSuspect::getSourceId()
{
	return this->sourceId;
}