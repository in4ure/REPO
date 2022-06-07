#include <iostream>
using namespace std;

class String112 {
	char* str{ nullptr };
	int len{ 0 };
public:

	String112() // ����� �� ����� ��������� ������ ������
	{
	}

	String112(const char* str) //������������ �� ����� ���� ������������
	{
		this->len = strlen(str);
		this->str = new char[this->len + 1];
		strcpy_s(this->str, this->len + 1, str);
	}

	String112(int cnt, char s) //������������ �� ����� ���� ������������
	{
		this->len = cnt;
		this->str = new char[this->len + 1];
		for (int i = 0; i < this->len; i++) {
			this->str[i] = s;
		}
		this->str[this->len] = '\0';
	}

	String112(const String112& right) //����������� ����������� (����������� ����� �� right � this)
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
		this->len += right.len; //���������� ����� ����� � this->len
		char* n_str = new char[this->len + 1]; // �������� ������ ��� ����� ������
		strcpy_s(n_str, this->len + 1, this->str); //���������� � ����� ������ �� this
		strcat_s(n_str, this->len + 1, right.str); //���������� � ����� ������ ������ �� right
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

	void print() const //������ const �� �������� ��������� ������� (����)
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

	String112& operator+= (const String112& s) //const ����� ��������� ����������� ��������� ������������� ������� //������ & - ����� �� ������ �����
	{
		this->add_string(s);
		return *this;
	}

};

//��� ������� ������ ���� ������������




