#ifndef ROUTE_H
#define ROUTE_H
#include"Date.h"
#include<string>
using namespace std;
class Route
{
protected:
	Date visitDate;
	string visitTime;
	string sitename;
public:
	virtual ~Route() {}
	virtual void createRoute(Date visitDate, string visitTime, string sitename, string city = "", string street = "", int number = 0) = 0;
	void setVisitDate(Date visitDate);
	void setVisitTime(string visitTime);
	void setSitename(string sitename);
	Date getVisitDate();
	string getVisitTime();
	string getSitename();
	virtual void showRoute() = 0;
};
#endif