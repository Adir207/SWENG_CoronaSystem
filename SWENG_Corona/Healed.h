#ifndef HEALED_H
#define HEALED_H
#include"PersonState.h"
#include"Lab.h"
#include<iostream>
#include<string>
using namespace std;
class Healed : public PersonState
{
	Date* healedDate;
	int encounter_id;

public:
	Healed(Date* dateToday);
	virtual Date* getHealedDate();
	virtual void show();
	virtual void showRoutes();
	virtual void showLabResults();
};
#endif