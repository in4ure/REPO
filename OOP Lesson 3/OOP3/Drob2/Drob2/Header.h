#pragma once
#include <iostream>
using namespace std;


class Drob
{
	int x, y;
	
public:
	Drob(int x = 0, int y = 1)
	{
		this->set_x(x);
		this->set_y(y);
	}

	void set_x(int x)
	{
		this->x = x;
	}

	void set_y(int y)
	{
		this->y = (y==0) ? 1 : y;
	}

	int getX()
	{
		return this->x;
	}
	
	int getY()
	{
		return this->y;
	}

	
	void print()
	{
		cout << this->x / this->y;
	}

};