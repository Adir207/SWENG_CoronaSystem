#include<string>
#include<iostream>
#include"Date.h"
#include"Lab.h"
using namespace std;
Lab::Lab(int labid, int testid, Date date, string result)
{
	this->labid = labid;
	this->testid = testid;
	this->date = Date(date.d, date.m, date.y);
	this->result = result;
}
void Lab::setlabid(int labid)
{
	this->labid = labid;
}
int Lab::getlabid()
{
	return this->labid;
}
void Lab::settestid(int testid)
{
	this->testid = testid;
}
int Lab::gettestid()
{
	return this->testid;
}
void Lab::setdate(Date date)
{
	this->date = Date(date.d, date.m, date.y);
}
Date Lab::getdate()
{
	return this->date;
}
void Lab::setresult(string result)
{
	this->result = result;
}
string Lab::getresult()
{
	return this->result;
}
void Lab::showLabResult()
{
	cout << date.d << "/" << date.m << "/" << date.y << "  " << labid << "  " << testid << "  " << result << endl;
}