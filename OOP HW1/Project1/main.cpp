#include <iostream>
using namespace std;

class elevator
{
private:
	int bottom_floor;
	int top_floor;
	int current_floor;
	bool power_on;
public:
	elevator(int bot = 1, int top = 9, int curr = 1, bool power = true)
	{
		set_bottom(bot);
		set_top(top);
		button(curr);
		power_on = power;
	}

	void print()
	{
		cout << "Bottom floor: " << bottom_floor << endl;
		cout << "Top floor: " << top_floor << endl;
		cout << "Current floor: " << current_floor << endl;
		if (power_on == false)
		{
			cout << "Status: Turned off" << endl;
		}
		else
		{
			cout << "Status: Turned on" << endl;
		}
		cout << endl;
	}

	//setters
	void set_bottom(int bot)
	{
		bottom_floor = bot;
	}

	void set_top(int top)
	{
		if (top > bottom_floor)
		{
			top_floor = top;
		}
		else
		{
			top_floor = bottom_floor + 1;
		}
	}

	void button(int curr)
	{
		if(power_on == true)
		{
			if ((curr <= top_floor) && (curr >= bottom_floor))
			{
				current_floor = curr;
			}
			else if (curr > top_floor)
			{
				current_floor = top_floor;
			}
			else
			{
				current_floor = bottom_floor;
			}
		}
		else
		{
			current_floor = bottom_floor;
		}
	}

	void switcher()
	{
		power_on = !power_on;
	}

	//getters
	bool turned()
	{
		return power_on;
	}

	int current_level()
	{
		return current_floor;
	}
};


int main()
{
	elevator my_elevator_1;
	my_elevator_1.print();
	my_elevator_1.switcher();
	my_elevator_1.print();

	elevator my_elevator_2 (-1, 22, 4, false); // этаж должены быть нижний т.к. нет питания
	my_elevator_2.print();
	my_elevator_2.button(16); // не должен ехать т.к. нет питания
	my_elevator_2.print();
	cout << "Power (1 - on, 0 - off): " <<  my_elevator_2.turned() << endl << endl;

	my_elevator_2.switcher();
	my_elevator_2.button(16);
	my_elevator_2.print();
	cout << "Power (1 - on, 0 - off): " << my_elevator_2.turned() << endl << endl;
	cout << "Current floor: " << my_elevator_2.current_level() << endl << endl;

	elevator my_elevator_3(50, 10, -100, false); // 50-51 50
	my_elevator_3.print();
	my_elevator_3.switcher();
	my_elevator_3.button(120);
	my_elevator_3.print();
}