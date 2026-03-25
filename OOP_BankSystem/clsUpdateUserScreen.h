#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include"clsScreen.h"

class clsUpdateUserScreen : protected clsScreen
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
    static void ShowUpdateScreen() {

        _DrawScreenHeader("\tUpdate User Screen");

        string username = "";

        cout << "Enter Username: ";
        username = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(username))
        {
            cout << "\nUser Not Fount!.\n";
            cout << "Enter Username: ";
            username = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(username);
        _PrintUserInfo(User1);

        cout << "Are You Sure You Want to Update this User? y/n ";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";
            _ReadUsersInfo(User1);

            clsUser::enSaveResult Result;
            Result = User1.save();

            switch (Result)
            {
            case clsUser::svFailedEmptyObject:
                cout << "\nFailed To Save User is Empty.\n";
                break;
            case clsUser::svsucess:
                cout << "\nUpdated Successfully.\n";
                _PrintUserInfo(User1);
                break;
            }

        }
        else
        {
            cout << "\nOperation Was Cancelled.\n";
        }
    }

};

