#pragma once
#ifndef ROZDZIAL13_H
#define ROZDZIAL13_H
#include <iostream>

class Cd
{
	char performers[50];
	char label[20];
	int selection;
	double playtime;
public:
	Cd(char * s1, char * s2, int n, double x);
	Cd();
	Cd(const Cd & cd);
	virtual ~Cd();
	virtual void Report() const;
	Cd & operator=(const Cd & cd);
};
class Classic : public Cd
{
	char  track_title[50];
public:
	Classic();
	Classic(const Classic & cl);
	Classic(char * s1, char * s2, int n, double x, char * track);
	Classic(char * track, const Cd & cd);
	~Classic();
	Classic & operator=(const Classic & cl);
};

///zad2
class Cd2
{
	char * performers;
	char * label;
	int selection;
	double playtime;
public:
	Cd2(char * s1, char * s2, int n, double x);
	Cd2();
	Cd2(const Cd2 & cd);
	virtual ~Cd2();
	virtual void Report() const;
	Cd2 & operator=(const Cd2 & cd);
};
class Classic2 : public Cd2
{
	char  * track_title;
public:
	Classic2();
	Classic2(const Classic2 & cl);
	Classic2(char * s1, char * s2, int n, double x, char * track);
	Classic2(char * track, const Cd2 & cd);
	~Classic2();
	Classic2 & operator=(const Classic2 & cl);
};

#endif