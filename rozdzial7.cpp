#include "stdafx.h"
//#include "rozdzial7.h"

int fill_array(double tab[], const int N)
{
	int i = 0;
	while (i < N)
	{
		std::cout << "Podaj liczbe nr " << i + 1 << std::endl;
		while (!(std::cin >> tab[i]))
		{
			std::cin.clear();
				while (std::cin.get() != '\n') continue;
			std::cout << "Podaj liczbe nr " << i + 1 << std::endl;
		}
		//while (std::cin.get() != '\n') continue;
		i++;
	}
	return i;
}
void show(const double tab[], const int N)
{
	int i = 0;
	while (i<N)
	{
		std::cout << tab[i] << std::endl;
		i++;
	}
	std::cout << "Koniec wyswietlania\n";
	return;
}
void reverse(double tab[], const int N)
{
	double temp;
	for (int i = 0, j = N - 1; i < j; i++, j--)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
	}
}

void test6()
{
	//r7zad6
	double tab[5];
	fill_array(tab, 5);
	show(tab, 5);
	reverse(tab, 5);
	show(tab, 5);
}
/// zad 8
const int Seasons = 4;
const char * Snames[Seasons] = { "Wiosna", "Lato", "Jesien", "zima" };

void zad8()
{
	double wydatki[Seasons];
	fill8(wydatki, Seasons);
	show8(wydatki, Seasons);
}

void fill8(double tab[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		std::cout << "Podaj wydatki za " << Snames[i];
		while (! (std::cin >> tab[i]))
		{
			std::cin.clear();
			while (std::cin.get() != '\0') continue;
			std::cout << "Podaj wydatki za " << Snames[i];
		}
	}
}
void show8(const double tab[], const int N)
{
	double tot = 0.0;
	for (int i = 0; i < N; i++)
	{
		std::cout << "Suma za : " << Snames[i] << " : " << tab[i] << std::endl;
		tot += tab[i];
	}
	std::cout << "Calkowicie : " <<tot << std::endl;
	return;
}