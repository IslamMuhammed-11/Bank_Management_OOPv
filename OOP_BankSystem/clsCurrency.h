#pragma once
#include <iostream>
#include "clsString.h"
#include <vector>
#include <fstream>
#include<string>
class clsCurrency
{
private:
	enum enMode {
		EmptyMode = 0, UpdateMode = 1
	};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;

	double _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string line, string delim = "#//#") {

		vector <string> vData = clsString::Split(line, delim);

		return clsCurrency(enMode::UpdateMode, vData[0], vData[1], vData[2], stod(vData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string delim = "#//#") {
		string Record = "";
		Record += Currency._Country + delim;
		Record += Currency._CurrencyCode + delim;
		Record += Currency._CurrencyName + delim;
		Record += to_string(Currency._Rate);
		return Record;
	}

	static vector<clsCurrency> _LoadCurrencyRecordsFromFile() {
		vector<clsCurrency>vFileData;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile,line))
			{
				clsCurrency C1 = _ConvertLineToCurrencyObject(line);
				vFileData.push_back(C1);
			}
			MyFile.close();
		}
			return vFileData;

	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrency) {

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string line;
			for (clsCurrency& C : vCurrency) {

				line = _ConvertCurrencyObjectToLine(C);
				MyFile << line << endl;
			}

			MyFile.close();

		}

	}

	 void _Update() {
		vector<clsCurrency>vCurrency;
		vCurrency = _LoadCurrencyRecordsFromFile();

		for (clsCurrency& C : vCurrency) {
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrency);
	}

	 static clsCurrency _GetEmptyCurrencyObject() {
		 return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode,
		string CurrencyName, double Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


	static vector<clsCurrency> GetAllUSDRates() {
		return _LoadCurrencyRecordsFromFile();
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	void UpdateRate(double Rate) {
		_Rate = Rate;
		_Update();
	}

	double Rate() {
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode) {

		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile,line))
			{
				clsCurrency C1 = _ConvertLineToCurrencyObject(line);
				if (clsString::UpperAllString(C1.CurrencyCode()) == CurrencyCode)
				{
					MyFile.close();
					return C1;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country) {

		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile , line))
			{
				clsCurrency C1 = _ConvertLineToCurrencyObject(line);
				if (clsString::UpperAllString(C1.Country()) == Country)
				{
					MyFile.close();
					return C1;
				}

			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}

	static vector<clsCurrency> GetCurrenciesList() {
		return _LoadCurrencyRecordsFromFile();
	}

	double ConvertToUSD(double Amount) {

		return (double)(Amount / Rate());
	}

	double ConvertToCurrency2(double Amount, clsCurrency Currency2) {
		double AmountInUSD = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}
		return (double)(AmountInUSD * Currency2.Rate());

	}

};

