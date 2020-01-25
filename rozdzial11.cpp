#include "stdafx.h"
using std::cout;
using std::cin;
using std::endl;
Complex Complex::operator+(const Complex &c1) const
{
	return Complex(re + c1.re, im + c1.im);
}

Complex Complex::operator-(const Complex & c1) const
{
	return Complex(re - c1.re, im - c1.im);
}
Complex Complex::operator-() const
{
	return Complex(re, -im);
}

Complex Complex::operator*(const Complex & c1) const
{
	return Complex(re * c1.re - im*c1.im, im*c1.re-re*c1.im);
}

Complex Complex::operator*(const double& n) const
{
	return Complex(re*n, im*n);
}

Complex operator*(const double& n, const Complex & c1)
{
	return c1 * n;
 }


std::istream & operator>>(std::istream & in, Complex & c1)
{
	std::cout << "Podaj czesc rzeczywista: \n";
	in >> c1.re;
	std::cout << "Podaj czesc urojona: \n";
	in >> c1.im;
	return in;
}

std::ostream & operator<<(std::ostream &os, const Complex & c1)
{
	os << "(" << c1.re << ", " << c1.im << "i)" << std::endl;
	return os;
}

void r11zad7()
{
	Complex a(3.0, 4.0);
	Complex c;
	std::cout << "Podaj liczbe zespolona, k konczy: \n";
	while (cin >> c)
	{
		cout << "c to " << c << endl;
		cout << "sprzezona z c to " << -c << endl;
		cout << "a to " << a << endl;
		cout << "a+c = " << a + c << endl;
		cout << "a - c = " << a - c << endl;
		cout << "a*c = " << a * c << endl;
		cout << "2c = " << 2 * c << endl;
		std::cout << "Podaj liczbe zespolona, k konczy: \n";
	}
}
