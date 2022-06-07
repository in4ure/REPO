#include <iostream>
#include <Windows.h>
using namespace std;

// структура - нет санкицонирования доступа
//struct drob
//{
//	int x;
//	int y;
//	void print()
//	{
//		cout << x << "/" << y << " = " << x / y;
//	}
//};

//класс - санкционированный доступ (переменные в классе - поля, функции в классе - методы)
class drob
{
private: //public: //protected: - модификаторы доступа
	int x;
	int y;
public:
	
	//если констуктор не создан, компилятор сам сделает пустой конструктор по умолчанию
	//название конструктора соответствует названию класса и никогда ничего не возвращает
	//конструкторы принципиально важны, так как все поля при создании объекта класса должны иметь значение
	
	//конструктор по умолчанию (для создания объектов этого класса) НЕ СОЗДАЕТСЯ АВТОМАТИЧЕСКИ, КОГДА СОЗДАЮТСЯ КОНСТРУКТОРЫ С ПАРАМЕТРАМИ
	//drob()
	//{
	//	//cout << "drob default constructor";
	//	x = 0;
	//	y = 1;
	//}

	////конструктор с параметром
	//drob(int value)
	//{
	//	//cout << "drob NOT default constructor";
	//	x = value;
	//	y = 1;
	//}

	////конструктор с параметрами
	//drob(int value_1, int value_2)
	//{
	//	//cout << "drob NOT default constructor";
	//	x = value_1;
	//	setY(value_2); // вызываем метод setY, для проверки на 0
	//}

	//конструктор с параметрами по умолчанию
	drob(int value_1 = 0, int value_2 = 1) //параметры по умолчанию указываются справа налево: (int a = 1, int b) - нельщя 
	{
		x = value_1;
		setY(value_2);
	}

	void print()
	{
		cout << x << "/" << y << " = " << (double)x / y << endl;
	}

	// setters (или модификаторы) служат для изменения приватных полей и задания для них условий ввода (например, при делении на 0). Сеттеры ничего не возвращают
	void setX(int a) // функция для изменения приватного поля Х
	{
		x = a;
	}

	void setY(int a) // функция для изменения приватного поля Y
	{
		if (a == 0)
		{
			a = 1;
		}

		y = a;
	}

	void setXY(int a, int b) //можно объединить сеттеры

	{
		setX(a);
		setY(b);
	}

	//getters (или инспекторы) служат для получения значений из приватных полей (Геттеры ничего не принимают);
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
	
	void set_clock(int hour, int min, int sec)
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
	drob d; //здесь вызвыается конструктор по умолчанию
	drob c(4); // конструктор с параметром
	drob e(3, 5); // конструктор с параметрами

	//drob d1(); // так не получится

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
	//	system("cls"); //очистить экран
	//	my_clock.print_clock();
	//	my_clock.add_sec();
	//	Sleep(1000);
	//}

}