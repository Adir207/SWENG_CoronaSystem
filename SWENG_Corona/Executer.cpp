#define _CRT_SECURE_NO_WARNINGS
#include"Executer.h"
#include<string>
#include<fstream>
#include <time.h>
#include<cmath>
#include <iomanip> 
#include<ctime>
#include <vector>
#include"Person.h"
#include"PersonState.h"
#include"RouteSite.h"
#include"RouteDecorator.h"
#include"RouteAddress.h"
#include"Date.h"
#include"Route.h"
#include"PersonState.h"
#include"Patient.h"
#include"Suspect.h"
#include"QuarantinedSuspects.h"
#include"Healed.h"
Executer* Executer::instance = 0;
Executer::Executer()
{
	encounterid = 1;
	newPatients = 0;
}
Executer* Executer::getInstance()
{
	if (instance == 0)
	{
		instance = new Executer();
	}

	return instance;
}
void Executer::addPatient(int id, string fname, string lname, Date birthdate, string phone, string mail, string city, string street, int hn, int ap, int hr)
{
	for (int i = 0; i < (int)patients.size(); i++)
	{
		if (patients[i]->getpersonid() == id)
		{
			patients[i]->setfirstname(fname);
			patients[i]->setlastname(lname);
			patients[i]->setbirthdate(birthdate);
			patients[i]->setphone(phone);
			patients[i]->setemail(mail);
			patients[i]->setcity(city);
			patients[i]->setstreet(street);
			patients[i]->sethousenumber(hn);
			patients[i]->sethouseresidents(hr);
			patients[i]->setapartment(ap);
			return;
		}
	}
	PersonState* state = new Patient();
	state->setSourceId(0);
	if (patients.empty())
	{
		patients.insert(patients.begin(), new Person(id, fname, lname, birthdate, phone, mail, city, street, hn, ap, hr, state));
	}
	else
	{
		patients.insert(patients.end(), new Person(id, fname, lname, birthdate, phone, mail, city, street, hn, ap, hr, state));
	}
}
void Executer::addRouteSite(int id, Date date, string time, string sitename)
{
	for (int i = 0; i < (int)patients.size(); i++)
	{
		if (patients[i]->getpersonid() == id)
		{
			patients[i]->getState()->addRouteSite(date, time, sitename);
			return;
		}
	}
}
void Executer::addRouteAddr(int id, Date date, string time, string sitename, string city, string street, int number)
{
	for (int i = 0; i < (int)patients.size(); i++)
	{
		if (patients[i]->getpersonid() == id)
		{
			patients[i]->getState()->addRouteAddress(date, time, sitename, city, street, number);
			return;
		}
	}
}
void Executer::addSickEncounter(int id, string firstname, string lastName, string phone)
{
	for (int i = 0; i < (int)patients.size(); i++)
	{
		if (patients[i]->getpersonid() == id)
		{
			suspects.insert(suspects.begin(), new Person(encounterid, firstname, lastName, phone, new Suspect(encounterid, id, patients[i]->getfirstname(), patients[i]->getlastname())));
			encounterid++;
			return;
		}
	}
}
void Executer::showSickEncounter()
{
	for (int i = (int)suspects.size() - 1; i >= 0; i--)
	{
		suspects[i]->getState()->show();
	}
}
void Executer::updateSickEncounter(int encounterid, int id, string fname, string lname, Date birthdate, string phone, string mail, string city, string street, int hn, int ap, int hr)
{
	for (int i = 0; i < (int)qurantinedSuspects.size(); i++)
	{
		if (qurantinedSuspects[i]->getState()->getEncounterId() == encounterid)
		{
			qurantinedSuspects[i]->setpersonid(id);
			qurantinedSuspects[i]->setfirstname(fname);
			qurantinedSuspects[i]->setlastname(lname);
			qurantinedSuspects[i]->setbirthdate(birthdate);
			qurantinedSuspects[i]->setphone(phone);
			qurantinedSuspects[i]->setemail(mail);
			qurantinedSuspects[i]->setcity(city);
			qurantinedSuspects[i]->setstreet(street);
			qurantinedSuspects[i]->sethousenumber(hn);
			qurantinedSuspects[i]->sethouseresidents(hr);
			qurantinedSuspects[i]->setapartment(ap);
			return;
		}
	}
	for (int i = 0; i < (int)suspects.size(); i++)
	{
		if (suspects[i]->getState()->getEncounterId() == encounterid)
		{
			time_t now = time(0);
			tm* ltm = localtime(&now);
			Date* today = new Date(ltm->tm_mday, ltm->tm_mon, ltm->tm_year);
			suspects[i]->TransitionTo(new QuarantinedSuspect(today, encounterid, suspects[i]->getState()->getSourceId()));
			suspects[i]->setpersonid(id);
			suspects[i]->setfirstname(fname);
			suspects[i]->setlastname(lname);
			suspects[i]->setbirthdate(birthdate);
			suspects[i]->setphone(phone);
			suspects[i]->setemail(mail);
			suspects[i]->setcity(city);
			suspects[i]->setstreet(street);
			suspects[i]->sethousenumber(hn);
			suspects[i]->sethouseresidents(hr);
			suspects[i]->setapartment(ap);
			suspects[i]->setpersonid(id);
			time_t now2 = time(0);
			tm* ltm2 = localtime(&now);

			Date* today2 = new Date(ltm2->tm_mday, ltm2->tm_mon, ltm2->tm_year);
			suspects[i]->TransitionTo(new QuarantinedSuspect(today, encounterid, suspects[i]->getState()->getSourceId()));
			qurantinedSuspects.insert(qurantinedSuspects.begin(), suspects[i]);
			suspects.erase(suspects.begin() + i);
			return;
		}
	}
}
void Executer::showpersonRoute(int id)
{
	for (int i = 0; i < (int)patients.size(); i++)
	{
		if (patients[i]->getpersonid() == id)
		{
			patients[i]->getState()->showRoutes();
			return;
		}
	}
	for (int i = 0; i < (int)qurantinedSuspects.size(); i++)
	{
		if (qurantinedSuspects[i]->getpersonid() == id)
		{
			qurantinedSuspects[i]->getState()->showRoutes();
			return;
		}
	}
	for (int i = 0; i < (int)healed.size(); i++)
	{
		if (healed[i]->getpersonid() == id)
		{
			healed[i]->getState()->showRoutes();
			return;
		}
	}
}
void Executer::updateLabResult(int labid, int testid, int id, Date date, string result)
{
	for (int i = 0; i < (int)patients.size(); i++)
	{
		if (patients[i]->getpersonid() == id)
		{
			patients[i]->getState()->addLabResult(labid, testid, date, result);
			if (result == "negative")
			{
				PersonState* newState = new Healed(new Date(0, 0, 0));
				newState->setLabResults(patients[i]->getState()->getLabResults());
				newState->setRoutes(patients[i]->getState()->getRoutes());

				patients[i]->TransitionTo(newState);
				healed.insert(healed.begin(), patients[i]);
				patients.erase(patients.begin() + i);

			}
			return;
		}
	}
	for (int i = 0; i < (int)qurantinedSuspects.size(); i++)
	{
		if (qurantinedSuspects[i]->getpersonid() == id)
		{
			qurantinedSuspects[i]->getState()->addLabResult(labid, testid, date, result);
			if (result == "positive")
			{
				PersonState* newState = new Patient();
				newState->setSourceId(qurantinedSuspects[i]->getState()->getSourceId());
				newState->setLabResults(qurantinedSuspects[i]->getState()->getLabResults());
				newState->setRoutes(qurantinedSuspects[i]->getState()->getRoutes());

				qurantinedSuspects[i]->TransitionTo(newState);
				patients.insert(patients.begin(), qurantinedSuspects[i]);
				qurantinedSuspects.erase(qurantinedSuspects.begin() + i);

			}
			return;
		}
	}
}
void Executer::showQuarantine()
{
	for (int i = 0; i < (int)qurantinedSuspects.size(); i++)
	{
		qurantinedSuspects[i]->getState()->show();
	}
}
void Executer::showNewSicks()
{
	for (int i = newPatients; i < (int)patients.size(); i++)
	{
		patients[i]->getState()->show();
	}
	if ((int)patients.size() != 0)
	{
		newPatients = (int)patients.size();
	}
}
void Executer::showSicks()
{
	for (int i = 0; i < (int)patients.size(); i++)
	{
		patients[i]->getState()->showSick();
	}
}
void Executer::showPerson(int id)
{
	for (int i = 0; i < (int)patients.size(); i++)
	{
		if (patients[i]->getpersonid() == id)
		{
			patients[i]->getState()->show();
			patients[i]->getState()->showLabResults();
			return;
		}
	}
	for (int i = 0; i < (int)qurantinedSuspects.size(); i++)
	{
		if (qurantinedSuspects[i]->getpersonid() == id)
		{
			qurantinedSuspects[i]->getState()->show();
			qurantinedSuspects[i]->getState()->showLabResults();
			return;
		}
	}
	for (int i = 0; i < (int)healed.size(); i++)
	{
		if (healed[i]->getpersonid() == id)
		{
			healed[i]->getState()->show();
			healed[i]->getState()->showLabResults();
			return;
		}
	}
	cout << "ERROR: No person found with Person ID: " << id << endl;
}
void Executer::showStat(string option)
{
	if (option == " sicks")
	{
		cout << "** BEGIN Sicks ** \n";
		cout << "Total Sicks: " << patients.size() << endl;
		cout << "** END Sicks **\n";
	}
	if (option == "healed")
	{
		cout << "** BEGIN Healed ** \n";
		cout << "Total Healed: " << healed.size() << endl;
		cout << "** END Healed **\n";
	}
	if (option == "isolated")
	{
		cout << "** BEGIN isolated ** \n";
		cout << "Total Isolated: " << qurantinedSuspects.size() << endl;
		cout << "** END isolated **\n";
	}
	if (option == "sick-per-city")
	{

		cout << "** BEGIN sick-per-city ** \n";
		for (int i = 0; i < (int)patients.size(); i++)
		{
			int j;
			for (j = 0; j < i; j++)
				if (patients[i]->getcity() == patients[j]->getcity())
					break;
			if (i == j)
			{
				int cityCount = 0;
				for (int k = 0; k < (int)patients.size(); k++)
				{
					if (patients[k]->getcity() == patients[i]->getcity())
					{
						cityCount++;
					}

				}
				float Percentage = (float)(((float)cityCount / (float)patients.size()) * 100);
				cout << setprecision(4);
				cout << patients[i]->getcity() << ": " << ((Percentage)) << " %" << endl;
			}

		}
		cout << "** END sick-per-city **\n";
	}
}
void Executer::parseInputFile(string filename)
{
	ifstream fin;
	fin.open(filename);
	string line;
	while (!fin.eof())
	{
		string command;
		fin >> command;
		if (command == "Create-sick")
		{
			int id = -1;
			fin >> id;
			string firstname = "";
			fin >> firstname;
			string lastname = "";
			fin >> lastname;
			string birthdate = "";
			fin >> birthdate;
			string phone = "";
			fin >> phone;
			string mail = "";
			fin >> mail;
			string city = "";
			fin >> city;
			string street = "";
			fin >> street;
			int housenumber = -1;
			fin >> housenumber;
			int apartment = -1;
			fin >> apartment;
			int houseresidents = -1;
			fin >> houseresidents;
			int day = 0, month = 0, year = 0;
			string delimiter = "/";
			size_t pos = 0;
			pos = birthdate.find(delimiter);
			string dayStr = birthdate.substr(0, pos);
			birthdate.erase(0, pos + delimiter.length());
			pos = birthdate.find(delimiter);
			string monthStr = birthdate.substr(0, pos);
			birthdate.erase(0, pos + delimiter.length());
			string yearStr = birthdate;
			if (dayStr != "" && monthStr != "" && yearStr != "")
			{
				day = stoi(dayStr);
				month = stoi(monthStr);
				year = stoi(yearStr);
			}

			if (id != -1 && firstname != "" && lastname != "" && day >= 1 && day <= 31 && month >= 1 && month < 13 && year != 0 && phone != "" && mail != "" && city != "" && street != "" && housenumber != -1 && apartment != -1 && houseresidents != -1)
				this->addPatient(id, firstname, lastname, Date(day, month, year), phone, mail, city, street, housenumber, apartment, houseresidents);
			else
				cout << "ERROR: Command failed due to invalid paramenters\n";
		}
		if (command == "Add-route-site")
		{
			int id = -1;
			fin >> id;
			string date;
			fin >> date;
			string time = "";
			fin >> time;
			string sitename = "";
			fin >> sitename;
			int day = 0, month = 0, year = 0;
			string delimiter = "/";
			size_t pos = 0;
			pos = date.find(delimiter);
			string dayStr = date.substr(0, pos);
			date.erase(0, pos + delimiter.length());
			pos = date.find(delimiter);
			string monthStr = date.substr(0, pos);
			date.erase(0, pos + delimiter.length());
			string yearStr = date;
			if (dayStr != "" && monthStr != "" && yearStr != "")
			{
				day = stoi(dayStr);
				month = stoi(monthStr);
				year = stoi(yearStr);
			}
			if (id != -1 && time != "" && sitename != "" && day >= 1 && day <= 31 && month >= 1 && month < 13 && year != 0)
				this->addRouteSite(id, Date(day, month, year), time, sitename);
			else
				cout << "ERROR: Command failed due to invalid parameters";
		}
		if (command == "Add-route-address")
		{
			int id = -1;
			fin >> id;
			string date = "";
			fin >> date;
			string time = "";
			fin >> time;
			string sitename = "";
			fin >> sitename;
			string city = "";
			fin >> city;
			string street = "";
			fin >> street;
			int number = -1;
			fin >> number;
			int day = 0, month = 0, year = 0;
			string delimiter = "/";
			size_t pos = 0;
			pos = date.find(delimiter);
			string dayStr = date.substr(0, pos);
			date.erase(0, pos + delimiter.length());
			pos = date.find(delimiter);
			string monthStr = date.substr(0, pos);
			date.erase(0, pos + delimiter.length());
			string yearStr = date;
			if (dayStr != "" && monthStr != "" && yearStr != "")
			{
				day = stoi(dayStr);
				month = stoi(monthStr);
				year = stoi(yearStr);
			}
			if (id != -1 && time != "" && sitename != "" && day >= 1 && day <= 31 && month >= 1 && month < 13 && year != 0 && city != "" && street != "" && number != -1)
				this->addRouteAddr(id, Date(day, month, year), time, sitename, city, street, number);
			else
				cout << "ERROR: Command failed due to invalid parameters";

		}
		if (command == "Add-sick-encounter")
		{
			int id = -1;
			fin >> id;
			string firstname = "";
			fin >> firstname;
			string lastname = "";
			fin >> lastname;
			string phone = "";
			fin >> phone;
			if (id != -1 && firstname != "" && lastname != "" && phone != "")
				this->addSickEncounter(id, firstname, lastname, phone);
			else
				cout << "ERROR: Command failed due to invalid parameters";
		}
		if (command == "Show-sick-encounter")
		{
			this->showSickEncounter();
		}
		if (command == "Update-sick-encounter-details")
		{
			int encounterid = -1;
			fin >> encounterid;
			int id = -1;
			fin >> id;
			string firstname = "";
			fin >> firstname;
			string lastname = "";
			fin >> lastname;
			string birthdate = "";
			fin >> birthdate;
			string phone = "";
			fin >> phone;
			string mail = "";
			fin >> mail;
			string city = "";
			fin >> city;
			string street = "";
			fin >> street;
			int housenumber = -1;
			fin >> housenumber;
			int apartment = -1;
			fin >> apartment;
			int houseresidents = -1;
			fin >> houseresidents;
			int day = 0, month = 0, year = 0;
			string delimiter = "/";
			size_t pos = 0;
			pos = birthdate.find(delimiter);
			string dayStr = birthdate.substr(0, pos);
			birthdate.erase(0, pos + delimiter.length());
			pos = birthdate.find(delimiter);
			string monthStr = birthdate.substr(0, pos);
			birthdate.erase(0, pos + delimiter.length());
			string yearStr = birthdate;
			if (dayStr != "" && monthStr != "" && yearStr != "")
			{
				day = stoi(dayStr);
				month = stoi(monthStr);
				year = stoi(yearStr);
			}

			if (encounterid != -1 && id != -1 && firstname != "" && lastname != "" && day >= 1 && day <= 31 && month >= 1 && month < 13 && year != 0 && phone != "" && mail != "" && city != "" && street != "" && housenumber != -1 && apartment != -1 && houseresidents != -1)
				this->updateSickEncounter(encounterid, id, firstname, lastname, Date(day, month, year), phone, mail, city, street, housenumber, apartment, houseresidents);
			else
				cout << "ERROR: Command failed due to invalid parameters";
		}
		if (command == "Update-lab-test")
		{
			int labid = -1;
			fin >> labid;
			int testid = -1;
			fin >> testid;
			int personid = -1;
			fin >> personid;
			string date = "";
			fin >> date;
			string result = "";
			fin >> result;
			int day = 0, month = 0, year = 0;
			string delimiter = "/";
			size_t pos = 0;
			pos = date.find(delimiter);
			string dayStr = date.substr(0, pos);
			date.erase(0, pos + delimiter.length());
			pos = date.find(delimiter);
			string monthStr = date.substr(0, pos);
			date.erase(0, pos + delimiter.length());
			string yearStr = date;
			if (dayStr != "" && monthStr != "" && yearStr != "")
			{
				day = stoi(dayStr);
				month = stoi(monthStr);
				year = stoi(yearStr);
			}
			if (labid != -1 && testid != -1 && personid != -1 && day >= 1 && day <= 31 && month >= 1 && month < 13 && year != 0 && result != "")
				this->updateLabResult(labid, testid, personid, Date(day, month, year), result);
			else
				cout << "ERROR: Command failed due to invalid parameters";

		}
		if (command == "Show-new-sick")
		{

			this->showNewSicks();

		}
		if (command == "Show-sick")
		{

			this->showSicks();

		}
		if (command == "Show-person-route")
		{
			int personid;
			fin >> personid;
			this->showpersonRoute(personid);
		}
		if (command == "Show-person")
		{
			int personid;
			fin >> personid;
			this->showPerson(personid);
		}
		if (command == "Show-isolated")
		{
			this->showQuarantine();
		}
		if (command == "Show-stat")
		{
			string options;
			getline(fin, options);
			cout << options;
			string delimiter = ", ";

			size_t pos = 0;
			string token;
			while ((pos = options.find(delimiter)) != std::string::npos) {
				token = options.substr(0, pos);
				this->showStat(token);
				options.erase(0, pos + delimiter.length());
			}
			this->showStat(options);

		}
		if (command == "Show-help")
		{
			cout << "1.  Create-sick: Create new Patient" << endl;
			cout << "2.  Add-route-site: Add route of Patient" << endl;
			cout << "3.  Add-route-address : Add route address" << endl;
			cout << "4.  Add-sick-encounter: Add suspect" << endl;
			cout << "5.  Show-sick-encounter: List down sick suspects" << endl;
			cout << "6.  Show-sick: List down All sicks" << endl;
			cout << "7.  Update-sick-encounter -details: Update Suspect to Patient" << endl;
			cout << "8.  Update-lab-test: Add Test detail" << endl;
			cout << "9.  Show-new-sick : List out new Patients since the last run of this command" << endl;
			cout << "10. Show-stat: List out statistics of Patients, stats options – sicks, healed, isolated, sick - per - city each" << endl;
			cout << "11. Show-person: Show Person Detail" << endl;
			cout << "12. Show-person-route : Show person routes in history" << endl;
			cout << "13. Show-isolated: Show list of Isolated" << endl;
			cout << "14. Show-help: Show Commands help" << endl;
		}
		if (command != "Show-stat")
			getline(fin, line);
	}
}