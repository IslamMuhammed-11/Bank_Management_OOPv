#pragma once
#include<iostream>
#include"clsScreen.h"

#include"clsUser.h"
#include"clsInputValidate.h"
class clsDeleteUserScreen : protected clsScreen
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
    static void ShowDeleteUserScreen() {

        _DrawScreenHeader("\tDelete User Screen");

        string username = "";
        cout << "\nEnter Username: ";
        username = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(username))
        {
            cout << "\n User Not Found!.\n";
            cout << "\nEnter Username: ";
            username = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(username);
        _PrintUserInfo(User1);

        cout << "\nAre You Sure You Want To Delete This User ? y/n ";
        char Answer = 'n';
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            if (User1.Delete())
            {
                cout << "\nDeleted Successfully.\n";
                _PrintUserInfo(User1);
            }
            else
            {
                cout << "\nError Was Not Deleted.\n";
            }
        }
        else
        {
            cout << "\nOperation Was Cancelled\n";
        }
    }

};

