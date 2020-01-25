#include "stdafx.h"

void setgolf(golf_r9 &g, const char * name, int hc) {
	g.handicap = hc;
	int i;
	for (i = 0; i < Len && *name; i++) {
		g.fullname[i] = *name;
		name++;
	}
	while (i++ < Len)
		g.fullname[i] = '\0';
}
void setgolf(golf_r9 &g) {
	std::cout << "Podaj imie:...\n";
	std::cin.getline(g.fullname, Len);
	if (std::cin.fail()) {//jesli blad w cin!
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	std::cout << "podaj handicap:...\n";
	while (!(std::cin >> g.handicap)) {
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
		std::cout << "Podaj handicap:...\n";
	}
	std::cin.clear();// jesli po liczbie wczytano jakies bzdury
	while (std::cin.get() != '\n')
		continue;
}
void handicap(golf_r9 &g, int hc) {
	g.handicap = hc;
}
void showgolf(const golf_r9 &g) {
	std::cout << " Gracz: " << g.fullname << std::endl;
	std::cout << " handicap " << g.handicap << std::endl;
}
//zad4
void SALES_r9::setSales(Sales &s, const double ar[], int n) {
	double min, max, avg = 0;
	if (n < QUARTERS) {
		min = ar[0];
		max = ar[0];
		for (int i = 0; i < n; i++) {
			s.sales[i] = ar[i];
			avg += ar[i];
			if (ar[i] > max) max = ar[i];
			if (ar[i] < min) min = ar[i];
		}
		for (int i = n; i < QUARTERS; i++) {
			s.sales[i] = 0;
		}
		s.average = avg / QUARTERS;
		s.max = max;
		s.min = min;
	}
	else if (QUARTERS <= n) {
		min = ar[0];
		max = ar[0];
		for (int i = 0; i < QUARTERS; i++){
			s.sales[i] = ar[i];
			avg += ar[i];
			if (ar[i] > max) max = ar[i];
			if (ar[i] < min) min = ar[i];
			}
		s.average = avg / QUARTERS;
		s.max = max;
		s.min = min;
	}
}
void SALES_r9::setSales(Sales &s) {
	int i = 0;
	while (i < QUARTERS) {
		std::cout << "podaj element nr : " << i+1 << std::endl;
		while (!(std::cin >> s.sales[i])) {
			if (std::cin.fail()) { // jesli cin ma bit bledu
				std::cin.clear();
				while (std::cin.get() != '\n')
					continue;
			}
		std::cout << "podaj element nr: " << i+1 << std::endl;
			}
		while (std::cin.get() != '\n') continue;//wczytano liczbe, ale ze smieciami po niej
		i++;
	}
	double min, max, avg=0;
	min = s.sales[0];
	max = s.sales[0];
	for (int i = 0; i < QUARTERS; i++) {
			avg += s.sales[i];
			if (s.sales[i] > max) max = s.sales[i];
			if (s.sales[i] < min) min = s.sales[i];
	}
	s.max = max;
	s.min = min;
	s.average = avg / QUARTERS;
}
void SALES_r9::showSales(const Sales &s) {
	std::cout << "Srednia, wartosc maksymalna, wartosc minimalna: \n";
	std::cout << s.average << "\t" << s.max << "\t" << s.min << std::endl;
}
// 