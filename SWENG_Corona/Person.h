#ifndef PERSON_H
#define PERSON_H
#include<string>
#include"Route.h"
#include"PersonState.h"
#include"Date.h"
class PersonState;
class Person
{
	int personid;
	string firstname;
	string lastname;
	Date birthdate;
	string phone;
	string email;
	string city;
	string street;
	int housenumber;
	int apartment;
	int houseresidents;
	PersonState* state;
public:
	Person(int personid = 0, string firstname = "", string lastname = "", Date birthdate = Date(), string phone = "", string email = "", string city = "", string street = "", int housenumber = 0, int apartment = 0, int houseresidents = 0, PersonState* state = nullptr);
	Person(int personid, string firstname, string lastname, string phone, PersonState* state);
	void setpersonid(int personid);
	int getpersonid();
	void setfirstname(string firstname);
	string getfirstname();
	void setlastname(string lastname);
	string getlastname();
	void setbirthdate(Date birthdate);
	Date getbirthdate();
	void setphone(string phone);
	string getphone();
	void setemail(string email);
	string getemail();
	void setcity(string city);
	string getcity();
	void setstreet(string street);
	string getstreet();
	void sethousenumber(int housenumber);
	int gethousenumber();
	void setapartment(int apartment);
	int getapartment();
	void sethouseresidents(int houseresidents);
	int gethouseresidents();
	void TransitionTo(PersonState* state);
	PersonState* getState();
};
#endif