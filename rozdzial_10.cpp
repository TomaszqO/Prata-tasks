#include "stdafx.h"
using namespace std;
//zad 1
Rachunek::Rachunek() {
	cout << "Witam, tu konstruktor domyslny!\n";
	this->nazwisko = "Piotrowski";
	this->numer = "9990983092";
	saldo = 0;
	}

Rachunek::Rachunek(std::string naz, std::string nr, int sal) {
	nazwisko = naz;
	numer = nr;
	saldo = sal;
}
Rachunek::~Rachunek() {
	cout << "Destruktor obiektu: " << this->nazwisko;
}
void Rachunek::show() const {
	cout << "saldo nazwisko numer konta \n";
	cout <<  saldo << endl;
	cout<< nazwisko << endl;
	cout << numer << endl;
}
void Rachunek::depo(int dep=0) {
	saldo += dep;
}
void Rachunek::wydaj(int wyd = 0) {
	saldo -= wyd;
}
//zad2
Person::Person(const std::string &ln, const char* fn ) {
	lname = ln;
	int i;
	for ( i = 0; i < LIMIT && *fn; i++) {
	    fname[i] = *fn;
		cout << *fn <<" w iteracji: "<<i+1<< endl;
		fn++;//uzupelnie pierwszych kilka znakow, reszte trzeba wypelnic pustymi znakami!
	}
	while (i<LIMIT) {
		fname[i] = '\0';
		i++;
	}
}
void Person::show() const {
	cout << lname << ", " << fname << endl;
}
void Person::Formalshow() const {
	//cout << fname << ", " << lname << endl;
	cout << lname << endl;
}
//zad3
Golf_r10::Golf_r10(const char * na, int hand){
	handicap = hand;
	int i;
	for (i = 0; i < Len && na[i]; i++) {
		fullname[i] = na[i];
	}
	while (i < Len) {
		fullname[i] = '\0';
		i++;
	}
}
void Golf_r10::setgolf() {
	char na[Len];
	int hand;
	cout << "podaj imie: \n";
	while (!(cin.getline(na, Len))) {
		if (cin.fail()) {
			cin.clear();
			while (cin.get() != '\n') continue;
		}
		cout << "podaj imie: \n";
	}
	cout << "podaj handicap: \n";
	while (!(cin >> hand)) {
		cin.clear();
		while (cin.get() != '\n') continue;
		cout << " podaje handicap: \n";
	}
		while (cin.get() != '\n') continue;
	
	Golf_r10 g1(na,hand);
	*this = g1;
	return;
}
//zad4
using namespace SALES_r10;
	Sales::Sales() {
		for (int i = 0; i < QUARTERS; i++) { sales[i] = 0.0; }
		average = 0.0; min = 0.0; max = 0.0;
	}
	Sales::Sales(double ar[], int n) {
		double avg = 0;
		if (n < QUARTERS) {
			min = ar[0];
			max = ar[0];
			for (int i = 0; i < n; i++) {
				sales[i] = ar[i];
				avg += ar[i];
				if (ar[i] > max) max = ar[i];
				if (ar[i] < min) min = ar[i];
			}
			for (int i = n; i < QUARTERS; i++) {
				sales[i] = 0;
			}
			average = avg / QUARTERS;
			max = max;
			min = min;
		}
		else if (QUARTERS <= n) {
			min = ar[0];
			max = ar[0];
			for (int i = 0; i < QUARTERS; i++) {
				sales[i] = ar[i];
				avg += ar[i];
				if (ar[i] > max) max = ar[i];
				if (ar[i] < min) min = ar[i];
			}
			average = avg / QUARTERS;

		}
	}
	/*
	void Sales::setSales() {
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
	this->average= s.average;
	this->max = s.max;
	this->min = s.min;
	this->sales = s.sales;
	}
	*/
//zad5
Stos::Stos() {
	top = 0;
	//payment = 0;
}
bool Stos::put(const Item &it_) {
	if (top < MAX) {
		it[top] = it_;//na topie nic nie ma dotychczas;
		top++;
		return true;
	}
	else
		return false;
}
bool Stos::erase(Item & it_) {
	if (top > 0) {
		top--;
		it_ = it[top];
		//payment = it[top].payment;
		//cout << " total value of payments: " << payment << endl;
		return true;
	}
	else return false;
}
bool Stos::is_empty()const {
	return top == 0;
}
bool Stos::is_full() const {
	return top == MAX;
}
//zad6 class Move {
Move::Move(double a, double b) {
	x = a;
	y = b;
}
Move Move::add(const Move&m) {
	Move m_ = (this->x + m.x, (*this).y + m.y);
	return m_;
}
void Move::show() const {
	cout << x << "\t" << y << endl;
}
void Move::reset(double a, double b) {
	this->x = a; this->y = b;
}
//zad 7
Plorg::Plorg(const char im[], int c) {
	coeff = c;
	strcpy_s(imie, im);
}
void Plorg::change(int c) {
	this->coeff = c;
}
void Plorg::show()const {
	cout << imie << "\t" << coeff << endl;
}