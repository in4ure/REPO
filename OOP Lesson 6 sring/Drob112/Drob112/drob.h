#pragma once
#include <iostream>
using namespace std;

class Drob 
{
    int x, y;
public:
    Drob(int x = 0, int y = 1) 
    {
        this->setX(x);
        this->setY(y);
    }

    //�������
    void setX(int x) 
    {
        this->x = x;
    }

    void setY(int y)
    {
        (y == 0) ? this->y = 1 : this->y = y;
    }

    //�������
    int getX() const { return this->x; } 
    int getY() const { return this->y; }  

    //������������� ���������
    //������������� ������ ������� � �������� ��������
    Drob& operator+=(const Drob& right) // ���������� ���������
    {
        //this += right
        this->x = this->x * right.y + right.x * this->y;
        this->y = this->y * right.y;
        this->reduce();
        return *this;
    }

    Drob& operator-=(const Drob& right)
    {
        //this += right
        this->x = this->x * right.y - right.x * this->y;
        this->y = this->y * right.y;
        this->reduce();
        return *this;
    }

    Drob& operator*=(const Drob& right)
    {
        this->x = this->x * right.x;
        this->y = this->y * right.y;
        this->reduce();
        return *this;
    }

    Drob& operator/=(const Drob& right)
    {
        this->x = this->x * right.y;
        this->y = this->y * right.x;
        this->reduce();
        return *this;
    }

    Drob operator+ (const Drob& right) //���������� ��������� ����� ������ // ����������� ��� ���������� ���������� ����� ������ ������, � �� ���������� ������� ����������
    {
        //Drob res(this->x, this->y); // ���� � �� ��
        Drob res = *this; // ���� � �� �� //����� ������������ ����������� �� ���������
        res += right;
        return res;

    }
    
    //���������� ����������� ++
    Drob& operator++()
    {
        this->x += this->y;
        return *this;
    }

    //���������� ������������ ++
    Drob operator++(int) // int - �������, ����� ������� ����������� ���������
    {
      //Drob tmp (this->x , this->y); // ���� � �� ��
        Drob tmp = *this; // ���� � �� ��
        this->x += this->y;
        return tmp;
    }

    // ��������� ������
    void print() const
    {
        cout << x << " / " << y << " = " << (double)this->x / this->y;
    }

    double get_decimal() const
    {
        return (double)this->x / this->y;
    }

    int nod(int x, int y) 
    {
        if (y == 0)
            return x;
        return nod(y, x % y);
    }

    void reduce() //��������� �����
    {
        int tmp = nod(this->x, this->y);
        this->x /= tmp;
        this->y /= tmp;
    }

    //��������� ���������� �������-���������� ����������
    friend ostream& operator<< (ostream& out, const Drob& d); // �������� ������������� �������
    friend istream& operator>> (istream& in, Drob& d);
    friend bool operator> (const Drob& a, const Drob& b);
    friend bool operator>= (const Drob& a, const Drob& b);
    friend bool operator< (const Drob& a, const Drob& b);
    friend bool operator<= (const Drob& a, const Drob& b);

};


//����������
Drob operator+ (const Drob& a, const Drob& b) //���������� ��������� ����� ���������� �������
{
    //Drob res(this->x, this->y); // ���� � �� ��
    Drob res = a; // ���� � �� �� //����� ������������ ����������� �� ���������
    res += b;
    res.reduce();
    return res;
}

Drob operator+ (const Drob& a, int b)
{
    Drob res = a;
    res += Drob(b);
    return res;
}

Drob operator+ (int a, const Drob& b)
{
    Drob res = b;
    res += Drob(a);
    return res;
}

Drob operator- (const Drob& a, const Drob& b)
{
    Drob res = a; 
    res -= b;
    res.reduce();
    return res;
}

Drob operator- (const Drob& a, int b)
{
    Drob res = a;
    res -= Drob(b);
    return res;
}

Drob operator- (int a, const Drob& b)
{
    Drob res = Drob(a);
    res -= b;
    res.reduce();
    return res;
}

Drob operator* (const Drob& a, const Drob& b)
{
    Drob res = a; 
    res *= b;
    res.reduce();
    return res;
}

Drob operator* (const Drob& a, int b)
{
    Drob res = a;
    res *= Drob(b);
    return res;
}

Drob operator* (int a, const Drob& b)
{
    Drob res = b;
    res *= Drob(a);
    return res;
}

Drob operator/ (const Drob& a, const Drob& b)
{
    Drob res = a; 
    res /= b;
    res.reduce();
    return res;
}

Drob operator/ (const Drob& a, int b)
{
    Drob res = a;
    res /= Drob(b);
    return res;
}

Drob operator/ (int a, const Drob& b)
{
    Drob res = Drob(a);
    res /= b;
    res.reduce();
    return res;
}


Drob operator- (const Drob& a)
{
    Drob res(-a.getX(), a.getY());
    return res;
}

//������
bool operator== (const Drob& a, const Drob& b)
{
    //if (a == b) // ��� ������, ��� ��� �������� ���� ���� (==)
    return a.get_decimal() == b.get_decimal();
}

bool operator> (const Drob& a, const Drob& b)
{
    int A = a.x * b.y;
    int B = b.x * a.y;
    return A > B;
}

bool operator< (const Drob& a, const Drob& b)
{
    int A = a.x * b.y;
    int B = b.x * a.y;
    return A < B;
}

bool operator>= (const Drob& a, const Drob& b)
{
    int A = a.x * b.y;
    int B = b.x * a.y;
    return A >= B;
}

bool operator<= (const Drob& a, const Drob& b)
{
    int A = a.x * b.y;
    int B = b.x * a.y;
    return A <= B;
}

//����-�����
ostream& operator<< (ostream& out, const Drob& d)
{
    //out == cout;
    out << d.x << " / " << d.y << " = " << (double)d.x / d.y << endl;
    return out;
}

istream& operator>> (istream& in, Drob& d)
{
    cout << "Enter x: ";
    in >> d.x;
    cout << "Enter y:";
    int Y;
    in >> Y;
    d.setY(Y);
    return in;
}
// ���� � ���� �������� �� ���������� �� ���� �� ��������-���������, ����������� � ���������� �������
// ���� ������ ���������� - ����������� ������� ������

// ���������� ��������� = ��������� ��� ������������� ����������

// ���������� �������� : > < >= <= == !=

// ��� ��������� ����� ���������� ����� <
//d1 < d2           // <
//!(d1 < d2)        // >=
//!(d1 < d2)&&!(d2 < d1)        // !=
//(d1 < d2)||(d2 < d1)          // ==
//!(!(d1 < d2)&&!(d2 < d1))     // ==
