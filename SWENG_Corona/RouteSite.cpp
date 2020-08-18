#include"Date.h"
#include"Route.h"
#include"RouteSite.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
RouteSite::RouteSite()
{
	this->visitDate.d = 0;
	this->visitDate.m = 0;
	this->visitDate.y = 0;
	this->visitTime = "";
	this->sitename = "";
}
void RouteSite::createRoute(Date visitDate, string visitTime, string sitename, string city, string street, int number)
{
	this->visitDate.d = visitDate.d;
	this->visitDate.m = visitDate.m;
	this->visitDate.y = visitDate.y;
	this->visitTime = visitTime;
	this->sitename = sitename;
}
void RouteSite::showRoute()
{
	string date = to_string(this->visitDate.d) + "/" + to_string(this->visitDate.m) + "/" + to_string(this->visitDate.y);
	cout << left << setw(11) << date;
	cout << left << setw(7) << this->visitTime;
	cout << left << setw(12) << this->sitename << endl;
}
