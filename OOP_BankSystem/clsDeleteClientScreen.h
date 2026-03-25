#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsDeleteClient : protected clsScreen
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

public:
   static void DeleteClient() {

       if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
           return;
       }


       _DrawScreenHeader("\tDelete Client Screen");

        string AccountNumber = "";

        cout << "Please Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Client With this Account Number Does Not Exist\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client1);

        cout << "\nAre You Sure You Want To Delete This Client? y/n ";

        char Answer;
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "Deleted Successfully\n";
                _PrintClientInfo(Client1);
            }
            else
            {
                cout << "Error Client Was Not Deleted!";
            }
        }
    }

};

