#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
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

    static void _ReadClientInfo(clsBankClient& client) {

        cout << "\nEnter First Name: ";
        client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name: ";
        client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Pin Code: ";
        client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        client.AccountBalance = clsInputValidate::ReadDblNumber();
    }

public:
    static void UpdateClient() {

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient)) {
            return;
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "Please Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Client With This Account Number Does not Exist\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient client1 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(client1);

        cout << "\nAre You Sure You Want To Update This Client? y/n ";
        char Answer = 'n';
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            cout << "\nUpdate Client Info\n";
            cout << "_____________________________";

            _ReadClientInfo(client1);

            clsBankClient::enSaveResult Result;
            Result = client1.save();

            switch (Result)
            {
            case clsBankClient::svFaildEmptyObject:
                cout << "\nCouldn't Save Object is Empty";
                break;
            case clsBankClient::svSucess:
                cout << "\nUpdated Successfully!\n";
                _PrintClientInfo(client1);
                break;
            }
        }
    }
};

