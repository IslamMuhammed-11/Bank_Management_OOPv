#pragma once
#include<iostream>
#include <string>
#include <fstream>
#include"clsPerson.h"
#include "clsString.h"
#include"clsUtil.h"
using namespace std;

class clsUser : public clsPerson
{
private:


	enum enMode {
		enEmptyMode = 0, enUpdateMode = 1
		,enAddNewMode = 2
	};



	enMode _Mode;
	string _Username;
	string _Password;

	int _Permissions;
	bool _MarkForDelete = false;

	

	static clsUser _ConvertLineToUserObject(string line, string delim = "#//#") {

		vector<string>UserData;
		UserData = clsString::Split(line ,delim);

		return clsUser(enMode::enUpdateMode, UserData[0], UserData[1], UserData[2],
			UserData[3], UserData[4], clsUtil::DecryptText(UserData[5]) , stoi(UserData[6]));

	}

	static string _ConvertUserObjectToLine(clsUser user , string delim = "#//#") {
		string DataLine = "";

		DataLine += user.FirstName + delim;
		DataLine += user.LastName + delim;
		DataLine += user.Email + delim;
		DataLine += user.Phone + delim;
		DataLine += user.Username + delim;
		DataLine += clsUtil::EncryptText(user.Password) + delim;
		DataLine += to_string(user.Permissions);

		return DataLine;
	}

	static vector<clsUser> _LoadUserDataFromFile() {
		fstream MyFile;
		vector<clsUser> vUsers;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string line;
			while (getline(MyFile , line))
			{
			
				clsUser user = _ConvertLineToUserObject(line);
				vUsers.push_back(user);
			}
			MyFile.close();
		}
		return vUsers;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open()) {
			string DataLine;
			for (clsUser& U : vUsers) {
				if (U.MarkForDelete() == false)
				{
				DataLine = _ConvertUserObjectToLine(U);
				MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}

	}

    void _Update() {
		vector<clsUser> vUsers;
		vUsers = _LoadUserDataFromFile();

		for (clsUser& U : vUsers) {

			if (U.Username == _Username)
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}

	void _AddNew() {
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::enEmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareLoginRecord(string delim = "#//#") {
		string DataLine = "";
		DataLine += clsDate::GetSystemDateAndTimeString() + delim;
		DataLine += Username + delim;
		DataLine += clsUtil::EncryptText(Password) + delim;
		DataLine += to_string(Permissions);
		return DataLine;
	}

public:
	enum enPermissions {
		eAll = -1, pListClient = 1
		, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16,
		pTransactions = 32, pManageUsers = 64,
		pLoginRegister = 128
	};

	static struct stLoginRegister {
		string Username;
		string Password;
		string DateTime;
		int Permission;
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email
		, string Phone, string Username, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_Username = Username;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty() {
		return (_Mode == enEmptyMode);
	}

	bool MarkForDelete() {
		return _MarkForDelete;
	}

	void SetUsername(string Username) {
		_Username = Username;
	}

	string GetUsername() {
		return _Username;
	}

	__declspec(property(get = GetUsername, put = SetUsername)) string Username;
	

	void SetPassword(string Password) {
		_Password = Password;
	}

	string GetPassword() {
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int permissons) {
		_Permissions = permissons;
	}

	int GetPermissions(){
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


	static clsUser Find(string parUsername) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile , line))
			{
				clsUser user = _ConvertLineToUserObject(line);
				if (user.Username == parUsername)
				{
					MyFile.close();
					return user;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string parUsername , string parPassword) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line))
			{
				clsUser user = _ConvertLineToUserObject(line);
				if (user.Username == parUsername && user.Password == parPassword)
				{
					MyFile.close();
					return user;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string parUsername) {
		clsUser user = clsUser::Find(parUsername);

		return (!user.IsEmpty());
	}

	enum enSaveResult {
		svFailedEmptyObject = 1, svsucess = 2, svFailedUserExist = 3
	};

	enSaveResult save() {
		switch (_Mode)
		{
		case clsUser::enEmptyMode:
			return svFailedEmptyObject;
			break;
		case clsUser::enUpdateMode:
			_Update();
			return svsucess;
			break;
		case clsUser::enAddNewMode:
			if (IsUserExist(_Username))
			{
				return svFailedUserExist;
			}
			else
			{
				_AddNew();
				_Mode = enUpdateMode;
				return svsucess;
			}
			break;
		default:
			break;
		}
	}

	bool Delete() {
		vector<clsUser>vUsers;
		vUsers = _LoadUserDataFromFile();

		for (clsUser& U : vUsers) {
			if (U.Username == _Username)
			{
				U._MarkForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);

		*this = _GetEmptyUserObject();

		return true;
	}

	static clsUser GetAddNewUserObject(string parUsername) {
		return clsUser(enMode::enAddNewMode, "", "", "", "", parUsername, "", 0);
	}

	static vector<clsUser>GetUserList() {
		return _LoadUserDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission) {
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	}

	void RegisterLogin() {

		string DataLine = _PrepareLoginRecord();
		fstream MyFile;
		MyFile.open("RegisterLogin.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;

			MyFile.close();
		}

	}

	static stLoginRegister ConvertLineToLoginRegisterStruct(string line, string delim = "#//#") {
		vector <string> LineData;
		stLoginRegister History;
		LineData = clsString::Split(line, delim);

		History.DateTime = LineData[0];
		History.Username = LineData[1];
		History.Password = clsUtil::DecryptText(LineData[2]);
		History.Permission = stoi(LineData[3]);

		return History;
	}

	static vector<stLoginRegister> LoadHistoryFromFile() {
		fstream MyFile;
		vector<stLoginRegister>vHistory;
		MyFile.open("RegisterLogin.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;
			stLoginRegister OneLineRecord;
			while (getline(MyFile, line))
			{
				OneLineRecord = ConvertLineToLoginRegisterStruct(line);
				vHistory.push_back(OneLineRecord);
			}
		}
		return vHistory;
	}

	static vector<stLoginRegister> GetLoginHistory() {
		return LoadHistoryFromFile();
	}

};

