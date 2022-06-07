#pragma once

class Student
{
private:
//����
	char* name;
	int* marks;
	int count_marks;

//��������� �������
	void create_name(const char* student_name);

public:
//��������� �������������
	Student();
	Student(const char* student_name, const int student_mark_count);
	Student(const char* student_name, const int student_mark_count, const int* student_marks);

//������
	double get_aver();

	//�������
	const char* get_name()
	{
		return name;
	}

	int get_mark(int index)
	{
		return marks[index];
	}

	//�������
	void set_name(const char* studentName);
	void set_mark(int mark, int index);

	//�������� �����������
	~Student();
};



