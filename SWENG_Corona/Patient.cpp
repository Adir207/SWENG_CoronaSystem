#include"Patient.h"
#include <iomanip>
using namespace std;
void Patient::show()
{
	cout << left << setw(11) << this->person->getpersonid();
	cout << left << setw(10) << this->person->getfirstname();
	cout << left << setw(10) << this->person->getlastname();
	string date = to_string(this->person->getbirthdate().d) + "/" + to_string(this->person->getbirthdate().m) + "/" + to_string(this->person->getbirthdate().y);
	cout << left << setw(11) << date;
	cout << left << setw(13) << this->person->getphone();
	cout << left << setw(18) << this->person->getemail();
	cout << left << setw(11) << this->person->getcity();
	cout << left << setw(11) << this->person->getstreet();
	cout << left << setw(3) << this->person->gethousenumber();
	cout << left << setw(3) << this->person->getapartment();
	cout << left << setw(3) << this->person->gethouseresidents() << endl;
}
void Patient::showSick()
{
	cout << left << setw(11) << this->person->getpersonid();
	cout << left << setw(10) << this->person->getfirstname();
	cout << left << setw(10) << this->person->getlastname();
	string date = to_string(this->person->getbirthdate().d) + "/" + to_string(this->person->getbirthdate().m) + "/" + to_string(this->person->getbirthdate().y);
	cout << left << setw(11) << date;
	cout << left << setw(13) << this->person->getphone();
	cout << left << setw(18) << this->person->getemail();
	cout << left << setw(11) << this->person->getcity();
	cout << left << setw(11) << this->person->getstreet();
	cout << left << setw(3) << this->person->gethousenumber();
	cout << left << setw(3) << this->person->getapartment();
	cout << left << setw(3) << this->person->gethouseresidents();
	cout << left << setw(12) << this->sourceId << "\n";
}
void Patient::addRouteSite(Date date, string time, string sitename)
{
	Route* route = new RouteSite();
	route->createRoute(date, time, sitename);
	this->routes.insert(this->routes.begin(), route);
}
void Patient::addRouteAddress(Date date, string time, string sitename, string city, string street, int number)
{
	Route* route = new RouteSite();
	route->createRoute(date, time, sitename);
	Route* routeAddress = new RouteAddress(route, city, street, number);
	this->routes.insert(this->routes.begin(), routeAddress);
}
void Patient::showRoutes()
{
	for (int i = 0; i < (int)this->routes.size(); i++)
	{
		this->routes[i]->showRoute();
	}
}
void Patient::addLabResult(int labid, int testid, Date date, string result)
{
	for (int i = 0; i < (int)this->labResults.size(); i++)
	{
		if (this->labResults[i]->getlabid() == labid && this->labResults[i]->gettestid() == testid)
		{
			this->labResults[i]->setdate(date);
			this->labResults[i]->setresult(result);
			return;
		}
	}
	if (labResults.empty())
		this->labResults.insert(this->labResults.begin(), new Lab(labid, testid, date, result));
	else
		this->labResults.insert(this->labResults.end(), new Lab(labid, testid, date, result));
}

void Patient::showLabResults()
{
	cout << "** LAB RESULT BEGIN **\n";
	for (int i = 0; i < (int)this->labResults.size(); i++)
	{
		this->labResults[i]->showLabResult();
	}
	cout << "** LAB RESULT END **\n";
}
void Patient::setSourceId(int sourceId)
{
	this->sourceId = sourceId;
}