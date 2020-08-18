#ifndef SUSPECT_H
#define SUSPECT_H
#include"PersonState.h"
#include<iostream>
#include<string>
using namespace std;
class Suspect : public PersonState
{
	int sick_id;
	string sick_firstName;
	string sick_lastName;
	int encounter_id;

public:
	Suspect(int encounter_id = 0, int sickId = 0, string sickfName = "", string sickLName = "");
	int getEncounterId();
	virtual void show();
	virtual int getSourceId();
};
#endif