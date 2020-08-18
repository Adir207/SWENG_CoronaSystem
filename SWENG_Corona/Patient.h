#ifndef PATIENT_H
#define PATIENT_H
#include"PersonState.h"
#include"RouteSite.h"
#include"RouteAddress.h"
#include"Route.h"
#include<iostream>
#include<string>
using namespace std;
class Patient : public PersonState
{
	bool isHealed;
	int sourceId;

public:
	virtual void show();
	virtual void showSick();
	virtual void addRouteSite(Date date, string time, string sitename);
	virtual void addRouteAddress(Date date, string time, string sitename, string city, string street, int number);
	virtual void showRoutes();
	virtual void addLabResult(int labid, int testid, Date date, string result);
	virtual void showLabResults();
	virtual void setSourceId(int sourceId);
};
#endif