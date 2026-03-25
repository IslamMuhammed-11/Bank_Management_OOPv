#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsWithdrawScreen : protected clsScreen
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
    static void ShowWithdrawScreen() {

        _DrawScreenHeader("\tWithdraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient With this Account Number Does Not Exist..\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client1);

        double Amount = 0;
        cout << "\nPlease Enter Withdraw Amount: ";
        Amount = clsInputValidate::ReadDblNumber();

        char Answer = 'N';
        cout << "\nAre You Sure You Want To Perform This Action? y/n ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client1.Withdraw(Amount)) {

                cout << "\nOperation Done Successfully.";
                cout << "\nNew Balance is: " << Client1.AccountBalance << endl;
            }
            else
            {
                cout << "\nOperation Cannot Be Done.\n";
                cout << "\nEntered Amount = " << Amount << endl;
                cout << "\nYour Balance   = " << Client1.AccountBalance << endl;
            }
        }
        else
        {
            cout << "\nOperation Is Cancelled\n";
        }
    }

};

