#include <iostream>

using namespace std;


class String112 {
	char* str{ nullptr };
	int len{ 0 };
public:

	String112() // чтобы мы могли создавать пустую строку
	{
	}

	String112(const char* str)
	{
		this->len = strlen(str);
		this->str = new char[this->len + 1];
		strcpy_s(this->str, this->len + 1, str);
	}

	String112(int cnt, char s)
	{
		this->len = cnt;
		this->str = new char[this->len + 1];
		for (int i = 0; i < this->len; i++) {
			this->str[i] = s;
		}
		this->str[this->len] = '\0';
	}
	void print() const //методы const не измен€ют состо€ни€ объекта (пол€)
	{
		cout << this->str;
	}

	int length() const
	{
		return this->len;
	}

	~String112()
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
	}
};


// не выгодно передавать объекты по значению, т. к. создаетс€ ее копи€ в пам€ти
//void print_string112(String112 str) 	// <- не выгодно так делать: передавать объекты по значению, т. к. создаетс€ ее копи€ в пам€ти
void print_string112(const String112& str) // лучше передавать по ссылке
{
	// здесь не будут работать методы не const, т. к. компил€тор не знает, что они ничего не мен€ют
	str.print();
}

void main() {
	String112 s("text");
	print_string112(s);

	String112 s2(4, 'R');
	s2.print();
}
