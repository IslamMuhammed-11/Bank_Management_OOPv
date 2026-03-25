#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindCurrency : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
{
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();

    cout << "\n_____________________________\n";

} 

    static void _ShowResult(clsCurrency Currency) {

        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found (-:\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Not Found )-:\n";
        }
    }

public:

    static void ShowFindCurrencyScreen() {

        _DrawScreenHeader("\tFind Currency Screen.");

        short Answer = 0;
        cout << "Find By: [1] Code or [2] Country ? ";

        Answer = clsInputValidate::ReadShortNumberBetween(1, 2);

        if (Answer == 1)
        {
            string Code = "";

            cout << "Please Enter Currency Code: ";
            Code = clsInputValidate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCode(Code);

            _ShowResult(Currency);
        }

        else
        {
            string Country = "";

            cout << "Please Enter Country Name: ";
            Country = clsInputValidate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCountry(Country);

            _ShowResult(Currency);
        }
    }
};

