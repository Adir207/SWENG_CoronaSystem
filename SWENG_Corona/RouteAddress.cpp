#include"RouteDecorator.h"
#include"RouteAddress.h"
#include<iomanip>
#include<string>
using namespace std;
RouteAddress::RouteAddress(Route* route, string city, string street, int number) :RouteDecorator(route)
{
	this->city = city;
	this->street = street;
	this->number = number;
}
void RouteAddress::createRoute(Date visitDate, string visitTime, string sitename, string city, string street, int number)
{
	route->createRoute(visitDate, visitTime, sitename, "", "", 0);
	this->number = number;
	this->street = street;
	this->city = city;
}
void RouteAddress::showRoute()
{
	string date = to_string(this->route->getVisitDate().d) + "/" + to_string(this->route->getVisitDate().m) + "/" + to_string(this->route->getVisitDate().y);
	cout << left << setw(11) << date;
	cout << left << setw(7) << this->route->getVisitTime();
	cout << left << setw(12) << this->route->getSitename();
	cout << left << setw(12) << this->city;
	cout << left << setw(10) << this->street;
	cout << left << setw(5) << this->number << endl;
}