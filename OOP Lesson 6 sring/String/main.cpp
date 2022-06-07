#include <iostream>
using namespace std;

class String112 {
	char* str{ nullptr };
	int len{ 0 };
public:

	String112() // чтобы мы могли создавать пустую строку
	{
	}

	String112(const char* str) //конструкторы не могут быть константными
	{
		this->len = strlen(str);
		this->str = new char[this->len + 1];
		strcpy_s(this->str, this->len + 1, str);
	}

	String112(int cnt, char s) //конструкторы не могут быть константными
	{
		this->len = cnt;
		this->str = new char[this->len + 1];
		for (int i = 0; i < this->len; i++) {
			this->str[i] = s;
		}
		this->str[this->len] = '\0';
	}

	String112(const String112& right) //конструктор копирования (скопировать текст из right в this)
	{
		if (right.str != nullptr)
		{
			this->len = right.len;
			this->str = new char[this->len + 1];
			strcpy_s(this->str, this->len + 1, right.str);
		}
	}

	char& operator[](int index) //получаем символ из строки
	{
		return this->str[index];
	}

	const char& operator[](int index) const //перегружаем, чтобы использовать в константных методах //конст меняет сигнатуру
	{
		return this->str[index];
	}

	String112& set_string(const String112& right) //задание строки
	{
		this->clear();
		if (right.str != nullptr)
		{
			this->len = right.len;
			this->str = new char[this->len + 1];
			strcpy_s(this->str, this->len + 1, right.str);
		}
		return *this;
	}

	void add_string(const String112& right)
	{
		if (right.str == nullptr)
		{
			return;
		}
		if (this->str == nullptr)
		{
			this->set_string(right);
			return;
		}
		this->len += right.len; //записываем общую длину в this->len
		char* n_str = new char[this->len + 1]; // выделяем память для новой строки
		strcpy_s(n_str, this->len + 1, this->str); //записываем в новую строку из this
		strcat_s(n_str, this->len + 1, right.str); //прибавляем к новой строке строку из right
		delete[] this->str;
		this->str = n_str;
	}

	void clear()
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
			this->str = nullptr;
			this->len = 0;
		}
	}

	void print() const //методы const не изменяют состояния объекта (поля)
	{
		if (this->str == nullptr)
		{
			cout << "Empty string" << endl;
		}
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
			this->str = nullptr;
			this->len = 0;
		}
	}

	String112& operator+= (const String112& s) //const чтобы исключить возможность изменения передаваемого объекта //ссылка & - чтобы не делать копию
	{
		this->add_string(s);
		return *this;
	}

	String112& operator=(const String112& s)
	{
		//любой оператор "=" состоит из:
		//1. защиты от самоприсваивания
		//2. вызова деструктора 
		//3. конструктора копирования

		//защита от самоприсваивания
		if (this == &s) //сравниваем адреса
		{
			return *this;
		}
		// сначала удаляем содержимое string 
		//this->clear(); //одно и то же
		this->~String112(); //одно и то же // для очистки объекта можно вызвать деструктор

		//скопировали код из конструктора копирования
		if (s.str != nullptr)
		{
			this->len = s.len;
			this->str = new char[this->len + 1];
			strcpy_s(this->str, this->len + 1, s.str);
		}
		return *this;
	}

	void reverse()
	{
		for (int i = 0; i < this->len / 2; i++)
		{
			swap(this->str[i], this->str[this->len - i - 1]);
		}
	}

	bool empty() const
	{
		return this->str == nullptr;
	}

	void replace(char from, char to)
	{
		for (int i = 0; i < this->len; i++)
		{
			if (this->str[i] == from)
			{
				this->str[i] = to;
			}
		}
	}

	void remove(char ch) //выгодно передавать char (1 byte), чем ссылку на чар (4 байта)
	{
		int count = 0;
		for (int i = 0; i < this->len; i++)
		{
			if (this->str[i] == ch)
			{
				count++;
			}
		}
		char* new_str = new char[this->len + 1 - count];
		for (int i = 0, k = 0; i < this->len + 1; i++)
		{
			if (this->str[i] != ch)
			{
				new_str[k] = this->str[i];
				k++;
			}
		}
		this->len -= count;
		delete[] this->str;
		this->str = new_str;
	}

	friend ostream& operator<<(ostream& os, const String112& str);
	friend bool operator==(const String112& s1, const String112& s2);
	friend bool operator> (const String112& s1, const String112& s2);
	friend bool operator< (const String112& s1, const String112& s2);
	friend bool operator>= (const String112& s1, const String112& s2);
	friend bool operator<= (const String112& s1, const String112& s2);
};

