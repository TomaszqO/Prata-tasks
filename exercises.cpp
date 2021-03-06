// exercises.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include<algorithm>
#include <cstring>
#include<cctype>
#include <sstream> 
#include <string>
#include <set>
//#pragma warning(disable : 4996) //usuwanie ostrzezenia w pliku

using namespace std;
string AlphabetSoup(string & s);
string longest(string & s);
string replace(string & s);

bool is_vowel(char a);
string vowelSquare(const string  str[], int n);

string closestEnemy(const string str[], int n);

string QuestionsMarks(string str);

string equivalentKeypress(string str[]);

int KaprekarConstant(int m);
int main()
{

		//test r10 zad 7
	/*
		Plorg p1("Tomislav asdas add a");
		p1.show();
		p1.change(30);
		p1.show();
		*/
		//doors();
		//r12zad1();


	///
		//string tab[] = { "Tadeu", "Steoi", "zlouy", "maroe"};
		//cout << vowelSquare(tab, sizeof(tab) / sizeof(*tab));
	///
	//string str[]{ "0000", "2010", "0000", "2002" };
	//cout << closestEnemy(str, 4) << endl;
	///
	//string str = "acc?7??sss?3rr1??????5";
	//string str =  "arrb6???4xxbl5???eee5";
	//cout << QuestionsMarks(str) << endl;
	///
	//string temp = "T,a,d,e,u,s,z,S,o,n,d,a,-B";
	//string temp1 = "T,a,d,e,u,s,z,S,o,n,d";
	//string ar[] = { temp, temp1 };
	//cout << equivalentKeypress(ar) << endl;
	///
	//cout << KaprekarConstant(9998) << endl;

	///

	std::cin.get();
    return 0;
}
//Longest word- determine the longest word in a string.
string longest(string & s)
{
	size_t i = 0;
	string lo="";
	string temp="";
	while (i < s.size())
	{
		while (isalpha(s[i]))
		{
			temp.append(s,i,1);
			i++;
		}
		if (temp.size() > lo.size()) 
		{
			lo = temp;
		}
		temp.clear();
		i++;
	}
	return lo;
}

