#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <vector>
using namespace std;
class clsUpdateRateScreen : protected clsScreen 
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

public:
    static void ShowUpdateRateScreen() {

        _DrawScreenHeader("\tUpdate Rate Screen.");

        string Code = "";
        cout << "Please Enter Currency code: ";
        Code = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nCurrency Not Found!,Try Another Code: ";
            Code = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(Code);

        _PrintCurrency(Currency);

        char Answer = 'n';
        cout << "\nAre You Sure You Want To Update This Currency Rate? y/n ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            double Amount = 0;

            cout << "\nUpdate Rate.";
            cout << "\n--------------------\n";
            cout << "\nPlease Enter The New Currency Rate? ";
            Amount = clsInputValidate::ReadDblNumber();

            Currency.UpdateRate(Amount);

            cout << "\nRate Updated Successfully (-:\n";
            _PrintCurrency(Currency);
        }
    }
};

