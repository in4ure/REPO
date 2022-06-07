#pragma once
using namespace std;
#include<iostream>
#include<string>
#include "Wallpaper.h"
#include <math.h>



class Room
{
	//Wallpaper wp;
	string room_name;
	double room_length;
	double room_width;
	double room_height;
	bool ceiling;

public:
	//конструктор
	Room(string room_name = "default room", double room_length = 5, double room_width = 5, double room_height = 2.7, bool ceiling = false)
	{
		this->set_name(room_name);
		this->set_length(room_length);
		this->set_width(room_width);
		this->set_height(room_height);
		this->set_ceiling(ceiling);
	}

	//сеттеры
	void set_name(string room_name)
	{
		this->room_name = room_name;
	}

	void set_length(double room_length)
	{
		(room_length <= 0) ? this->room_length = 5 : this->room_length = room_length;
	}

	void set_width(double room_width)
	{
		(room_width <= 0) ? this->room_width = 5 : this->room_width = room_width;
	}

	void set_height(double room_height)
	{
		this->room_height = room_height;
	}

	void set_ceiling(bool ceiling)
	{
		this->ceiling = ceiling;
	}

	//геттеры

	string get_name() const
	{
		return this->room_name;
	}

	double get_length() const
	{
		return this->room_length;
	}

	double get_width() const
	{
		return this->room_width;
	}

	double get_height() const
	{
		return this->room_height;
	}

	bool get_ceiling() const
	{
		return this->ceiling;
	}

	double get_perimeter() const
	{
		return 2 * (this->room_length + this->room_width);
	}

	double get_walls_area() const
	{
		return this->get_perimeter() * this->room_height;
	}

	double get_ceiling_area() const
	{
		return this->room_length * this->room_width;
	}

	double get_actual_area(Wallpaper wps) const // площадь одного рулона за минусом обрезков
	{
		return ((int)(wps.get_length() / this->get_height())) * wps.get_width() * wps.get_length();
	}

	double get_rolls_quantity(Wallpaper wps) const
	{
		return (int)((this->get_walls_area()/ this->get_actual_area(wps))) + 1;
	}

	double get_room_price(Wallpaper wps)
	{
		if (this->ceiling == false)
		{
			return this->get_rolls_quantity(wps) * wps.get_price();
		}
		else
		{
			int ceiling_rolls_quantity;
			if (fmod(this->get_ceiling_area(), wps.get_area()) == 0)
			{
				ceiling_rolls_quantity = this->get_ceiling_area() / wps.get_area();
				//cout << "ceiling_rolls_quantity = " << ceiling_rolls_quantity;
			}
			else
			{
				ceiling_rolls_quantity = (int)(this->get_ceiling_area() / wps.get_area() + 1);
				//cout << "ceiling_rolls_quantity = " << ceiling_rolls_quantity;

			}
			return (this->get_rolls_quantity(wps) + ceiling_rolls_quantity) * wps.get_price();

		}

	}
	
	void info() const
	{
		cout << "Name: " << this->room_name << endl;
		cout << "Length: " << this->room_length << endl;
		cout << "Width: " << this->room_width << endl;
		cout << "Height: " << this->room_height << endl;
		cout << "Ceiling: " << this->ceiling << endl;
		cout << "Perimeter: " << this->get_perimeter() << endl;
		cout << "Walls area: " << this->get_walls_area() << endl;
		cout << "Ceiling area: " << this->get_ceiling_area() << endl;
		cout << endl;
	}
};