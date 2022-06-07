#include <iostream>
#include <string>
using namespace std;

class Human
{
	char* name = nullptr;
	int age;

public:

	//конструктор
	Human(const char* name, int age) //const - для того, чтобы можно было передавать литералы
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}

	//сеттеры
	void set_name(const char* name)
	{
		if(strlen(this->name) != strlen(name))
		{
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			
		}
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void set_age(int age)
	{
		this->age = age;
	}

	void set_all(const char* name, int age)
	{
		this->set_name(name);
		this->set_age(age);
	}

	// геттеры
	int get_age()
	{
		return this->age;
	}

	char* getName()
	{
		return this->name;
	}

	//вывод на печать
	void info()
	{
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
		
	}

	//деструктор
	~Human()
	{
		delete[] this->name;
	}

	//все 3 ситуации разрешает конструктор копирования
	
	//human h2(h)
	//имя_класса(const имя_класса& значение переменной)
	//задача - скопировать все переменные, а указатели создать свои и скопировать данные по указателям из название_переменной
	Human(const Human& obj)
	{
		this->age = obj.age;
		this->name = new char[strlen(obj.name) + 1];
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
	}
};

//2-я ситуация
//глобальная функция не изменит возраст в мейне, т. к передаем по значению
//void set_18(Human h) - не работает
void set_18(Human& h) // работает, т. к нет копирования, работаем непосредственно с исходным объектом
{
	h.set_age(18);
}

//3-я ситуация
//возврат из функции по значению
Human New_petya()
{
	Human h("Petya", 30);
	return h;
}

void main()
{
//1-я ситуация
	//Human h("Petya", 18);
	//h.set_name("Petr");
	//h.info();

	//инициализация при создании объекта
	//human h2 = h;
	//объекты не умеют копироваться, если есть указатели, т. к. топорно копируются все значения переменных


//2-я ситуация (не работает, т. к передаем по значению)
	//Human h("Vasya", 30);
	//set_18(h);
	//h.info();

//3-я ситуация не работает из-за копирования
	//Human d = New_petya();
	//d.info();


	//если есть указатели, принципиально нужны деструктор и конструктор копирования!!!
}