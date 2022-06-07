#include <iostream>
#include <string>
using namespace std;

class Human
{
	char* name = nullptr;
	int age;

public:

	//�����������
	Human(const char* name, int age) //const - ��� ����, ����� ����� ���� ���������� ��������
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = age;
	}

	//�������
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

	// �������
	int get_age()
	{
		return this->age;
	}

	char* getName()
	{
		return this->name;
	}

	//����� �� ������
	void info()
	{
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
		
	}

	//����������
	~Human()
	{
		delete[] this->name;
	}

	//��� 3 �������� ��������� ����������� �����������
	
	//human h2(h)
	//���_������(const ���_������& �������� ����������)
	//������ - ����������� ��� ����������, � ��������� ������� ���� � ����������� ������ �� ���������� �� ��������_����������
	Human(const Human& obj)
	{
		this->age = obj.age;
		this->name = new char[strlen(obj.name) + 1];
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
	}
};

//2-� ��������
//���������� ������� �� ������� ������� � �����, �. � �������� �� ��������
//void set_18(Human h) - �� ��������
void set_18(Human& h) // ��������, �. � ��� �����������, �������� ��������������� � �������� ��������
{
	h.set_age(18);
}

//3-� ��������
//������� �� ������� �� ��������
Human New_petya()
{
	Human h("Petya", 30);
	return h;
}

void main()
{
//1-� ��������
	//Human h("Petya", 18);
	//h.set_name("Petr");
	//h.info();

	//������������� ��� �������� �������
	//human h2 = h;
	//������� �� ����� ������������, ���� ���� ���������, �. �. ������� ���������� ��� �������� ����������


//2-� �������� (�� ��������, �. � �������� �� ��������)
	//Human h("Vasya", 30);
	//set_18(h);
	//h.info();

//3-� �������� �� �������� ��-�� �����������
	//Human d = New_petya();
	//d.info();


	//���� ���� ���������, ������������� ����� ���������� � ����������� �����������!!!
}