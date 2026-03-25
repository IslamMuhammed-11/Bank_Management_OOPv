#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include<iomanip>
class clsTransferLogScreen : protected clsScreen
{
private:
	static void _PrintRecord(clsBankClient::stTransferRecord Record) {
		cout << setw(8) << left << "" << "| " << setw(23) << left << Record.DateTime;
		cout << "| " << setw(8) << left << Record.Source;
		cout << "| " << setw(8) << left << Record.Destination;
		cout << "| " << setw(8) << left << Record.Amount;
		cout << "| " << setw(10) << left << Record.sBalance;
		cout << "| " << setw(10) << left << Record.dBalance;
		cout << "| " << setw(8) << left << Record.User;
	}
	
public:
	static void ShowTransferLogScreen() {

		vector<clsBankClient::stTransferRecord> vData = clsBankClient::LoadTransferRecordsFromFile();


		string Title = "\tTransfer Log Screen.";
		string SubTitle = "\t(" + to_string(vData.size()) + ") Log(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vData.size() == 0)
			cout << "\t\t\t\tThere is No Logs in The System.\n";
		else
		{
			for (clsBankClient::stTransferRecord& L : vData) {
				_PrintRecord(L);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

