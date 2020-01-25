#pragma once
#ifndef rozdz8_h
#define rozdz8_h
template <typename T>
T max5(T tab[]);

void zad5();

///zad 6
template <typename T>
T maxn(T tab[], const int N);

template <> char*  maxn(char *tab[] , const int N);

void zad6();

/// zad 7 
struct debts
{
	char name[50];
	double amount;
};
template <typename T>
T sum(T tab[], int n);

template <typename T>
T sum(T *tab[], int n);

void zad7();


#endif