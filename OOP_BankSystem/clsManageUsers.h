#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsUserListScreen.h"
#include"clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include"clsUser.h"

using namespace std;

class clsManageUsers : protected clsScreen
{
private:
	enum enManageUsersOptions {
		enShowUesrList = 1, enAddNewUser = 2,
		 enDeleteUser = 3, enUpdateUser = 4,
		enFindUser = 5, enMainMenu = 6
	};

	static short _ReadManageUsersOptions() {
		cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 - 6] ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter A Number Between 1 - 6..\n");
		return choice;
	}

	static void _ShowUsersListScreen() {
		/*cout << "\nUsers List Will Show Here";*/
		clsUserListScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen() {
		/*cout << "\nAdd New User Screen Will Show Here";*/
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen() {
		/*cout << "\nDelete User Screen Will Show Here";*/
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen() {
		/*cout << "\nUpdate Screen Will Show here";*/
		clsUpdateUserScreen::ShowUpdateScreen();
	}

	static void _ShowFindUserScreen() {
		/*cout << "\nFind User Screen Will Show Here";*/
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUserMenu() {
		cout << "\n\t\t\t\tPress Any Key To Go back To Manage Users Menu.....";
		system("pause>0");

		ShowManageUserMenu();
	}

	static void _PerformManageUsersMenuOptions(enManageUsersOptions option) {
		switch (option)
		{
		case clsManageUsers::enShowUesrList:
			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::enAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::enUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::enDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::enFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::enMainMenu:
			// Nothing (:
			break;
		}
	}
public:
	static void ShowManageUserMenu() {
		system("cls");

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
			return;
		}

		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersMenuOptions((enManageUsersOptions)_ReadManageUsersOptions());
	}

};

