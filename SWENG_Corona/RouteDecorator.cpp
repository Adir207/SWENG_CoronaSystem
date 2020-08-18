#include"RouteDecorator.h"
#include"Route.h"
#include<iostream>
using namespace std;
RouteDecorator::RouteDecorator(Route* decorator) : route(decorator)
{

}
void RouteDecorator::createRoute(Date visitDate, string visitTime, string sitename, string city, string street, int number)
{
	route->createRoute(visitDate, visitTime, sitename);
}
void RouteDecorator::ShowRoute()
{
	route->showRoute();
}