#pragma once
#ifndef  rozdz13z4
#define  rozdz13z4
#include <iostream>

using namespace std;

class Port
{
	char * brand;
	char style[50];
	int bottles;
public:
	Port(const char * br = "Brak", const char * st = "Brak", int b = 0);
	Port(const Port & p);
	virtual ~Port() { delete[] brand; }
	Port & operator=(const Port & p);
	Port & operator+=(int b);
	Port & operator-=(int b);
	int BottleCount() const { return bottles;}
	virtual void Show() const;
	friend ostream & operator<<(ostream & os, const Port & p);
};

class VintagePort : public Port
{
	char * nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char * br, int b, const char * mn, int y);
	VintagePort(const VintagePort & vp);
	~VintagePort() { delete[] nickname;}
	VintagePort & operator=(const VintagePort & vp);
	void Show() const;
	friend ostream & operator<<(ostream & os, const VintagePort & vp);
};
void zad();
#endif // ! rozdz13z4
