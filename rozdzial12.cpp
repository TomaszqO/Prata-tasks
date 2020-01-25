#include "stdafx.h"

using namespace std;
Cow::Cow()
{
	weight = 0.0;
	hobby = new char[1];
	hobby[0] = '\0';
	strcpy_s(name, "Tadeusz Mazowiecki");
}

Cow::Cow(const char * nm, const char* ho, double wt)
{
	weight = wt;
	strcpy_s(name, nm);
	hobby = new char[strlen(ho)+1];
	int i = 0;
	while (ho[i])
	{
		hobby[i] = ho[i];
		i++;
	}
	hobby[strlen(ho)] = '\0';
}
Cow::Cow(const Cow & c)
{
	weight = c.weight;
	strcpy_s(name, c.name);
	hobby = new char[strlen(c.hobby)+1];
	int i = 0;
	while (c.hobby[i])
	{
		hobby[i] = c.hobby[i];
		i++;
	}
	hobby[strlen(c.hobby)] = '\0';
}
void Cow::ShowCow() const
{
	cout << "imie: " << (*this).name << endl;
	cout << "hobby: " << hobby << endl;
	cout << "masa: " << weight << endl;
}

Cow & Cow::operator=(const Cow & c)
{
	if (&c == this) return *this;
	weight = c.weight;
	strcpy_s(name, c.name);
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	int i = 0;
	while (c.hobby[i])
	{
		hobby[i] = c.hobby[i];
		i++;
	}
	hobby[strlen(c.hobby)] = '\0';
}

Cow::~Cow()
{
	delete[] hobby;
}
void r12zad1()
{
	Cow c1;
	Cow c2("Jakubek", "gra w szachy", 840.0);
	Cow c3;
	cout << "obiekt c3 przed przypisaniem : \n";
	c3.ShowCow();
	c3 = c2;
	cout << "obiekt c3 po przypisaniu: \n";
	c3.ShowCow();
	
}