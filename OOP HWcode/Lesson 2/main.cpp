#include <iostream>
class Date
{
	int day;
	int month;
	int year;
public:
	Date(int dayP, int monthP, int yearP) : day{ dayP }, month{ monthP }, year{ yearP } {}
	Date() : Date(1, 1, 1970) {}
	void print() 
	{
		std::cout << day << '.' << month << '.'	<< year << '\n';
	}
	Date& setDay(int dayP) 
	{
		day = dayP;
		return *this; 
	}
	Date& setMonth(int monthP) 
	{
		month = monthP;
		return *this;
	}
	Date& setYear(int yearP) {
		year = yearP;
		return *this;
	}
};

int main()
{
	Date date1;
	date1.setDay(29).setMonth(2).setYear(2004);
	date1.print();
	return 0;
}