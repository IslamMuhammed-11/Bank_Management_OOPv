#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsAddNewUserScreen : protected clsScreen
{
private:
	static void _ReadUsersInfo(clsUser& user) {

		cout << "\nEnter First Name: ";
		user.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		user.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		user.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		user.Phone = clsInputValidate::ReadString();
		//cout << "\nEnter Username: ";
		//user.Username = clsInputValidate::ReadString();
		cout << "\nEnter Password: ";
		user.Password = clsInputValidate::ReadString();

		cout << "\n Enter Permissions: ";
        user.Permissions = _ReadPermissionToSet();
	}

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

    static int _ReadPermissionToSet() {
        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClient;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTransactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nShow Login Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }
        
        return Permissions;
    }

public:
    static void ShowAddNewUserScreen() {

        _DrawScreenHeader("\tAdd New User Screen");

        string Username = "";

        cout << "Enter A Username: ";
        Username = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(Username))
        {
            cout << "User with this Username Already signed Please Try Another..\n";
            Username = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::GetAddNewUserObject(Username);
        
        _ReadUsersInfo(User);

        clsUser::enSaveResult Result;
        Result = User.save();

        switch (Result)
        {
        case clsUser::svFailedEmptyObject:
            cout << "\nError User was not saved because it's Empty";
            break;
        case clsUser::svsucess:
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUserInfo(User);
            break;
        case clsUser::svFailedUserExist:
            cout << "\nError User was not saved because UserName is used!\n";
            break;
        default:
            break;
        }
    }
    
};

