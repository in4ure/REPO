#include <iostream>

using namespace std;


class String112 {
	char* str{ nullptr };
	int len{ 0 };
public:

	String112() // ����� �� ����� ��������� ������ ������
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
	void print() const //������ const �� �������� ��������� ������� (����)
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


// �� ������� ���������� ������� �� ��������, �. �. ��������� �� ����� � ������
//void print_string112(String112 str) 	// <- �� ������� ��� ������: ���������� ������� �� ��������, �. �. ��������� �� ����� � ������
void print_string112(const String112& str) // ����� ���������� �� ������
{
	// ����� �� ����� �������� ������ �� const, �. �. ���������� �� �����, ��� ��� ������ �� ������
	str.print();
}

void main() {
	String112 s("text");
	print_string112(s);

	String112 s2(4, 'R');
	s2.print();
}
