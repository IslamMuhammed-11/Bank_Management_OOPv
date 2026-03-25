#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include "Global.h"
using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _Balance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string line, string delim = "#//#") {
		vector<string>vClientData;
		vClientData = clsString::Split(line, delim);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string delim = "#//#") {
		string ClientDataLine = "";
		ClientDataLine += Client.FirstName + delim;
		ClientDataLine += Client.LastName + delim;
		ClientDataLine += Client.Email + delim;
		ClientDataLine += Client.Phone + delim;
		ClientDataLine += Client.AccountNumber() + delim;
		ClientDataLine += Client.PinCode + delim;
		ClientDataLine += to_string(Client.AccountBalance);
		return ClientDataLine;
	}

	static vector<clsBankClient> _LoadClientDataFromFile() {
		vector<clsBankClient>_vClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);
				_vClient.push_back(client);
			}
			MyFile.close();
		}
		return _vClient;
	}

	static void _SaveClientDataToFile(vector<clsBankClient>& vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); // overwrite
		if (MyFile.is_open())
		{
			string DataFile;
			for (clsBankClient& C : vClients) {

				if (C.MarkForDelete() == false) {
					DataFile = _ConvertClientObjectToLine(C);
					MyFile << DataFile << endl;
				}
			}

			MyFile.close();
		}

	}

	void _Update() {
		vector<clsBankClient>vClient;
		vClient = _LoadClientDataFromFile();

		for (clsBankClient& C : vClient) {

			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientDataToFile(vClient);
	}

	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareTransferLog(clsBankClient DestinationClient,double Amount ,string delim = "#//#") {
		string FileLine = "";
		FileLine += clsDate::GetSystemDateAndTimeString() + delim;
		FileLine += _AccountNumber + delim;
		FileLine += DestinationClient.AccountNumber() + delim;
		FileLine += to_string(Amount) + delim;
		FileLine += to_string(AccountBalance) + delim;
		FileLine += to_string(DestinationClient.AccountBalance) + delim;
		FileLine += CurrentUser.Username;
		return FileLine;
	}

	void _TransferLog(double Amount, clsBankClient DestinationClient) {
		string Line = _PrepareTransferLog(DestinationClient, Amount);
		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}

	}


public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double Balance)
		: clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}

	//Check If The Object Is Empty
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	//Read Only
	string AccountNumber() {
		return _AccountNumber;
	}

	bool MarkForDelete() {
		return _MarkForDelete;
	}
	//_________________________Get And Set Properties________________
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	string GetPinCode() {
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double Balance) {
		_Balance = Balance;
	}

	double GetAccountBalance() {
		return _Balance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;
	//______________________________________________________________

	//void Print()
	//{
	//	cout << "\nInfo:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName   : " << FirstName;
	//	cout << "\nLastName    : " << LastName;
	//	cout << "\nFull Name   : " << FullName();
	//	cout << "\nEmail       : " << Email;
	//	cout << "\nPhone       : " << Phone;
	//	cout << "\nAcc. Number : " << _AccountNumber;
	//	cout << "\nPin Code    : " << _PinCode;
	//	cout << "\nAcc. Balance: " << _Balance;
	//	cout << "\n___________________\n";
	//}

	//Find Client With Account Number
	static clsBankClient Find(string AccountNumber) {
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);
				if (client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return client;
				}
				vClients.push_back(client);
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	//Find Client With Account Number And Password
	static clsBankClient Find(string AccountNumber, string PinCode) {
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);
				if (client.AccountNumber() == AccountNumber && client._PinCode == PinCode)
				{
					MyFile.close();
					return client;
				}
				vClients.push_back(client);
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	//Check If Client Exists
	static bool IsClientExist(string AccountNumber) {
		clsBankClient client = clsBankClient::Find(AccountNumber);
		return !(client.IsEmpty());
	}

	enum enSaveResult { svFaildEmptyObject = 0, svSucess = 1 , svFailAccountNumberExists = 2 };

	enSaveResult save() {
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
		{

			return svFaildEmptyObject;

			break;
		}
		case clsBankClient::UpdateMode:
		{
			_Update();
			return svSucess;
			break;
		}

		case clsBankClient::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return svFailAccountNumberExists;
			}
			else
			{
				_AddNew();

				_Mode = UpdateMode;
				return svSucess;
			}
		}

		}
	};

	static clsBankClient GetAddNewClientObject(string accountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "", 0);
	}

	bool Delete() {
		vector<clsBankClient>vClients;
		vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : vClients) {
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveClientDataToFile(vClients);

		*this = _GetEmptyClientObject();
		return true;
	}

	static vector<clsBankClient> GetClientsList() {
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances() {
		vector<clsBankClient>vClients;
		vClients = _LoadClientDataFromFile();
		double TotalBalance = 0;

		for (clsBankClient& C : vClients) {
			TotalBalance += C.AccountBalance;
		}
		return TotalBalance;
	}

	void Deposit(double Amount) {
		_Balance += Amount;
		save();
	}

	bool Withdraw(double Amount) {

		if (Amount > _Balance)
		{
			return false;
		}
		else
		{
		_Balance -= Amount;
		save();
		return true;
		}
	}

	bool Transfer(double Amount , clsBankClient & DestinationClient) {
		 if (Amount > _Balance)
		 {
			 return false;
		 }

		 Withdraw(Amount);
		 DestinationClient.Deposit(Amount);
		 _TransferLog(Amount, DestinationClient);
		 return true;
	}

	struct stTransferRecord	 {
		string DateTime;
		string Source;
		string Destination;
		double Amount;
		double sBalance;
		double dBalance;
		string User;
	};

	static stTransferRecord ConvertLineToTransferRecord(string line , string delim = "#//#") {
		vector<string> vDataFile = clsString::Split(line , delim);
		stTransferRecord Record;
		Record.DateTime = vDataFile[0];
		Record.Source = vDataFile[1];
		Record.Destination = vDataFile[2];
		Record.Amount = stod(vDataFile[3]);
		Record.sBalance = stod(vDataFile[4]);
		Record.dBalance = stod(vDataFile[5]);
		Record.User = vDataFile[6];
		return Record;
	}

	static vector<stTransferRecord> LoadTransferRecordsFromFile() {
		vector<stTransferRecord> vData;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;
			stTransferRecord Record;
			while (getline(MyFile, line))
			{
				Record = ConvertLineToTransferRecord(line);
				vData.push_back(Record);
			}
			MyFile.close();
		}
		return vData;
	}
};
