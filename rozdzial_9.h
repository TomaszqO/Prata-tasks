#pragma once
#ifndef ROZDZIAL_9_H
#define ROZDZIAL_9_H
//zad1
const int Len = 4;
struct golf_r9 {
	char fullname[Len];
	int handicap;
};
void setgolf(golf_r9 &g, const char * name, int hc);
void setgolf(golf_r9 &g);
void handicap(golf_r9 &g, int hc);
void showgolf(const golf_r9 &g);
//zad 4
namespace SALES_r9 {
	const int QUARTERS = 4;
	struct Sales {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};
	void setSales(Sales &s, const double ar[], int n);
	void setSales(Sales &s);
	void showSales(const Sales &s);
}
#endif