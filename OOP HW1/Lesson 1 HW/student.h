#pragma once

class Student
{
private:
//поля
	char* name;
	int* marks;
	int count_marks;

//служебная функция
	void create_name(const char* student_name);

public:
//прототипы конструкторов
	Student();
	Student(const char* student_name, const int student_mark_count);
	Student(const char* student_name, const int student_mark_count, const int* student_marks);

//методы
	double get_aver();

	//геттеры
	const char* get_name()
	{
		return name;
	}

	int get_mark(int index)
	{
		return marks[index];
	}

	//сеттеры
	void set_name(const char* studentName);
	void set_mark(int mark, int index);

	//прототип деструктора
	~Student();
};



