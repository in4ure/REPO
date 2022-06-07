#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

int main()
{
	cout << "Grades" << endl << endl;
	//Работа с 1 объектом
	//Student my_student("Petrov", 3, new int[3]{10, 9, 10});
	//my_student.set_mark(7, 0);
	//cout << my_student.get_name() << ": " << fixed << setprecision(2) << my_student.get_aver() << endl;

	//Работа с массивом объектов
	const int SIZE = 2;
	double sum = 0;
	Student* my_students = new Student[SIZE]{ {"Stud1", 3, new int[3] {4, 5, 9}}, {"Stud2", 3, new int[3] {7, 6, 8}} };
	for (Student* stud = my_students; stud < my_students + SIZE; stud++)
	{
		double aver = stud->get_aver();
		cout << "Avarage " << stud->get_name() << ": " << fixed << setprecision(2) << aver << endl;
		sum += aver;
	}

	cout << "Group avarage: " << fixed << setprecision(2) << sum/SIZE << endl;

	delete[] my_students;
}


