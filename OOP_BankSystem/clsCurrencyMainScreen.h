#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsListCurrenciesScreen.h"
#include"clsFindCurrency.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyMainScreen : protected clsScreen
{
private:
	enum enCurrencyScreenOptions {
		enListCurrencies = 1 , enFindCurrency = 2,
		enUpdateRate = 3 , enCurrencyCalculator = 4
		,enMainMenu = 5
	};

	static short _ReadCurrencyScreenOptions() {
		cout << setw(37) << left << "" << "Choose What You Want To Do? [1 - 5]  ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number Between 1 - 5 ? ");
		return Choice;
	}

	static void _ListCurrenciesScreen() {
		/*cout << "\nCurrencies List Will Show Here,";*/
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _FindCurrencyScreen() {
		/*cout << "\nFind Currency Screen Will Show Here.";*/
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _UpdateRateScreen() {
		/*cout << "\nUpdate Rate Screen.";*/
		clsUpdateRateScreen::ShowUpdateRateScreen();
	}

	static void _CurrencyCalculatorScreen() {
		/*cout << "\nCurrency Calculator will show Here.";*/
		clsCurrencyCalculatorScreen::ShowCurrencyCalculator();
	}

	static void _GoBackToCurrencyScreen() {
		cout << setw(37) << left << "\n\tPress Any Key To Go Back To Currency Screen....";

		system("pause>0");
		ShowCurrencyMainScreen();
	}

	static void _PerformCurrencyScreenOptions(enCurrencyScreenOptions Option) {

		switch (Option)
		{
		case clsCurrencyMainScreen::enListCurrencies:
			system("cls");
			_ListCurrenciesScreen();
			_GoBackToCurrencyScreen();
			break;
		case clsCurrencyMainScreen::enFindCurrency:
			system("cls");
			_FindCurrencyScreen();
			_GoBackToCurrencyScreen();
			break;
		case clsCurrencyMainScreen::enUpdateRate:
			system("cls");
			_UpdateRateScreen();
			_GoBackToCurrencyScreen();
			break;
		case clsCurrencyMainScreen::enCurrencyCalculator:
			system("cls");
			_CurrencyCalculatorScreen();
			_GoBackToCurrencyScreen();
			break;
		case clsCurrencyMainScreen::enMainMenu:
			
			break;
		}
	}

public:
	static void ShowCurrencyMainScreen() {
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen.");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyScreenOptions((enCurrencyScreenOptions)_ReadCurrencyScreenOptions());
	}

};

