#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include"Global.h"

#include <iomanip>
class clsLoginRegisterScreen : protected clsScreen
{
private:

	static void _PrintUserLogLine(clsUser::stLoginRegister History) {
		 
		 cout << setw(8) << left << "" << "| " << setw(25) << left << History.DateTime;
		 cout << "| " << setw(25) << left << History.Username;
		 cout << "| " << setw(25) << left << History.Password;
		 cout << "| " << setw(25) << left << History.Permission;
	}

	
public:

	static void ShowLoginRegisterScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister)) {
			return;
		}

		vector<clsUser::stLoginRegister> vHistory;
		vHistory = clsUser::GetLoginHistory();

		string Title = "\tLogin Registration Screen";
		string subTitle ="\t(" + to_string(vHistory.size()) + ") Record(s).";
		_DrawScreenHeader(Title , subTitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date Time";
		cout << "| " << left << setw(25) << "Username";
		cout << "| " << left << setw(25) << "Password";
		cout << "| " << left << setw(25) << "Permission";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vHistory.size() == 0)
			cout << "\t\t\t\tNo Records Avaliable.\n";

		else
		{
		for (clsUser::stLoginRegister& H : vHistory) {
			_PrintUserLogLine(H);
			cout << endl;
		}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	};

};

