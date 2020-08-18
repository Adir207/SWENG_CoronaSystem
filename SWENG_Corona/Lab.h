#ifndef LAB_H
#define LAB_H
#include<string>
using namespace std;
class Lab
{
private:
	int labid;
	int testid;
	Date date;
	string result;
public:
	Lab(int labid = -1, int testid = -1, Date date = Date(), string result = "");
	void setlabid(int labid);
	int getlabid();
	void settestid(int testid);
	int gettestid();
	void setdate(Date date);
	Date getdate();
	void setresult(string result);
	string getresult();
	void showLabResult();
};
#endif