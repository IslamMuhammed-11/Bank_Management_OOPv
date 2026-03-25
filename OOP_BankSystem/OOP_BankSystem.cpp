// OOP_BankSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsMainScreen.h"
#include"clsLoginScreen.h"
#include"clsCurrency.h"
using namespace std;




//static void _PrintCurrency(clsCurrency Currency)
//{
//    cout << "\nCurrency Card:\n";
//    cout << "_____________________________\n";
//    cout << "\nCountry    : " << Currency.Country();
//    cout << "\nCode       : " << Currency.CurrencyCode();
//    cout << "\nName       : " << Currency.CurrencyName();
//    cout << "\nRate(1$) = : " << Currency.Rate();
//
//    cout << "\n_____________________________\n";
//
//}
//
//int main()
//
//{
//    clsCurrency Currency1 = Currency1.FindByCode("jod");
//
//    if (Currency1.IsEmpty())
//    {
//        cout << "\nCurrency Is Not Found!\n";
//    }
//    else
//    {
//        _PrintCurrency(Currency1);
//    }
//
//    clsCurrency Currency2 = Currency2.FindByCountry("Egypt");
//
//    if (Currency2.IsEmpty())
//    {
//        cout << "\nCurrency Is Not Found!\n";
//    }
//    else
//    {
//        _PrintCurrency(Currency2);
//    }
//
//    cout << "Currency1 after updating Rate:\n";
//    Currency1.UpdateRate(0.71);
//    _PrintCurrency(Currency1);
//
//
//    return 0;
//}

int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
    return 0;
}



