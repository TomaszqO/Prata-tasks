#pragma once

#ifndef ROZDZIAL10CW7_H
#define ROZDZIAL10CW7_H
#include <iostream>
#include <cstring>
const int N = 5;
class Plorg
{
	char imie[N];
	int coeff;
	
public:
	//Plorg() { imie = "Plorga"; coeff = 50;}

	Plorg(const char *i = "Plorga", int c = 50) 
		{
		std::cout << "Konstruktor domyslyn\n";
		coeff = c; 

		//strcpy_s(imie, i);
		int li =0;
		while (*i && li<N-1) {
			imie[li++] = *i++;
		}
		imie[li] = '\0';
		}
		~Plorg() { std::cout << "Koniec obiektu  " <<std::endl; }
		void show() const { std::cout << "Imie: " << imie << std::endl; std::cout << "Wspolczynnik: " << coeff << std::endl; }
		void change(int c)  { coeff = c; }

};

#endif // !ROZDZIAL10CW7_H

