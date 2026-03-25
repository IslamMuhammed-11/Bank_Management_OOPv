#pragma once
#include<iostream>
#include <iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsShowClientsScreen.h"
#include"clsAddNewClient.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsers.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyMainScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuChoices 
	{ enShowClient = 1, enAddClient = 2,
		enDeleteClient = 3, enUpdateClient = 4,
		enFindClient = 5, enTransactions = 6, 
		enManageUseres = 7, enLoginRegister = 8
		, enCurrencyExchange = 9,enLogOut = 10 };

	static short _ReadMainMenuOptions() {
		cout << setw(37) << left << "" << "Choose What You Want To Do? [1 - 10]  ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number Between 1 - 10 ? ");
		return Choice;
	}

	static void _GoBackToMainMenu() {
		cout << setw(37) << left << "\n\tPress Any Key To Go Back To Main Menu....";

		system("pause>0");
		ShowMainMenuScreen();
	}
				
	static void _ShowAllClientsScreen() {
		/*cout << "\nAll Clients Screen Will show here..";*/
		clsShowClientsScreen::ShowClientsList();
	}
				
	static void _AddClientScreen() {
		/*cout << "\nAdd Client Screen Will Show Here";*/
		clsAddNewClient::AddNewClient();
	}
				
	static void _DeleteClientScreen() {
		/*cout << "\nDelete Client Screen Will Show Here";*/
		clsDeleteClient::DeleteClient();
	}
				
	static void _UpdateClientScreen() {
		/*cout << "\nUpdate Client screen will show here";*/
		clsUpdateClientScreen::UpdateClient();
	}
				
	static void _FindClientScreen() {
		/*cout << "\nFind Screen Will Show here";*/
		clsFindClientScreen::ShowFindClientScreen();
	}
				
	static void _TransactionScreen() {
		/*cout << "\nTransaction Screen Will Show Here";*/
		clsTransactionScreen::ShowTransactionMenu();
	}
				
	static void _ManageUsersScreen() {
		/*cout << "\nManage Users Screen Will Show here";*/
		clsManageUsers::ShowManageUserMenu();
	}

	static void _LoginRegisterScreen() {
		/*cout << "\nRegister Screen Will Be Here.";*/
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _CurrencyExchange() {
		/*cout << "\nCurrency Exchange Will Show Here.";*/
		clsCurrencyMainScreen::ShowCurrencyMainScreen();
	}

	//static void _ShowEndScreen() {
	//	cout << "\n End";
	//}

	static void _Logout() {

		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMenuOptions(enMainMenuChoices UserChoice) {

		switch (UserChoice)
		{
		case clsMainScreen::enShowClient:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::enAddClient:
			system("cls");
			_AddClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::enDeleteClient:
			system("cls");
			_DeleteClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::enUpdateClient:
			system("cls");
			_UpdateClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::enFindClient:
			system("cls");
			_FindClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::enTransactions:
			system("cls");
			_TransactionScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::enManageUseres:
			system("cls");
			_ManageUsersScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::enLoginRegister:
			system("cls");
			_LoginRegisterScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::enCurrencyExchange:
			system("cls");
			_CurrencyExchange();
			_GoBackToMainMenu();
		case clsMainScreen::enLogOut:
			system("cls");
			_Logout();
			break;
		default:
			break;
		}
	}

	public:
		static void ShowMainMenuScreen() {
			system("cls");
			_DrawScreenHeader("\tMain Screen");

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
			cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
			cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
			cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
			cout << setw(37) << left << "" << "\t[5] Find Client.\n";
			cout << setw(37) << left << "" << "\t[6] Transactions.\n";
			cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
			cout << setw(37) << left << "" << "\t[8] Login Register.\n";
			cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
			cout << setw(37) << left << "" << "\t[10] Logout.\n";
			cout << setw(37) << left << "" << "===========================================\n";

			_PerformMainMenuOptions((enMainMenuChoices)_ReadMainMenuOptions());
		}
};

