#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

    static double _ReadAmount() {

        cout << "Enter Amount To Exchange: ";
        double Amount = 0;

        Amount = clsInputValidate::ReadDblNumber();
        return Amount;

    }

    static clsCurrency _GetCurrency(string Message) {

        string CurrencyCode;
        cout << Message << endl;
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "Currency Not Found, Try Another? ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return Currency;

    }

    static void _PrintCurrency(clsCurrency Currency , string Title = "Currency Card:")
    {
        cout << endl << Title << endl;;
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _PrintCalculationsResult(double Amount, clsCurrency Currency1, clsCurrency Currency2) {

        _PrintCurrency(Currency1, "Convert From");

        double AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting From USD To: \n";
        _PrintCurrency(Currency2, "To: ");

        double AmountInCurrency2 = Currency1.ConvertToCurrency2(Amount, Currency2);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
    }

public:
    static void ShowCurrencyCalculator() {
        char Continue = 'y';

        while (toupper(Continue) == 'Y')
        {
            system("cls");
            _DrawScreenHeader("\tCurrency Calculator Screen.");
            
            clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");

            double Amount = _ReadAmount();

            _PrintCalculationsResult(Amount, CurrencyFrom, CurrencyTo);

            cout << "\nDo You Want To Perform Another Currency Exchange? y/n ";
            cin >> Continue;
        }


     
    }
};

