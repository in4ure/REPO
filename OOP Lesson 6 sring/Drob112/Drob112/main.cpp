#include<iostream>
#include"drob.h"
using namespace std;

void main()
{
	Drob d1(1, 1);
	Drob d2(1, 2);
	Drob d3(1, 3);
	Drob d4(1, 4);
	Drob d5(3, 6);

	//d1 += d2 += d3;
	//d1.operator+=(d2); //одно и то же
	//d1 += (d2); //одно и то же

	//cout << (d1 += d2).getX();

	//d1 *= d2 += d3; // одно и то же
	//d1.operator*=(d2.operator+=(d3)); // одно и то же

	//d1.print();

	//int x = 1, y = 2;
	//x = -y;
	//d1 = -d2;
	//cout << d1 << "\n" << d2;
	//cin >> d1;
	//cout << d1;
	cout << d5;
	d5.reduce();
	cout << d5;
	cout << (d3 <= d4);
}