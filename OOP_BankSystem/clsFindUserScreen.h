#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsScreen.h"

class clsFindUserScreen : protected clsScreen
{
private:
    static void _PrintUserInfo(clsUser User) {

        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.Username;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }


public:
    static void ShowFindUserScreen() {

        _DrawScreenHeader("\t Find User Screen");

        string username = "";
        cout << "Enter Username: ";
        username = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(username))
        {
            cout << "\nUser Not Found!\n";
            cout << "\nEnter Username: ";
            username = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(username);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found (-:\n";
        }
        else
        {
            cout << "\nUser Was Not Found )-:\n";
        }

        _PrintUserInfo(User1);

    }
};