// Replace every letter in the string with the letter
//following it in the alphabet (ie. c becomes d, z becomes a).
//	Then capitalize every vowel in this new string (a, e, i, o, u)
//	and finally return this modified string. 
string replace(string & s)
{
	size_t i = 0;
	while (i < s.length())
	{
		if (isalpha(s[i]))
		{
			if ((s[i] >= 'a' && s[i] < 'z') || (s[i] >= 'A' && s[i] < 'Z'))
			{
				s[i] = char((int)s[i] + 1);
				if (s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u')
					s[i] = toupper(s[i]);
			}
			else
				s[i] = 'A';
		}
		i++;
	}
	return s;
}

int sum(int n)
{
	if
		(n == 1) return 1;
	else
		return n+sum(n - 1);
}

//Have the function AlphabetSoup(str) take the str string parameter being passed 
//and return the string with the letters in alphabetical order(ie.hello becomes ehllo).
//Assume numbers and punctuation symbols will not be included in the string.
string AlphabetSoup(string & s)
{
	char temp;
	size_t i1;
	for (size_t i = 0; i < s.size()-1; i++)
	{
		i1 = i;
		for (size_t j = i + 1; j < s.size(); j++)
		{
			if (int(s[j]) < int(s[i1]))
				i1 = j;
		}
		temp = s[i];
		s[i] = s[i1];
	    s[i1] = temp;
	}
	return s;
}

//Have the function CorrectPath(str) read the str parameter being passed,
//which will represent the movements made in a 5x5 grid of cells starting from the top left position.
//The characters in the input string will be entirely composed of : r, l, u, d, ? .
//Your goal is to determine what characters the question marks should be in order 
//for a path to be created to go from the top left of the grid all the way to
//the bottom right without touching previously travelled on cells in the grid.




///
/*
Have the function VowelSquare(strArr) take the strArr parameter being passed 
which will be a 2D matrix of some arbitrary size filled with letters from the alphabet, 
and determine if a 2x2 square composed entirely of vowels exists in the matrix.
For example : strArr is["abcd", "eikr", "oufj"] then this matrix looks like the following :
a b c d
e i k r
o u f j
Within this matrix there is a 2x2 square of vowels starting in the second row and first column,
namely, ei, ou. If a 2x2 square of vowels is found your program should return the top-left position 
(row-column) of the square, so for this example your program should return 1-0. If no 2x2 
square of vowels exists, then return the string not found. If there are multiple squares of vowels, 
return the one that is at the most top-left position in the whole matrix. The input matrix will at 
least be of size 2x2.
*/
bool is_vowel(char a)
{
	return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y') ? true :  false;
}


string vowelSquare(const string  str[], int n)
{
	string ret;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < str[i].size() - 1; j++)
		{
			if (is_vowel(str[i][j]))
			{
				if (is_vowel(str[i][j + 1]) && is_vowel(str[i + 1][j]) && is_vowel(str[i + 1][j]))
				{
					ret+=(to_string(i));
					ret+=",";
					ret+=to_string(j);
					return ret;
				}
			}
		}
	}
	return "Not found";
}
/*
Have the function ClosestEnemyII(strArr) read the matrix of numbers stored in strArr
which will be a 2D matrix that contains only the integers 1, 0, or 2.
Then from the position in the matrix where a 1 is, return the number of spaces either left,
right, down, or up you must move to reach an enemy which is represented by a 2. 
You are able to wrap around one side of the matrix to the other as well.
*/
string closestEnemy(const string str[], int n)
{
	pair <int, int> enemy;
	pair <int, int> object;
	vector<pair<int, int>> enemies;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < str[i].size(); j++)
		{
			if (str[i][j] == '0') continue;
			else if (str[i][j] == '2')
			{
				enemy.first = i;
				enemy.second = j;
				enemies.push_back(enemy);
			}
			else if (str[i][j] == '1')
			{
				object.first = i;
				object.second = j;
			}
		}
	}
	int d = n;
	int dx, dy;

	for (int i = 0; i < enemies.size(); i++)
	{
		if (abs(enemies[i].first - object.first) <= abs(enemies[i].first - object.first + n) && abs(enemies[i].first - object.first) <= abs(enemies[i].first - object.first - n))
			dy = abs(enemies[i].first - object.first);
		else if (abs(enemies[i].first - object.first + n) <= abs(enemies[i].first - object.first) && abs(enemies[i].first - object.first + n) <= abs(enemies[i].first - object.first - n))
			dy = abs(enemies[i].first - object.first + n);
		else
			dy = abs(enemies[i].first - object.first - n);

		if ((abs(enemies[i].second - object.second) <= abs(enemies[i].second - object.second + n)) && (abs(enemies[i].second - object.second) <= abs(enemies[i].second - object.second - n)))
			dx = abs(enemies[i].second - object.second);
		else if (abs(enemies[i].second - object.second + n) <= abs(enemies[i].second - object.second) && abs(enemies[i].second - object.second + n) <= abs(enemies[i].second - object.second - n))
			dx = abs(enemies[i].second - object.second + n);
		else
			dx = abs(enemies[i].second - object.second - n);

		if (dx + dy < d) d = dx + dy;

	}
	return to_string(d);
}

/*
Have the function QuestionsMarks(str) take the str string parameter, 
which will contain single digit numbers, letters, and question marks, 
and check if there are exactly 3 question marks between every pair of two numbers 
that add up to 10. If so, then your program should return the string true,
otherwise it should return the string false. If there aren't any two numbers that add up to 10 
in the string, then your program should return false as well.
*/
string QuestionsMarks(string str)
{
	string str1 = "false";
	int count = 0;
	int l1 = -1 , l2 = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			l1 = stoi(str.substr(i,1));
			if ((l1 + l2) == 10)
			{
				if (count == 3)
					str1 = "true";
				else
					return "false";
			}
			l2 = l1;
			count = 0;
		}
		else if (l1 != -1 && str[i] == '?')
			count++;
	}
	return str1;
}

