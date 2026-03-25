#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

class clsAddNewClient : protected clsScreen
{

private:
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
    static void AddNewClient() {

        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
            return;
        }


        _DrawScreenHeader("\t Add New Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Client With This Account Number Already Exists , Try Another..\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResult Result;
        Result = NewClient.save();

        switch (Result)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "Failed Empty Object\n";
            break;
        case clsBankClient::svSucess:
            cout << "Client Added Successfully\n";
            _PrintClientInfo(NewClient);
            break;
        case clsBankClient::svFailAccountNumberExists:
            cout << "Client With This Account Number Already Exists\n";
            break;
        }
    }
};

