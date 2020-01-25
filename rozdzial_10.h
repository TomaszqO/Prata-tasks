#pragma once
#ifndef ROZDZIAL_10_H
#define ROZDZIAL_10_H
//zad1
class Rachunek {
	std::string nazwisko;
	std::string numer;
	int saldo;
public:
	Rachunek();
	//Rachunek(std::string naz, char *im, std::string nr, int sal);
	Rachunek(std::string naz, std::string nr, int sal);
	~Rachunek();
	void show() const;
	void depo(int dep);
	void wydaj(int wyd);
};
//zad2
class Person {
	static const int LIMIT = 256;
	std::string lname;
	char fname[LIMIT];
public:
	Person() { lname = "", fname[0] = '\0'; }
	Person(const std::string &ln, const char* fn = "HejTy");
	void show() const;
	void Formalshow() const;
};
//zad3
class Golf_r10 {
	static const int Len = 10;
	char fullname[Len];
	int handicap;
public:
	Golf_r10() { fullname[0] = '\0', handicap = 0; }
	Golf_r10(const char * na, int hand);
	void setgolf();
};
//zad4
namespace SALES_r10 {
	const int QUARTERS = 4;
	class Sales {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	public:
		Sales();
		Sales(double[], int n);
		void setSales(Sales &);
		void showSales(const Sales &s);
	};
}
//zad5
struct customer {
	char fullname[35];
	double payment;
};
typedef customer Item;
class Stos {
	enum {MAX = 10};
	//static const int max = 20;
	enum { payment = 0 };
	Item it[MAX];
	int top;
public:
	Stos();
	bool put(const Item &it_);
	bool erase(Item & it_);
	bool is_empty()const;
	bool is_full() const;
};
//zad6
class Move {
	double x, y;
public:
	Move(double a = 0, double b = 0);
	Move add(const Move &m);
	void show()const;
	void reset(double a = 0, double b = 0);
};
//zad7
class Plorg {
	static const int n = 20;
	char imie[n];
	int coeff;
public:
	Plorg(const char im[] = "Plorga", int c = 30);
	void change(int c);
	void show() const;
};
#endif // !ROZDZIAL_10_h
