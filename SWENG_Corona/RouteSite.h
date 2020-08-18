#ifndef ROUTESITE_H
#define ROUTESITE_H
#include"Date.h"
#include"Route.h"
#include<string>
using namespace std;
class RouteSite : public Route
{
public:
	RouteSite();
	virtual void createRoute(Date visitDate, string visitTime, string sitename, string city, string street, int number);
	virtual void showRoute();
};
#endif