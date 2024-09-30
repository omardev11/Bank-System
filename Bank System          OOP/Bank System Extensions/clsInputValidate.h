#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;
//template <class T>
class clsInputValidate
{
	static bool IsEqual(clsDate date1, clsDate date2)
	{
		return (date1.Year == date2.Year && date1.Month == date2.Month && date1.Day == date2.Day);
	}

public:

	static bool IsNumberBetween(short number, short from, short to)
	{

		if (number >= from && number <= to)
		{
			return true;
		}
		else
		{
			return false;

		}


	}
	static bool IsNumberBetween(int number, int from, int to)
	{
		if (number >= from && number <= to)
		{
			return true;
		}
		else
		{
			return false;

		}
	}
	static bool IsNumberBetween(float num, float from, float to)
	{
		if (num >= from && num <= to)
		{
			return true;
		}
		else
		{
			return false;

		}
	}
	static bool IsNumberBetween(double num, double from, double to)
	{
		if (num >= from && num <= to)
		{
			return true;
		}
		else
		{
			return false;

		}
	}

	static bool IsDateBetween(clsDate date,clsDate from,clsDate to)
	{

		if ( (clsDate::IsDate1AfterDate2(date,from) || clsDate::IsDate1EqualDate2(date,from))
			&& (clsDate::IsDate1BeforeDate2(date, to) || clsDate::IsDate1EqualDate2(date, to))  )
		{
			return true;
		}
		if ((clsDate::IsDate1AfterDate2(date, to) || clsDate::IsDate1EqualDate2(date, to))
			&& (clsDate::IsDate1BeforeDate2(date, from) || clsDate::IsDate1EqualDate2(date, from)))
		{
			return true;
		}
		return false;




	
	}

	static int ReadIntNumber(string Messege)
	{
		int x;
		cin >> x;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Messege << endl;
			cin >> x;
		}
		
		return x;

	}
	static int ReadShortNumberBetween(short from, short to, string messege)
	{
		short y;
		y = ReadIntNumber(messege);



		while (!IsNumberBetween(y,from,to))
		{
			cout << messege;
			y = ReadIntNumber(messege);
		}
		return y;
	}

	static double ReadDoubleNumber(string Messege)
	{
		double x;
		cin >> x;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Messege << endl;
			cin >> x;
		}

		return x;

	}

	static int ReadDoubleNumberBetween(double from, double to, string messege)
	{
		double y;
		y = ReadDoubleNumber(messege);
		while (!IsNumberBetween(y,from,to))
		{
			cout << messege;
			cin >> y;
		}
		return y;
	}


	static bool IsValidDate(clsDate date)
	{
		return clsDate::IsValidDate(date);
	}

	static string ReadString()
	{
		string Name;
		getline(cin >> ws, Name);
		return Name;
	}
	static bool AreYouSure(string messege)
	{
		char answer;
		cout << messege << " ";
		cin >> answer;
		while (answer == 'y' || answer == 'Y')
		{
			return true;
		}
		return false;
	}
 
};

