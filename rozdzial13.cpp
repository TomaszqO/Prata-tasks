#include "stdafx.h"
#include <cstring>
using namespace std;

Cd::Cd(char * s1, char * s2, int n, double x)
{
	strncpy_s(performers, s1, 49);
	strncpy_s(label, s2, 19);
	selection = n;
	playtime = x;

}

Cd::Cd()
{
	selection = 0;
	playtime = 0.0;
	label[0] = '\0';
	performers[0] = '\0';
}
Cd::Cd(const Cd & cd)
{
	strncpy_s(performers, cd.performers, 49);
	strncpy_s(label, cd.label, 19);
	playtime = cd.playtime;
	selection = cd.selection;
}
Cd::~Cd()
{
}

void Cd::Report() const
{
	cout << "Performer: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Liczba utworow: " << selection << endl;
	cout << "Dlugosc plyty w minutach: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & cd)
{
	if (this == &cd) return *this;
	strncpy_s(performers, cd.performers, 49);
	strncpy_s(label, cd.label, 19);
	playtime = cd.playtime;
	selection = cd.selection;
	return *this;
}
Classic::Classic() : Cd()
{
	track_title[0] = '\0';
}
Classic::Classic(const Classic & cl) : Cd(cl)
{
	strncpy_s(track_title, cl.track_title, 49);
}
Classic::Classic(char * s1, char * s2, int n, double x, char * track) : Cd(s1, s2, n, x)
{
	strncpy_s(track_title, track, 49);
}
Classic::Classic(char * track, const Cd & cd) : Cd(cd)
{
	strncpy_s(track_title, track, 49);
}
Classic::~Classic()
{

}
Classic & Classic::operator=(const Classic & cl)
{
	if (this == &cl) return *this;
	Cd::operator=(cl);
	strncpy_s(track_title, cl.track_title, 49);
}

///zad2

Cd2::Cd2(char * s1, char * s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	int i = 0;
	while (i < strlen(s1))
	{
		performers[i] = *s1++;
		i++;
	}
	performers[i] = '\0';
	i = 0;
	label = new char[strlen(s2)+1];
	while (i<strlen(s2))
	{
		label[i] = *s2++;
		i++;
	}
	label[i] = '\0';
	selection = n;
	playtime = x;

}

Cd2::Cd2()
{
	selection = 0;
	playtime = 0.0;
	label = new char[1];
	label[0] = '\0';
	performers = new char[1];
	performers[0] = '\0';
}
Cd2::Cd2(const Cd2 & cd)
{
	performers = new char[strlen(cd.performers) + 1];
	int i = 0;
	while (i < strlen(cd.performers))
	{
		performers[i] = cd.performers[i];
		i++;
	}
	performers[i] = '\0';
	i = 0;
	label = new char[strlen(cd.label) + 1];
	while (i < strlen(cd.label))
	{
		label[i] = cd.label[i];
		i++;
	}
	label[i] = '\0';
	playtime = cd.playtime;
	selection = cd.selection;
}
Cd2::~Cd2()
{
	delete[] label;
	delete[] performers;
}

void Cd2::Report() const
{
	cout << "Performer: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Liczba utworow: " << selection << endl;
	cout << "Dlugosc plyty w minutach: " << playtime << endl;
}

Cd2 & Cd2::operator=(const Cd2 & cd)
{
	if (this == &cd) 
		return *this;
	delete [] label;
	label = new char[strlen(cd.label) + 1];
	size_t i = 0;
	while (i < strlen(cd.label))
	{
		label[i] = cd.label[i];
		i++;
	}
	delete[] performers;
	performers = new char[strlen(cd.performers) + 1];
	i = 0;
	while (i < strlen(cd.performers))
	{
		performers[i] = cd.performers[i];
		i++;
	}
	playtime = cd.playtime;
	selection = cd.selection;
	return *this;
}
Classic2::Classic2() : Cd2()
{
	track_title = new char[1];
	track_title[0] = '\0';
}
Classic2::Classic2(const Classic2 & cl) : Cd2(cl)
{
	track_title = new char[strlen(cl.track_title)+1];
	size_t i = 0;
	while (i < strlen(cl.track_title))
	{
		track_title[i] = cl.track_title[i];
		i++;
	}
}
Classic2::Classic2(char * s1, char * s2, int n, double x, char * track) : Cd2(s1, s2, n, x)
{
	track_title = new char[strlen(track) + 1];
	size_t i = 0;
	while (i < strlen(track))
	{
		track_title[i] = track[i];
		i++;
	}
}
Classic2::Classic2(char * track, const Cd2 & cd) : Cd2(cd)
{
	track_title = new char[strlen(track) + 1];
	size_t i = 0;
	while (i < strlen(track))
	{
		track_title[i] = track[i];
		i++;
	}
}
Classic2::~Classic2()
{
	delete[] track_title;
}
Classic2 & Classic2::operator=(const Classic2 & cl)
{
	if (this == &cl) 
		return *this;
	Cd2::operator=(cl);
	delete[] track_title;	
	track_title = new char[strlen(cl.track_title) + 1];
	size_t i = 0;
	while (i < strlen(cl.track_title))
	{
		track_title[i] = cl.track_title[i];
		i++;
	}
}

