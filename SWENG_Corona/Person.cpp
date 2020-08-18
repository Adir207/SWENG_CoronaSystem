#include"Person.h"
#include<string>
using namespace std;
Person::Person(int personid, string firstname, string lastname, Date birthdate, string phone, string email, string city, string street, int housenumber, int apartment, int houseresidents, PersonState* state)
{
	this->personid = personid;
	this->firstname = firstname;
	this->lastname = lastname;
	this->birthdate = birthdate;
	this->phone = phone;
	this->email = email;
	this->city = city;
	this->street = street;
	this->housenumber = housenumber;
	this->apartment = apartment;
	this->houseresidents = houseresidents;
	this->state = state;
	this->state->setPerson(this);
}
Person::Person(int personid, string firstname, string lastname, string phone, PersonState* state)
{
	this->personid = personid;
	this->firstname = firstname;
	this->lastname = lastname;
	this->birthdate = Date(0, 0, 0);
	this->phone = phone;
	this->state = state;
	this->email = "";
	this->city = "";
	this->street = "";
	this->housenumber = 0;
	this->apartment = 0;
	this->houseresidents = 0;
	this->state->setPerson(this);

}
void Person::setpersonid(int personid)
{
	this->personid = personid;
}
int Person::getpersonid()
{
	return this->personid;
}
void Person::setfirstname(string firstname)
{
	this->firstname = firstname;
}
string Person::getfirstname()
{
	return this->firstname;
}
void Person::setlastname(string lastname)
{
	this->lastname = lastname;
}
string Person::getlastname()
{
	return this->lastname;
}
void Person::setbirthdate(Date birthdate)
{
	this->birthdate = birthdate;
}
Date Person::getbirthdate()
{
	return this->birthdate;
}
void Person::setphone(string phone)
{
	this->phone = phone;
}
string Person::getphone()
{
	return this->phone;
}
void Person::setemail(string email)
{
	this->email = email;
}
string Person::getemail()
{
	return this->email;
}
void Person::setcity(string city)
{
	this->city = city;
}
string Person::getcity()
{
	return this->city;
}void Person::setstreet(string street)
{
	this->street = street;
}
string Person::getstreet()
{
	return this->street;
}
void Person::sethousenumber(int housenumber)
{
	this->housenumber = housenumber;
}
int Person::gethousenumber()
{
	return this->housenumber;
}
void Person::setapartment(int apartment)
{
	this->apartment = apartment;
}
int Person::getapartment()
{
	return this->apartment;
}
void Person::sethouseresidents(int houseresidents)
{
	this->houseresidents = houseresidents;
}
int Person::gethouseresidents()
{
	return this->houseresidents;
}
void Person::TransitionTo(PersonState* state)
{
	if (this->state != nullptr)
	{
		delete this->state;
	}
	this->state = state;
	this->state->setPerson(this);
}
PersonState* Person::getState()
{
	return this->state;
}
