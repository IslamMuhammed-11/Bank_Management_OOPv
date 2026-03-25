#pragma once
#include<iostream>
#include <string>
#include"clsDate.h"
using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(short NumberToCheck, short From, short To) {
		return (NumberToCheck >= From && NumberToCheck <= To);
	}

	static bool IsNumberBetween(int NumberToCheck, int From, int To) {

		return (NumberToCheck >= From && NumberToCheck <= To);
	}

	static bool IsNumberBetween(float NumberToCheck, float From, float To) {
		return (NumberToCheck >= From && NumberToCheck <= To);
	}

	static bool IsNumberBetween(double NumberToCheck, double From, double To) {
		return (NumberToCheck >= From && NumberToCheck <= To);
	}

	static int ReadIntNumber(string InvalidMessage = "Invalid Input , Please Try Again..") {
		int x;

		while (!(cin >> x))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << InvalidMessage << endl;

			cin >> x;
		}

		return x;
	}

	static int ReadIntNumberBetween(int From, int To, string InvalidMessage = "Number Is Not In Between..") {
		int x = ReadIntNumber();

		while (!IsNumberBetween(x, From, To))
		{
			cout << InvalidMessage << endl;
			x = ReadIntNumber();
		}

		return x;
	}

	static short ReadShortNumber(string InvalidMessage = "Invalid Input , Please Try Again..") {
		short x;

		while (!(cin >> x))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << InvalidMessage << endl;

			cin >> x;
		}

		return x;
	}

	static short ReadShortNumberBetween(short From, short To, string InvalidMessage = "Number Is Not In Between..") {
		short x = ReadIntNumber();

		while (!IsNumberBetween(x, From, To))
		{
			cout << InvalidMessage << endl;
			x = ReadIntNumber();
		}

		return x;
	}

	static double ReadDblNumber(string InvalidMessage = "Invalid Input , Please Try Again..") {
		double x;
		while (!(cin >> x))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << InvalidMessage << endl;

			cin >> x;
		}
		return x;
	}

	static double ReadDblBetween(double From, double To, string InvalidMessage = "Number IS Not In Between") {

		double x = ReadDblNumber();
		while (!IsNumberBetween(x, From, To))
		{
			cout << InvalidMessage << endl;
			x = ReadDblNumber();
		}
		return x;
	}

	static bool IsDateInBetween(clsDate DateToCheck, clsDate FromDate, clsDate ToDate) {
		return clsDate::IsDateInBetween(DateToCheck, FromDate, ToDate);
	}

	static bool IsValid(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

	static string ReadString() {

		string S1;
		getline(cin >> ws, S1);
		return S1;
	}

};

