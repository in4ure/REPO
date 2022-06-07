#include <iostream>
#include<time.h>
using namespace std;

class Student
{
	char* name = nullptr; //����� � ������� �� ��������� �������������� ��������� ������ // ���������� �� �����, �. �. ���� ������
	int* marks = nullptr;//����� � ������� �� ��������� �������������� ��������� ������
	int count_marks = 0; // ���������� ������
	int course;
	char sex;

public:
	Student(const char* name, int course, char sex)
	{
		this->set_name(name);
		this->set_course(course);
		this->set_sex(sex);
	}

	void set_name(const char* name)
	{
		if (name != nullptr)
		{
			delete[] this->name;
		}
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void set_course(int course)
	{
		if ((course < 1) || (course > 5))
		{
			this->course = 1;
		}
		else
		{
			this->course = course;
		}
	}

	void set_sex(char sex)
	{
		if ((sex != 'm') && (sex != 'f'))
		{
			this->sex = 'm';
		}
		else
		{
			this->sex = sex;
		}
	}

	char* get_name()
	{
		return this->name;
	}

	char get_sex()
	{
		return this->sex;
	}

	int get_course()
	{
		return this->course;
	}

	int get_count_marks()
	{
		return this->count_marks;
	}


	void info()
	{
		srand(time(NULL));
		cout << "Name: " << this->name << endl;
		cout << "Sex: " << this->sex << endl;
		cout << "Course: " << this->course << endl;
		cout << "Marks: ";
		for (int i = 0; i < count_marks; i++)
		{
			cout << marks[i] << "  ";
		}
		cout << endl << endl;
	}

	void add_mark(int mark)
	{
		if (this->marks == nullptr) // ���� ��� ������
		{
			this->marks = new int[++this->count_marks/*1*/]{ mark };
			//this->count_marks++;
			return;
		}
		int* new_marks = new int[this->count_marks + 1]; // ������� ������ ������ �� 1
		for (int i = 0; i < this->count_marks; i++) // �������� ������ � �����
		{
			new_marks[i] = this->marks[i];
		}
		new_marks[this->count_marks] = mark; // ������ ����� ������
		delete[] this->marks; // ������� ������ ������
		this->marks = new_marks;//�������������� ���������
		this->count_marks++;
	}

	float get_avg_mark()
	{
		int sum = 0;
		for (int i = 0; i < this->count_marks; i++)
		{
			sum += this->marks[i];
		}
		return (float)sum / this->count_marks;
	}

	//����������� �����������
	Student(const Student& stud) // � ������������� ������������ ������ ����� �����* ��� ����������
	{
		//stud; //������ ��������
		//this; //���� ����������

		//������� ���������� ������ �����������

		this->course = stud.course;
		this->sex = stud.sex;
		this->count_marks = stud.count_marks;

		//this->name = stud.name; // �� ���������, �� �������� ����� �� ���� ������ � ����

		/*this->name - new char[strlen(stud.name) + 1];
		strcpy_s(this->name, strlen(stud.name) + 1, stud.name);*/

		this->set_name(stud.name); //�������������� ��� ���������� ������

		this->marks = new int[this->count_marks];
		for (int i = 0; i < this->count_marks; i++)
		{
			this->marks[i] = stud.marks[i];
		}
	}

	void change_mark(int index, int mark)
	{
		if ((index < 0) || (index > count_marks))
		{
			cout << "Wrong index.";
		}
		else
		{
			this->marks[index] = mark;
		}
	}

	~Student()
	{
		delete[] this->name;
		delete[] this->marks;
	}
};

void main()
{
	Student my_stud_1{ "Petya", 2, 'm' };
	my_stud_1.add_mark(5);

	my_stud_1.info();

	Student my_stud_2 = my_stud_1;

	my_stud_2.info();
	my_stud_2.add_mark(2);
	my_stud_2.info();

	//	int mark = rand() % 5 + 8; //������ 8-12  //+8 - ��������� ��������, 5 - ������� �����, ������� � 8: 1-8. 2-9 3-10. 4-11. 5-12

	for (int i = 0; i < 10; i++)
	{
		my_stud_1.add_mark(rand() % 5 + 8);
	}
	my_stud_1.info();

}