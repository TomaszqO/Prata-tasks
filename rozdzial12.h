#pragma once
#ifndef rozdzial12_h
#define rozdzial12_h
#include <iostream>
void r12zad1();

class Cow
{
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char* ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const;
};


#endif