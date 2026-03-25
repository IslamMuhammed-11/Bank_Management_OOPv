#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsDepositScreen : protected clsScreen
{
private:
    static void _PrintClientInfo(clsBankClient Client) {

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPin Code    : " << Client.PinCode;
        cout << "\nAcc. Balance: " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    
    static string _ReadAccountNumber() {
        cout << "Please Enter Account Number: ";
        string AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

public:

    static void ShowDepositScreen() {

        _DrawScreenHeader("\tDeposit Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Client With this Account Number Does Not Exist..\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client1);
        double Amount = 0;
        cout << "\nPlease Enter A Deposit Amount: ";
        Amount = clsInputValidate::ReadDblNumber();

        char Answer = 'n';
        cout << "\nAre You Sure Want To Perform This Action ? y/n ";
        cin >> Answer;

        if (toupper(Answer) == 'Y') {

            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.AccountBalance << endl;
        }
        else
        {
            cout << "\nOperation Was Cancelled\n";
        }
    }
};

