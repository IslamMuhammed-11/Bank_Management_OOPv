#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsFindClientScreen : protected clsScreen
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
    static void ShowFindClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
            return;
        }

        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber = "";
        cout << "Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Client With This Account Number Does Not Exist, Enter Another Account Number.\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty())
        {
            cout << "\nClient Found (-:\n";
        }
        else
        {
            cout << "\nClient Was Not found )-:\n";
        }
        _PrintClientInfo(Client);
    }

};

