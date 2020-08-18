#ifndef PERSONSTATE_H
#define PERSONSTATE_H
#include<string>
#include <vector> 
#include<iostream>
#include"Route.h"
#include"Person.h"
#include"Date.h"
#include"Lab.h"
using namespace std;
class Person;
class PersonState
{
protected:
	vector <Route*> routes;
	vector <Lab*> labResults;
	Person* person;
public:
	virtual void show();
	virtual void showSick();
	virtual void addRouteSite(Date date, string time, string sitename);
	virtual void addRouteAddress(Date date, string time, string sitename, string city, string street, int number);
	virtual void showRoutes();
	virtual void showLabResults();
	void setPerson(Person* person);
	virtual int getEncounterId();
	virtual void addLabResult(int labid, int testid, Date date, string result);
	virtual Date* getQuarantineDate();
	virtual int getSourceId();
	virtual void setSourceId(int);
	vector <Route*> getRoutes();
	vector <Lab*> getLabResults();
	void setRoutes(vector <Route*> routes);
	void setLabResults(vector <Lab*> labResults);
};
#endif