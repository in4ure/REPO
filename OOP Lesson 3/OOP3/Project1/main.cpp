
/*
#include "clock_.h"
#include "drob.h"


class Drob
{
public:
	int x = 3, y = 2;
};

void main()
{
	Drob d;
	d.x;

	int t = 7;
	int* tt;
	tt = &t;
	*tt = 8;
	tt = new int(5); //� tt ������������ ����� ������ � ���� 


	Drob* dd = new Drob;
	(*dd).x = 7; // �� ������
	dd->x = 7; // ������
}

*/

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
	//�����������
	Clock_(int h, int m, int s)
	{
		set_clock(h, m, s);
	}

	//�������
	void set_sec(int seconds)
	{
		if ((seconds >= 0) && (seconds < 60))
		{
			this->seconds = seconds; //this - ��������� � ����� ������
		}
		else
		{
			this->seconds = 0; //this - ��������� � ����� ������
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
		if ((hour >= 0) && (hour < 60))
		{
			hours = hour;
		}
		else
		{
			hours = 0;
		}
	}

	void set_clock(int hour = 0, int min = 0, int sec = 0)
	{
		set_sec(sec);
		set_min(min);
		set_hour(hour);
	}

	//�������
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

		cout << seconds << endl;
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
	
	SetConsoleCP(1251); //��� �������� � �������
	SetConsoleOutputCP(1251); //��� �������� � �������

	Clock_* c = new Clock_(1, 2, 3);
	(*c).print_clock(); //���� � �� ��
	c->print_clock(); //���� � �� ��

	Clock_* c_arr = new Clock_[2]{{1, 2, 3}, {4, 5, 6}}; // ������ �� ���� �����
	c_arr[0].print_clock(); // ����� ������ �����
	c_arr[1].print_clock(); // ����� ������ �����


}