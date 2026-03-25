#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include"Global.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login() {
		bool LoginFailed = false;
		string username, password;
		short FailedCounter = 0;
		do
		{
			if (LoginFailed)
			{
				FailedCounter++;
				cout << "\nInvalid Username / Password\n";
				cout << "You Have " << (3 - FailedCounter) << " Trials Left\n";
			}
			if (FailedCounter == 3)
			{
				cout << "\nYou're Locked Out After 3 Failed Trials\n";
				return false;
			}

			cout << "\nEnter Username: ";
			username = clsInputValidate::ReadString();

			cout << "\nEnter Password: ";
			password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(username, password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);
		
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenuScreen();
		return true;
	}

public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}
};

