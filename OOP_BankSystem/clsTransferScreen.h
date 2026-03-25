#pragma once
#include<iostream>
#include <iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

using namespace std;
class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClientCard(clsBankClient Client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nAcc. Balance: " << Client.AccountBalance;
        cout << "\n___________________\n";
	}

    static string _ReadAccountNumber() {
        
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Invalid Account Number, Try Another One? ";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }

    static double _ReadAmount(clsBankClient SourceClient) {
        double Amount = 0;
        cout << "\nPlease Enter Transfer Amount: ";
        Amount = clsInputValidate::ReadDblNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nThe Amount Exceeds The Balance Try Another Amount? ";
            Amount = clsInputValidate::ReadDblNumber();
        }

        return Amount;
    }

public:
    static void ShowTransferScreen() {

        _DrawScreenHeader("\tTransfer Screen");

        cout << "\nPlease Enter Account Number To Transfer From: ";
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClientCard(SourceClient);

        cout << "\nPlease Enter Account Number To Transfer To: ";
        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClientCard(DestinationClient);

        double Amount = _ReadAmount(SourceClient);

        char Answer = 'N';
        cout << "Are You Sure You Want To Perform This Action? y/n ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (SourceClient.Transfer(Amount , DestinationClient))
            {
                cout << "\nTransferred Successfully.\n";
            }
            else
            {
                cout << "\nTransfer Failed.\n";
            }
            _PrintClientCard(SourceClient);
            _PrintClientCard(DestinationClient);
        }

    }

};