//ПРАВИЛО
//ОБЪЕКТЫ С УКАЗАТЕЛЯМИ НЕ УМЕЮТ КОПИРОВАТЬСЯ, СЛЕДОВАТЕЛЬНО:
//ДЕЙСТВУЕТ ПРАВИЛО ТРЕХ: ДЕСТРУКТОР - КОНСТРУКТОР КОПИРОВАНИЯ - ОПЕРАТОР ПРИСВАИВАНИЯ

//все геттеры должны быть константными
// не выгодно передавать объекты по значению, т. к. создается ее копия в памяти
//void print_string112(String112 str) 	// <- не выгодно так делать: передавать объекты по значению, т. к. создается ее копия в памяти
void print_string112(const String112& str) // лучше передавать по ссылке
{
	// здесь не будут работать методы не const, т. к. компилятор не знает, что они ничего не меняют
	//константные ссылки могут вызывать только константные методы
	str.print();
}

String112 operator+(const String112& s1, const String112& s2)
{
	String112 res = s1;
	res += s2;
	return res;
}

bool operator==(const String112& s1, const String112& s2) //равенство строк
{
	if (s1.length() != s2.length())
	{
		return false;
	}
	//если длины равны, сравниваем по алфавиту
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1.str[i] != s2.str[i])
		{
			return false;
		}
		return true;
	}
}

bool operator> (const String112& s1, const String112& s2)
{
	if (s1.length() < s2.length())
	{
		return false;
	}
	if (s1.length() > s2.length())
	{
		return true;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1.str[i] > s2.str[i])
		{
			return true;
		}
	}
	return false;
}

bool operator< (const String112& s1, const String112& s2)
{
	if (s1.length() > s2.length())
	{
		return false;
	}
	if (s1.length() < s2.length())
	{
		return true;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1.str[i] < s2.str[i])
		{
			return true;
		}
	}
	return false;
}

bool operator>= (const String112& s1, const String112& s2)
{
	if (s1.length() < s2.length())
	{
		return false;
	}
	if (s1.length() > s2.length())
	{
		return true;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1.str[i] < s2.str[i])
		{
			return false;
		}
	}
	return true;
}

bool operator<= (const String112& s1, const String112& s2)
{
	if (s1.length() > s2.length())
	{
		return false;
	}
	if (s1.length() < s2.length())
	{
		return true;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1.str[i] > s2.str[i])
		{
			return false;
		}
	}
	return true;
}

// << и >> всегда перегружаются как глобальные функции
ostream& operator<<(ostream& os, const String112& str)
{
	str.print();
	return os;
}

istream& operator>>(istream& is, String112& str)
{
	char* tmp = new char[10000000]; //выделяем память под нашу строку
	is >> tmp; //вводим туда //cin считывает до первого проблема или переноса строки
	str.set_string(tmp); //записываем введенное в стр
	delete[] tmp; //удаляем память
	return is;
}



void main()
{
	String112 s("text1");
	String112 s2("text2");
	String112 s3("text3");
	String112 s4("Hello");

	//s.set_string(s2);
	//s.print();
	//s += s2 += s2;
	//s.print();

	/*s = s3 + s4;		//так не работает, так как присутствуе копирование объектов с указателями
	s.print();
	*/

	/*s = s2 = s3;
	cin >> s;
	cout << s;*/
	cout << s[2];
	s[1] = '3';
	cout << endl << s << endl;
	s4.reverse();
	cout << s4 << endl;
	s4.replace('H', 'K');
	cout << s4 << endl;
	s4.remove('l');
	cout << s4 << endl;
	cout << (s3 > s2);
}
