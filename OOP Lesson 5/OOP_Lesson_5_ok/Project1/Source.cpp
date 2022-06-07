#include <iostream>
using namespace std;

class Point
{
public:
	Point()
	{
		this->x = new int{ 0 };
		this->y = new int{ 0 };
		this->z = new int{ 0 };
	}

	Point(int x, int y = 0, int z = 0)
	{
		this->x = new int{ x };
		this->y = new int{ y };
		this->z = new int{ z };
	}

	void setX(int x)
	{
		*this->x = x;
	}

	void setY(int y)
	{
		*this->y = y;
	}

	void setZ(int z)
	{
		*this->z = z;
	}

	int getX()
	{
		return *this->x;
	}
	
	int getY()
	{
		return *this->y;
	}
	
	int getZ()
	{
		return *this->z;
	}

	void info()
	{
		cout << "X: " << *this->x << endl;
		cout << "Y: " << *this->y << endl;
		cout << "Z: " << *this->z << endl << endl;
	}

	void input()
	{
		cin >> *this->x >> *this->y >> *this->z;
	}

	~Point()
	{
		delete this->x;
		delete this->y;
		delete this->z;
	}

private:
	int* x = nullptr;
	int* y = nullptr;
	int* z = nullptr;
};

void main()
{
	Point p1;
	p1.info();

	Point p2(3, 4, 5);
	p2.info();

	Point p3;
	p3.input();
	p3.info();

}