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

	char& operator[](int index) //�������� ������ �� ������
	{
		return this->str[index];
	}

	const char& operator[](int index) const //�����������, ����� ������������ � ����������� ������� //����� ������ ���������
	{
		return this->str[index];
	}

	String112& set_string(const String112& right) //������� ������
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

	String112& operator+= (const String112& s) //const ����� ��������� ����������� ��������� ������������� ������� //������ & - ����� �� ������ �����
	{
		this->add_string(s);
		return *this;
	}

	String112& operator=(const String112& s)
	{
		//����� �������� "=" ������� ��:
		//1. ������ �� ����������������
		//2. ������ ����������� 
		//3. ������������ �����������

		//������ �� ����������������
		if (this == &s) //���������� ������
		{
			return *this;
		}
		// ������� ������� ���������� string 
		//this->clear(); //���� � �� ��
		this->~String112(); //���� � �� �� // ��� ������� ������� ����� ������� ����������

		//����������� ��� �� ������������ �����������
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

	void remove(char ch) //������� ���������� char (1 byte), ��� ������ �� ��� (4 �����)
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

//�������
//������� � ����������� �� ����� ������������, �������������:
//��������� ������� ����: ���������� - ����������� ����������� - �������� ������������

//��� ������� ������ ���� ������������
// �� ������� ���������� ������� �� ��������, �. �. ��������� �� ����� � ������
//void print_string112(String112 str) 	// <- �� ������� ��� ������: ���������� ������� �� ��������, �. �. ��������� �� ����� � ������
void print_string112(const String112& str) // ����� ���������� �� ������
{
	// ����� �� ����� �������� ������ �� const, �. �. ���������� �� �����, ��� ��� ������ �� ������
	//����������� ������ ����� �������� ������ ����������� ������
	str.print();
}

String112 operator+(const String112& s1, const String112& s2)
{
	String112 res = s1;
	res += s2;
	return res;
}

bool operator==(const String112& s1, const String112& s2) //��������� �����
{
	if (s1.length() != s2.length())
	{
		return false;
	}
	//���� ����� �����, ���������� �� ��������
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

// << � >> ������ ������������� ��� ���������� �������
ostream& operator<<(ostream& os, const String112& str)
{
	str.print();
	return os;
}

istream& operator>>(istream& is, String112& str)
{
	char* tmp = new char[10000000]; //�������� ������ ��� ���� ������
	is >> tmp; //������ ���� //cin ��������� �� ������� �������� ��� �������� ������
	str.set_string(tmp); //���������� ��������� � ���
	delete[] tmp; //������� ������
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

	/*s = s3 + s4;		//��� �� ��������, ��� ��� ����������� ����������� �������� � �����������
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
