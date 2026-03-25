#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsUser.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;
class clsTransactionScreen : protected clsScreen
{
private:
	enum enTransactionMenuOptions {
		eDeposit = 1 , eWithdraw = 2,
		eTotalBalances = 3 , eTransfer = 4
		, eTransferLog = 5, eBackToMainMenu = 6
	};

	static short _ReadTransactionMenuOptions() {
		cout << setw(37) << left << "" << "Choose What You Want To Do? [1 - 6]  ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter A Number Between 1 - 6 ");
		return choice;
	}

	static void _ShowDepositScreen() {
		/*cout << "\n Deposit Screen Will Show Here";*/
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		/*cout << "\n Withdraw Screen Will Show Here";*/
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {
		/*cout << "\n Total Balances Will Show Here";*/
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _GoBackToTransactionMenu() {
		cout << setw(37) << left << "\n\tPress Any Key To Go Back To Transaction Menu....";

		system("pause>0");
		ShowTransactionMenu();
	}

	static void _ShowTransferScreen() {
		/*cout << "\nTransfer Screen Will be Here.";*/
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() {
		/*cout << "\nTransfer Log Will Show Here.";*/
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactionMenu(enTransactionMenuOptions option) {
		switch (option)
		{
		case clsTransactionScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenu();
			break;
		case clsTransactionScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenu();
			break;
		case clsTransactionScreen::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenu();
			break;

		case clsTransactionScreen::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenu();
			break;
		case clsTransactionScreen::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenu();
			break;
		case clsTransactionScreen::eBackToMainMenu:
			// Wait For it
			break;
		default:
			break;
		}
	}

public:

	static void ShowTransactionMenu() {

		system("cls");
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions)) {
			return;
		}

		_DrawScreenHeader("\tTransaction Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionMenu((enTransactionMenuOptions)_ReadTransactionMenuOptions());
		}

};

