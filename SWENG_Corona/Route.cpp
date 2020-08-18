#include"Route.h"
#include"Date.h"
#include<string>
#include<iostream>
using namespace std;
void Route::setVisitDate(Date visitDate)
{
	this->visitDate.d = visitDate.d;
	this->visitDate.m = visitDate.m;
	this->visitDate.y = visitDate.y;
}
void Route::setVisitTime(string visitTime)
{
	this->visitTime = visitTime;
}
void Route::setSitename(string sitename)
{
	this->sitename = sitename;
}
Date Route::getVisitDate()
{
	return this->visitDate;
}
string Route::getVisitTime()
{
	return this->visitTime;
}
string Route::getSitename()
{
	return this->sitename;
}
