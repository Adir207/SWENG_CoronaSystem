#ifndef QUARANTINEDSUSPECT_H
#define QUARANTINEDSUSPECT_H
#include"PersonState.h"
#include"Lab.h"
#include<iostream>
#include<string>
using namespace std;
class QuarantinedSuspect : public PersonState
{
	Date* quarantineDate;
	int encounter_id;
	int sourceId;

public:
	QuarantinedSuspect(Date* dateToday, int encounterId, int sourceId);
	virtual Date* getQuarantineDate();
	virtual int getEncounterId();
	virtual void show();
	virtual void addLabResult(int labid, int testid, Date date, string result);
	virtual void showRoutes();
	virtual void showLabResults();
	virtual void addRouteSite(Date date, string time, string sitename);
	virtual void addRouteAddress(Date date, string time, string sitename, string city, string street, int number);
	virtual void setSourceId(int sourceId);
	virtual int getSourceId();
};
#endif