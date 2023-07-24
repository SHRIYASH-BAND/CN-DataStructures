#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d)
    {

        this->numerator = n;
        this->denominator = d;
    }
    void simplify();
    void multiply(Fraction const &f2);
    void print();
    void add(Fraction const &f2);
    Fraction operator+(Fraction const &f2) const;
    Fraction operator*(Fraction const &f2) const;
    bool operator==(Fraction const &f2) const;
};

void Fraction::print()
{
    cout << this->numerator << " / " << this->denominator << endl;
}

void Fraction::simplify()
{
    int gcd = 1;
    int j = min(this->numerator, this->denominator);

    for (int i = 2; i <= j; i++)
    {
        if (this->numerator % i == 0 && this->denominator % i == 0)
        {
            gcd = i;
        }
    }

    this->numerator /= gcd;
    this->denominator /= gcd;
}

void Fraction::add(Fraction const &f2)
{
    int lcm = this->denominator * f2.denominator;

    int x = lcm / this->denominator;
    int y = lcm / f2.denominator;

    int num = x * this->numerator + (y * f2.numerator);

    this->numerator = num;
    this->denominator = lcm;
    this->simplify();
}

void Fraction::multiply(Fraction const &f2)
{
    this->numerator = this->numerator * f2.numerator;
    this->denominator = this->denominator * f2.denominator;
    this->simplify();
}

Fraction Fraction::operator+(Fraction const &f2) const
{
    int lcm = this->denominator * f2.denominator;

    int x = lcm / this->denominator;
    int y = lcm / f2.denominator;

    int num = x * this->numerator + (y * f2.numerator);

    Fraction f3 = Fraction(num, lcm);
    f3.simplify();
    return f3;
}

Fraction Fraction::operator*(Fraction const &f2) const
{
    Fraction f3(this->numerator * f2.numerator, this->denominator * f2.denominator);
    f3.simplify();
    return f3;
}

bool Fraction::operator==(Fraction const &f2) const
{
    return ((this->numerator == f2.numerator) && (this->denominator == f2.denominator));
}

int main()
{
    Fraction f1(10, 2), f2(15, 4), f5(15, 4);

    // f1.print();
    // f2.print();
    // f1.add(f2);
    // f1.print();
    // f1.multiply(f2);
    // f1.print();
    // f2.print();
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 * f2;
    f3.print();
    f4.print();
    cout << "\n"
         << (f5 == f2);
    return 0;
}