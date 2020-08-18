#ifndef DATE_H
#define DATE_H
class Date
{
public:
	int d, m, y;
	Date()
	{
		d = 0;
		m = 0;
		y = 0;
	}
	Date(int d, int m, int y)
	{
		this->d = d;
		this->m = m;
		this->y = y;
	}
};
#endif