/*
Equivalent Keypresses
Have the function EquivalentKeypresses(strArr) read the array of strings stored in strArr
which will contain 2 strings representing two comma separated lists of keypresses. 
Your goal is to return the string true if the keypresses produce the same printable string 
and the string false if they do not. A keypress can be either a printable character or
a backspace represented by -B. You can produce a printable string from such a string of 
keypresses by having backspaces erase one preceding character.

For example: if strArr contains ["a,b,c,d", "a,b,c,c,-B,d"] the output should 
return true because those keypresses produce the same printable string. 
The array given will not be empty. The keypresses will only contain letters from the alphabet
and backspaces.
*/
string equivalentKeypress(string str[])
{
	//string s1 = "";
	//string s2 = "";
	string s[2]{ "","" };
	size_t i , f;
	for (int it = 0; it < 2; it++)
	{
		i = 0;
		while (i < str[it].size())
		{
			f = str[it].find(",", i);
			if (f != string::npos)
			{
				if (str[it].substr(i, f - i) != "-B")
				{
					s[it].append(str[it], i, f - i);
					i = f + 1;
				}
				else if (!s[it].empty())
				{
					s[it].pop_back();
					i = f + 1;
				}
			}
			else
			{
				if (str[it].substr(i, f - i) != "-B")
				{
					s[it].append(str[it], i, str[it].size() - i);
					i = str[it].size();
				}
				else if (!s[it].empty())
				{
					s[it].pop_back();
					i = str[it].size();
				}
			}
		}
	}



	//size_t  f = s1.find_first_not_of(s2);
		//(f != string::npos) ? s2 = "true": s2 = "false";

	return (s[0].compare(s[1])) ? "false" : "true";
}
///
/*
Kaprekars Constant
Have the function KaprekarsConstant(num) take the num parameter being passed which will be
a 4 - digit number with at least two distinct digits.
Arrange the digits in descending order and in ascending order
(adding zeroes to fit it to a 4-digit number), and subtract the smaller number from the bigger 
number. Then repeat the previous step. Performing this routine will always cause you to reach
a fixed number: 6174. Then performing the routine on 6174 will always give you 6174 (7641 - 1467
= 6174). Your program should return the number of times this routine must be performed until 
6174 is reached.
*/
int KaprekarConstant(int m)
{
	int licz=0, n;
	if (m < 1000 || m > 9998 || m == 1111 || m == 2222 || m == 3333 || m == 4444 || m == 5555 || m == 6666 || m == 7777 || m == 8888)
	{
		cout << "zal liczba. wyjscie z programu.\n";
		return 0;
	}
	vector<int> v1;
	while (m != 6174)
	{
		for (int i = 0; i < 4; i++)
		{
			v1.push_back(m % 10);
			m /= 10;
		}
		sort(v1.begin(), v1.end());
		m = 1000 * v1[0] + 100 * v1[1] + 10 * v1[2] + v1[3];
		n = 1000 * v1[3] + 100 * v1[2] + 10 * v1[1] + v1[0];
		m = n - m;
		v1.erase(v1.begin(), v1.begin()+4);
		licz++;
	}
	return licz;
}

///
/*
Maximal Square
Have the function MaximalSquare(strArr) take the strArr parameter being passed which
will be a 2D matrix of 0 and 1's, and determine the area of the largest square submatrix that 
contains all 1's.A square submatrix is one of equal width and height, and your program should 
return the area of the largest submatrix that contains only 1's. 
*/
int  MaximalSquare(string ar[])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < ar[i].size(); j++)
		{
			if()

		}
	}
}