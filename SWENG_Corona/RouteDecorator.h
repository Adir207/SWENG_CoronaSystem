#ifndef ROUTEDECORATOR_H
#define ROUTEDECORATOR_H
#include"Route.h"
#include<iostream>
class RouteDecorator : public Route
{
public:
	RouteDecorator(Route* decorator);
	virtual void createRoute(Date visitDate, string visitTime, string sitename, string city, string street, int number);
	virtual void ShowRoute();
protected:
	Route* route;
};
#endif