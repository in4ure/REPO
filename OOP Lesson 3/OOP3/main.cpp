#include <iostream>
#include <Windows.h>
using namespace std;

class Clock_
{
private:
	int seconds;
	int minutes;
	int hours;
public:
//конструктор
	Clock_(int h, int m, int s)
	{
		set_clock(h, m, s);
	}

//сеттеры
	void set_sec(int sec)
	{
		if ((sec >= 0) && (sec < 60))
		{
			seconds = sec;
		}
		else
		{
			seconds = 0;
		}
	}

	void set_min(int min)
	{
		if ((min >= 0) && (min < 60))
		{
			minutes = min;
		}
		else
		{
			minutes = 0;
		}
	}

	void set_hour(int hour)
	{
		if ((hour>= 0) && (hour < 60))
		{
			hours = hour;
		}
		else
		{
			hours = 0;
		}
	}
	
	void set_clock(int = 0, int min = 0, int sec = 0)
	{
		set_sec(sec);
		set_min(min);
		set_hour(hour);
	}

	//геттеры
	int get_sec()
	{
		return seconds;
	}
	
	int get_min()
	{
		return minutes;
	}
	int get_hours()
	{
		return hours;
	}

	void print_clock()
	{
		if (hours < 10)
		{
			cout << 0;
		}

		cout << hours << " : ";

		if (minutes < 10)
		{
			cout << 0;
		}

		cout << minutes << " : ";
		
		if (seconds < 10)
		{
			cout << 0;
		}

		cout << seconds;
	}

	void add_sec()
	{
		if (seconds == 60)
		{
			seconds = 0;
			minutes++;
			if (minutes == 60)
			{
				minutes = 0;
				hours++;
				if (hours == 24)
				{
					hours = 0;
				}
			}
		}
		
	}
};


int main()
{
	Clock_* c = new Clock_(1, 2, 3);
	(*c).print_clock(); //одно и то же
	c->print_clock(); //одно и то же

	Clock_* c_arr = new Clock_[3]{ {1, 2, 3}, {4, 5, 6} }, {}); // массив из двух часов
	c_arr[0].print_clock; // вывод первых часов
	с_arr[1].print_clock; // вывод вторых часов
	с_arr[2].print_clock; // вывод третьих часов
}