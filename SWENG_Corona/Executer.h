#ifndef EXECUTER_H
#define EXECUTER_H
#include"Date.h"
#include"Person.h"
#include<string>
using namespace std;
class Executer
{
private:
	vector <Person*> patients;
	vector <Person*> suspects;
	vector <Person*> qurantinedSuspects;
	vector <Person*> healed;
	int encounterid;
	int newPatients;
	static Executer* instance;
	Executer();
	void addPatient(int id, string fname, string lname, Date birthdate, string phone, string mail, string city, string street, int hn, int ap, int hr);
	void addRouteSite(int id, Date date, string time, string sitename);
	void addRouteAddr(int id, Date date, string time, string sitename, string city, string street, int number);
	void addSickEncounter(int id, string firstname, string lastName, string phone);
	void showSickEncounter();
	void updateSickEncounter(int encounterid, int id, string fname, string lname, Date birthdate, string phone, string mail, string city, string street, int housenumber, int apartment, int houseresident);
	void showpersonRoute(int id);
	void updateLabResult(int labid, int testid, int id, Date date, string result);
	void showQuarantine();
	void showNewSicks();
	void showSicks();
	void showPerson(int id);
	void showStat(string option);
public:
	static Executer* getInstance();
	void parseInputFile(string filename);

};
#endif