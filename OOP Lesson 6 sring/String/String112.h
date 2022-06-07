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

	String112& set_string(const String112& right)
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
		if (this->str != nullptr)
		{
			cout << this->str;
		}
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

	String112& operator+= (const String112& s) //const чтобы исключить возможность изменения передаваемого объекта //ссылка & - чтобы не делать копию
	{
		this->add_string(s);
		return *this;
	}

};

//все геттеры должны быть константными




