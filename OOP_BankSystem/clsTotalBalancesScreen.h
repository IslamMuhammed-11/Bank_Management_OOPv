#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
using namespace std;
class clsTotalBalancesScreen : protected clsScreen
{

private:
    static void _PrintClientBalanceLine(clsBankClient Client) {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(52) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }

public:
   static void ShowTotalBalances() {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t Total Balances Screen";
        string subTitle = "\t (" + to_string(vClients.size()) + ") Client(s)";
        _DrawScreenHeader(Title , subTitle);


        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(52) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\tNo Clients Available On The System..";
        else {
            for (clsBankClient& C : vClients) {
                _PrintClientBalanceLine(C);
                cout << endl;
            }
        }
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();
        cout << "\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t( " << clsUtil::NumberToText(TotalBalances) << ")";
    }

};

