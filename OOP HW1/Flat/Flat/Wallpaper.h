#pragma once
#include <iostream>
#include <string>
using namespace std;

class Wallpaper
{
	string name;
	float length;
	float width;
	float price;

public:
	//constructor
	Wallpaper(string name = "White", float length = 10, float width = 0.9, float price = 1000)
	{
		this->name = name;
		this->length = length;
		this->width = width;
		this->price = price;
	}

	void info() const
	{
		cout << "Name: " << this->name << endl;
		cout << "Length: " << this->length << " m;" << endl;
		cout << "Width: " << this->width << " m;" << endl;
		cout << "Price: " << this->price << " rub.;" << endl << endl;
	}

	//сеттеры

	//геттеры

	string get_name() const
	{
		return this->name;
	}

	double get_length() const
	{
		return this->length;
	}
	
	double get_width() const
	{
		return this->width;
	}

	double get_price() const
	{
		return this->price;
	}

	void info()
	{
		cout << "Wallpaper name: " << this->name << endl;
		cout << "Length: " << this->length << " m" << endl;
		cout << "Width: " << this->width << " m" << endl;
		cout << "Price: " << this->price << " rub" << endl;
		cout << endl;
	}

	float get_area() const //возвращает площадь стен покрываемую 1 рулоном
	{
		return this->length * this->width;
	}

	float get_actual_area(double height) const //возвращает площадь стен покрываемую 1 рулоном (без учета обрезков)
	{
		return ((int)(this->length / height)) * this->width * height;
	}

	int get_quantity(double length, double width, double height) const //возвращает количество рулонов на комнату
	{
		return ((height * (2 * length * width)) / this->get_actual_area(height)) / 1 + 1;
	}

	//перенести в комнату
	//double get_room_price (Room room)
	//{
	//	return this->get_quantity(room)* this->price;
	//}

	// если вся квартира в одинаковых обоях
	//double get_total_price(Flat flat)
	//{
	//	double total = 0;
	//	for (int i = 0; i < 3; i++)
	//	{
	//		total += this->get_room_price(flat.get_room(i));
	//	}
	//}

};