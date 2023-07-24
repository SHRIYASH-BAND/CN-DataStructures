#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class ComplexNumbers
{
private:
    int real;
    int img;

public:
    ComplexNumbers(int real, int img)
    {
        this->img = img;
        this->real = real;
    }

    void plus(ComplexNumbers const &c2);
    void print();
    void multiply(ComplexNumbers const &c2);
};

void ComplexNumbers::plus(ComplexNumbers const &c2)
{
    this->real += c2.real;
    this->img += c2.img;
}

void ComplexNumbers::print()
{
    cout << real << " + i" << img << endl;
}

void ComplexNumbers::multiply(ComplexNumbers const &c2)
{
    int real = this->real * c2.real - (this->img * c2.img);
    int img = this->real * c2.img + this->img * c2.real;

    this->real = real;
    this->img = img;
}

int main()
{
    int real1, imaginary1, real2, imaginary2;

    cout << "Enter real and img no" << endl;
    cin >> real1 >> imaginary1;
    cout << "Enter real and img no" << endl;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        return 0;
    }
}