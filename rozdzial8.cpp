#include "stdafx.h"
#include <cstring>
///zadanie 5
template <typename T>
T max5(T tab[])
{
	T max = tab[0];
	for (int i = 1; i < 5; i++)
	{
		if (tab[i] > max) max = tab[i];
	}
	return max;
}

void zad5()
{
	int t1[5]{ 1,3,4,5,6 };
	std::cout << "maksymalna wartosc z t1: " << max5(t1) << std::endl;
	double t2[]{ 0,98,9.3,45.0,32.4 };
	std::cout << "maksymalna wartosc z t2: " << max5(t2) << std::endl;
}
///zad 6 
template <typename T>
T maxn(T tab[], const int N)
{
	std::cout << "konkretyzacja niejawna...";
	T max = tab[0];
	for (int i = 1; i < N; i++)
	{
		if (tab[i] > max) max = tab[i];
	}
	return max;
}

template <> char*  maxn(char* tab[], const int N)
{
	std::cout << "weszlo do specjalizacji...\n";
	char* max = tab[0];
	
	for (int i = 1; i < N; i++)
	{
		if (std::strlen(tab[i]) > std::strlen(max)) max = tab[i];
	}
	return max;
}


void zad6()
{
	int t1[]{ 4,6,2,90,8 };
	//std::cout<<maxn(t1, 5)<<std::endl;
	double t2[]{ 54,2,12,45 };
	//std::cout<<maxn(t2, 4)<<std::endl;
	char nap1[] = "Pizdoslwa"; 
	char nap2[] = "Saska Kepa";
	char nap3[] = "Polska gola";
	char nap4[] = "Parowki z kapusta";
	char nap5[] = "C++;";
	char *napis[] = { nap1, nap2, nap3, nap4, nap5 };
	std::cout << maxn(napis, 5);
}


///zad 7

template <typename T>
T sum(T tab[], int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += tab[i];
	}
	return sum;
}


	template <typename T>
	T sum(T *tab[], int n)
	{
		std::cout << "szablon 2\n";
		T sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += *tab[i];
		}
		return sum;
	}

	void zad7()
	{
		int a1[5] { 5,10,34,35,6 };
		sum(a1, 5);
		struct debts d1[3] 
		{
			{"Tadziik", 450.0 },
			{"Lodzik", 7300.0},
			{"Basieniek", 831.5}
		};
		double *p[3];
		for (int j = 0; j < 3; j++)
		{
			p[j] = &d1[j].amount;
		}
		std::cout <<"suma zadluzenia: "<< sum(p, 3) << std::endl;
	}