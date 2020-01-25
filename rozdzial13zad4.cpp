#include "stdafx.h"

//char * brand;
//char style[50];
//int bottles;

Port::Port(const char * br, const char * st, int b)
{
	bottles = b;
	strncpy_s(style, st, 49);
	style[49] = '\0';
	size_t i = 0, i1 = strlen(br);
	brand = new char[i1+ 1];
	while (i < i1)
	{
		brand[i] = br[i];
		i++;
	}
	brand[i] = '\0';
}

Port::Port(const Port & p)
{
	bottles =p.bottles;
	strncpy_s(style, p.style, 49);
	style[49] = '\0';
	size_t i = 0;
	brand = new char[strlen(p.brand) + 1];
	while (i < strlen(p.brand))
	{
		brand[i] = p.brand[i];
		i++;
	}
	brand[strlen(p.brand)] = '\0';
}	
Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;
	bottles = p.bottles;
	strncpy_s(style, p.style, 49);
	style[49] = '\0';
	size_t i = 0;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	while (*p.brand)
	{
		brand[i] = p.brand[i];
		i++;
	}
	return *this;
}
Port & Port::operator+=(int b)
{
	bottles = bottles + b;
	return *this;
}
Port & Port::operator-=(int b)
{
	if (bottles - b >= 0)
	{
		bottles = bottles - b;
		return *this;
	}
	else 
	{
		bottles = 0;
		return *this;
	}
}
void Port::Show() const
{
	cout << "Marka: " << brand << endl;
	cout << "Rodzaj: " << style << endl;
	cout << "Butelek: " << bottles << endl;
}
ostream & operator<<(ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort() : Port()
{
	year = 1900;
	nickname = new char[10];
	nickname[0] = 'u';
}

VintagePort::VintagePort(const char * br, int b, const char * mn, int y) : Port(br, "Brak", b), year(y)
{
	nickname = new char[strlen(mn)+1];
	size_t i = 0;
	while (i < strlen(mn))
	{
		nickname[i] = mn[i];
		i++;
	}
	nickname[strlen(mn)] = '\0';
}
VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
	year = vp.year;
	delete[] nickname;
	size_t i1 = strlen(vp.nickname);
	nickname = new char[ i1+ 1];
	size_t i = 0;
	while (i < i1)
	{
		nickname[i] = vp.nickname[i];
		i++;
	}
	nickname[i1] = '\0';
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;

	Port::operator=(vp);
	year = vp.year;
	delete[] nickname;
	size_t i1 = strlen(vp.nickname);
	nickname = new char[i1 + 1];
	size_t i = 0;
	while (i < i1)
	{
		nickname[i] = vp.nickname[i];
		i++;
	}
	nickname[i1] = '\0';
	return *this;
}
void VintagePort::Show() const
{
	//(*this).Port::Show();
	Port::Show();
	cout << "rok winobrania: " << year << endl;
	cout << "przydomek: " << nickname << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
	os << (Port)vp;
	os << "\nRok: " << vp.year << endl;
	os << "Przydomek: " << vp.nickname << endl;
	return os;
}

void zad()
{
	Port p1("LasUvas", "Malaga", 190);
	VintagePort vp1("DelSol", 132, "Pedro Ximenez", 2006);
	vp1.Show();
	vp1 -= 3;
	vp1.Show();
	p1.Show();

	cout << "Funkcje zaprzyjaznione\n\n";
	operator<<(cout, vp1);
	operator<<(cout, p1);

	cout << "\n\nPolimorfizm: \n";
	Port * wsk1 = &vp1;
	wsk1->Show();
}
