#pragma once
#ifndef rozdzial8_h
#define rozdzial8_h
#include <iostream>
void r11zad7();

class Complex
{
	double re;
	double im;
public:
	Complex() { re = 0; im = 0; }
	Complex(double x, double y) { re = x; im = y; }
	~Complex() {}
	Complex operator+(const Complex & c1) const;
	Complex operator-(const Complex & c1) const;
	Complex operator-() const ;
	Complex operator*(const Complex & c1) const; //sprobuj z szablonem i specjalizacja dla obiektu Complex
	Complex operator*(const double& n) const;
	friend Complex operator*(const double& n, const Complex & c1);
	friend std::istream & operator>>(std::istream & in, Complex & c1);
	friend std::ostream & operator<<(std::ostream & out, const Complex & c1);
};




#endif