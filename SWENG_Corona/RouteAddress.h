#ifndef ROUTEADDRESS_H
#define ROUTEADDRESS_H
#include"RouteDecorator.h"
#include<string>
using namespace std;
class RouteAddress :public RouteDecorator
{
	string city, street;
	int number;

public:
	RouteAddress(Route* route, string city, string street, int number);
	virtual void createRoute(Date visitDate, string visitTime, string sitename, string city, string street, int number);
	virtual void showRoute();
};
#endif