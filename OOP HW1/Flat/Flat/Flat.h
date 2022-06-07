#pragma once
#include <string>
#include "Room.h"
#include "Wallpaper.h"
using namespace std;

class Flat
{
	string name;
	Room room[3];
	Wallpaper wps[3];

public:
	//конструкторы
	Flat()
	{
		this->name = "Default flat";
		this->room[0] = {};
		this->room[1] = {};
		this->room[2] = {};
		this->wps[0] = {};
		this->wps[1] = {};
		this->wps[2] = {};
	}

	Flat(string name, Room room[3], Wallpaper wps[3])
	{
		this->name = name;
		for (int i = 0; i < 3; i++)
		{
			this->room[i] = room[i];
			this->wps[i] = wps[i];
		}
	}

	//сеттеры
	void set_name(string name = "Unknown flat")
	{
		this->name = name;
	}

	void change_room(int index, Room room)
	{
		if ((index > 2) && (index < 0))
		{
			cout << "Wrong index" << endl;
			return;
		}
		else
		{
			this->room[index] = room;
		}
	}

	void change_wps(int index, Wallpaper wps)
	{
		if ((index > 2) && (index < 0))
		{
			cout << "Wrong index" << endl;
			return;
		}
		else
		{
			this->wps[index] = wps;
		}
	}

	//геттер
	Room get_room(int index) const
	{
		if ((index > 2) && (index < 0))
		{
			cout << "Wrong index" << endl;
			return this->room[0];
		}
		else
		{
			return this->room[index];
		}
	}

	Wallpaper get_wp(int index) const
	{
		if ((index > 2) && (index < 0))
		{
			cout << "Wrong index" << endl;
			return this->wps[0];
		}
		else
		{
			return this->wps[index];
		}
	}

	void info() const
	{
		cout << this->name;
		for (int i = 0; i < 3; i++)
		{
			this->room[i].info();
			this->wps[i].info();
			cout << endl;
		}
	}

	double total_price()
	{
		double total = 0;
		for (int i = 0; i < 3; i++)
		{
			total += this->room[i].get_room_price(this->wps[i]);
		}
		return total;
	}

	void total_quantity() const
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "You need " << this->room[i].get_rolls_quantity(this->wps[i]) << " rolls of " << wps[i].get_name() << " wallpaper for " << this->room[i].get_name() << endl;
			cout << endl;
		}
	}
};