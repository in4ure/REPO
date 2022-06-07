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

    //сеттеры
    void setX(int x) 
    {
        this->x = x;
    }

    void setY(int y)
    {
        (y == 0) ? this->y = 1 : this->y = y;
    }

    //геттеры
    int getX() const { return this->x; } 
    int getY() const { return this->y; }  

    //перегруженные операторы
    //перегружаются только унарные и бинарные операции
    Drob& operator+=(const Drob& right) // перегрузка оператора
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

    Drob operator+ (const Drob& right) //перегрузка оператора ввиде метода // приоритетно при перегрузке вызывается метод внутри класса, а не глобальная функция перегрузки
    {
        //Drob res(this->x, this->y); // одно и то же
        Drob res = *this; // одно и то же //вызов конструктора копирования по умолчанию
        res += right;
        return res;

    }
    
    //перегрузка префиксного ++
    Drob& operator++()
    {
        this->x += this->y;
        return *this;
    }

    //перегрузка постфиксного ++
    Drob operator++(int) // int - костыль, чтобы работал постфиксный инкремент
    {
      //Drob tmp (this->x , this->y); // одно и то же
        Drob tmp = *this; // одно и то же
        this->x += this->y;
        return tmp;
    }

    // остальные методы
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

    void reduce() //сократить дробь
    {
        int tmp = nod(this->x, this->y);
        this->x /= tmp;
        this->y /= tmp;
    }

    //прототипы глобальных функций-перегрузок операторов
    friend ostream& operator<< (ostream& out, const Drob& d); // прототип дружественной функции
    friend istream& operator>> (istream& in, Drob& d);
    friend bool operator> (const Drob& a, const Drob& b);
    friend bool operator>= (const Drob& a, const Drob& b);
    friend bool operator< (const Drob& a, const Drob& b);
    friend bool operator<= (const Drob& a, const Drob& b);

};


//АРИФМЕТИКА
Drob operator+ (const Drob& a, const Drob& b) //перегрузка оператора ввиде глобальной функции
{
    //Drob res(this->x, this->y); // одно и то же
    Drob res = a; // одно и то же //вызов конструктора копирования по умолчанию
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

//ЛОГИКА
bool operator== (const Drob& a, const Drob& b)
{
    //if (a == b) // так нельзя, так как вызываем сами себя (==)
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

//ВВОД-ВЫВОД
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
// если в ходе операции не изменяется ни один из объектов-операндов, перегружаем в глобальной функции
// если объект изменяется - перегружаем методом класса

// перегрузка оператора = актуальна при использовании указателей

// логические операции : > < >= <= == !=

// все сравнения можно неалзовать через <
//d1 < d2           // <
//!(d1 < d2)        // >=
//!(d1 < d2)&&!(d2 < d1)        // !=
//(d1 < d2)||(d2 < d1)          // ==
//!(!(d1 < d2)&&!(d2 < d1))     // ==
