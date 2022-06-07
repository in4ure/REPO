#include <iostream>
#include <Windows.h>
using namespace std;

// ��������� - ��� ���������������� �������
//struct drob
//{
//	int x;
//	int y;
//	void print()
//	{
//		cout << x << "/" << y << " = " << x / y;
//	}
//};

//����� - ����������������� ������ (���������� � ������ - ����, ������� � ������ - ������)
class drob
{
private: //public: //protected: - ������������ �������
	int x;
	int y;
public:
	
	//���� ���������� �� ������, ���������� ��� ������� ������ ����������� �� ���������
	//�������� ������������ ������������� �������� ������ � ������� ������ �� ����������
	//������������ ������������� �����, ��� ��� ��� ���� ��� �������� ������� ������ ������ ����� ��������
	
	//����������� �� ��������� (��� �������� �������� ����� ������) �� ��������� �������������, ����� ��������� ������������ � �����������
	//drob()
	//{
	//	//cout << "drob default constructor";
	//	x = 0;
	//	y = 1;
	//}

	////����������� � ����������
	//drob(int value)
	//{
	//	//cout << "drob NOT default constructor";
	//	x = value;
	//	y = 1;
	//}

	////����������� � �����������
	//drob(int value_1, int value_2)
	//{
	//	//cout << "drob NOT default constructor";
	//	x = value_1;
	//	setY(value_2); // �������� ����� setY, ��� �������� �� 0
	//}

	//����������� � ����������� �� ���������
	drob(int value_1 = 0, int value_2 = 1) //��������� �� ��������� ����������� ������ ������: (int a = 1, int b) - ������ 
	{
		x = value_1;
		setY(value_2);
	}

	void print()
	{
		cout << x << "/" << y << " = " << (double)x / y << endl;
	}

	// setters (��� ������������) ������ ��� ��������� ��������� ����� � ������� ��� ��� ������� ����� (��������, ��� ������� �� 0). ������� ������ �� ����������
	void setX(int a) // ������� ��� ��������� ���������� ���� �
	{
		x = a;
	}

	void setY(int a) // ������� ��� ��������� ���������� ���� Y
	{
		if (a == 0)
		{
			a = 1;
		}

		y = a;
	}

	void setXY(int a, int b) //����� ���������� �������

	{
		setX(a);
		setY(b);
	}

	//getters (��� ����������) ������ ��� ��������� �������� �� ��������� ����� (������� ������ �� ���������);
	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}
};



class clock_
{
private:
	int seconds;
	int minutes;
	int hours;
public:

//�������
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
	
	void set_clock(int hour, int min, int sec)
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
	drob d; //����� ���������� ����������� �� ���������
	drob c(4); // ����������� � ����������
	drob e(3, 5); // ����������� � �����������

	//drob d1(); // ��� �� ���������

	//d.setX(5);
	//d.setY(0);
	d.print();
	c.print();
	e.print();
	//cout << endl << "x = " << d.getX() << endl << "y = " << d.getY() << endl;

	//clock_ my_clock;
	//my_clock.set_clock(22, 3, 5);
	//while (1)
	//{
	//	system("cls"); //�������� �����
	//	my_clock.print_clock();
	//	my_clock.add_sec();
	//	Sleep(1000);
	//}

}