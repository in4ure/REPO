#include<iostream>
#include "student.h"
using namespace std;

//конструкторы
Student :: Student()
{
	name = new char[] {"Vasya"};
	marks = nullptr;
	count_marks = 0;
}

Student :: Student(const char* student_name, const int student_mark_count)
{
	std::cout << ">>Constructor works here<<" << std::endl;
	create_name(student_name);

	marks = new int[student_mark_count];
	for (int i = 0; i < student_mark_count; i++)
	{
		marks[i] = 0;
	}
	count_marks = student_mark_count;
}

Student :: Student(const char* student_name, const int student_mark_count, const int* student_marks)
{
	std::cout << ">>Constructor works here<<" << std::endl;
	create_name(student_name);

	marks = new int[student_mark_count];
	for (int i = 0; i < student_mark_count; i++)
	{
		marks[i] = student_marks[i];
	}
	count_marks = student_mark_count;

}

//деструктор
Student :: ~Student()
{
	cout << ">>Destructor works here for " << name << "<<\n";

	if (name != nullptr)
	{
		delete[] name;
	}

	if (marks != nullptr)
	{
		delete[] marks;
	}
	//system("pause");
}

//служебная функция
void Student::create_name(const char* student_name)
{
	int name_length = strlen(student_name);
	name = new char[name_length + 1];
	for (int i = 0; i < name_length; i++)
	{
		name[i] = student_name[i];
	}
	name[strlen(student_name)] = '\0'; // чтобы после имени не было лишних символов
}

//сеттеры
void Student::set_name(const char* student_name)
{
	delete[] name;
	create_name(student_name);
}

void Student::set_mark(int mark, int index)
{
	if ((index < 0) or (index >= count_marks))
	{
		return;
	}
	if ((mark < 1) or (mark > 12))
	{
		mark = 0;
	}
	marks[index] = mark;
}



double Student :: get_aver()
{
	double sum = 0;
	for (int i = 0; i < count_marks; i++)
	{
		sum += marks[i];
	}
	return sum / count_marks;
}