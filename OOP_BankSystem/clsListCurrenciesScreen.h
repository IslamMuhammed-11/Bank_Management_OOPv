#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
class clsListCurrenciesScreen : protected clsScreen
{
private:

	static void _PrintCurrenciesRecord(clsCurrency Currency) {
        cout << setw(8) << left << "" << "| " << setw(28) << left <<Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(35) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();
	}

public:

    static void ShowListCurrenciesScreen() {

        vector<clsCurrency>vDataFile = clsCurrency::GetCurrenciesList();

        string Title = "\t Currencies List Screen.";
        string SubTitle = "\t( " + to_string(vDataFile.size()) + " ) Currencies.";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(28) << "Country ";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(35) << "Name";
        cout << "| " << left << setw(12) << "Rate /(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vDataFile.size() == 0)
            cout << "\t\t\tNo Currencies On System.\n";
        else
        {
            for (clsCurrency& C : vDataFile) {
                _PrintCurrenciesRecord(C);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

