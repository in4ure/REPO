#include <iostream>
#include <iomanip>
#include "Wallpaper.h"
#include "Room.h"
#include "Flat.h"
using namespace std;

void main()
{
	/*Wallpaper my_wp_1;
	Wallpaper my_wp_2("Beautiful", 9, 0.45, 3100);
	my_wp_1.info();
	my_wp_2.info();*/

	Wallpaper wps[3]{ {"Beautiful", 9, 0.45, 3100},{"Expensive", 9.5, 0.4, 6500},{} };
	//wps[0].info();
	//wps[1].info();
	//wps[2].info();

	Room rooms[3]{ {"Kitchen", 3, 4.5, 2.7, true}, {"Bedroom", 7.5, 6.3, 3.1, false}, {} };

	//cout << rooms[0].get_perimeter() << endl;
	//cout << "Walls area: " <<rooms[0].get_walls_area() << endl;
	//cout << "1 roll actual area: " << wps[0].get_actual_area(rooms[0]) << endl;
	//cout << "Rolls needed: " << wps[0].get_quantity(rooms[0]) << endl;
	//rooms[0].info();

	Flat flat1("My flat", rooms, wps);
	//flats.info();
	flat1.total_quantity();
	cout << "Total price: " << flat1.total_price() << endl;

}