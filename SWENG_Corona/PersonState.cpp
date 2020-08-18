#include"PersonState.h"
#include<string>
#include <vector> 
#include<iostream>
#include"Route.h"
#include"Person.h"
#include"Date.h"
#include"Lab.h"
using namespace std;
void PersonState::show() {}
void PersonState::showSick() {}
void PersonState::addRouteSite(Date date, string time, string sitename) {  }
void PersonState::addRouteAddress(Date date, string time, string sitename, string city, string street, int number) {  }
void PersonState::showRoutes() {  }
void PersonState::showLabResults() {  }
void PersonState::setSourceId(int sourceId) {}
int PersonState::getSourceId() { return 0; }
void PersonState::setPerson(Person* person)
{
	this->person = person;
}
int PersonState::getEncounterId() { return 0; }
void PersonState::addLabResult(int labid, int testid, Date date, string result) {}
Date* PersonState::getQuarantineDate() { return nullptr; }
vector <Route*> PersonState::getRoutes()
{
	return this->routes;
}
vector <Lab*> PersonState::getLabResults()
{
	return this->labResults;
}
void PersonState::setRoutes(vector <Route*> routes)
{
	this->routes = routes;
}
void PersonState::setLabResults(vector <Lab*> labResults)
{
	this->labResults = labResults;
}