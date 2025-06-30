#pragma once
#include<iostream>
#include<string>
#include"clsString.h"
#include"clsPerson.h"
#include<vector>
#include"fstream"

using namespace std; 

class clsBankClient	: public clsPerson
{
private: 
	enum enMode {EmptyMode = 0 , UpdateMode=1};	 // For Object ; 
	enMode _Mode; 

	string _AccountNumber; 
	string _PinCode; 
	float _AccountBalance; 

	static clsBankClient _ConvertLineToRecordObject(string Line,string Seperator = "#//#")
	{

		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


public  :
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName,
			Email, Phone)
	{

		_Mode = Mode; 
		_AccountNumber = AccountNumber; 
		_PinCode = PinCode; 
		_AccountBalance = AccountBalance; 
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode); 
	}

	string GetAccountNumber()
	{
		return _AccountNumber; 
	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode; 
	}
	string GetPinCode()
	{
		return _PinCode; 
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode; 
	 
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance; 
	}
    float GetAccountBalance()
	{
		return _AccountBalance; 
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	string FullName()
	{
		return FirstName + LastName; 
	}

	void Print()
	{
		cout << "\n Client Card : "; 
		cout << "\n ---------------------------------------------"; 
		cout << "\n First Name           : " << FirstName; 
		cout << "\n Last Name            : " << LastName; 
		cout << "\n Full Name            : " << FullName(); 
		cout << "\n Email                : " << Email; 
		cout << "\n Phone                : " << Phone; 
		cout << "\n Acc. Number          : " << _AccountNumber; 
		cout << "\n PassWord             : " << _PinCode; 
		cout << "\n Balance              : " << _AccountBalance; 
		cout << "\n ---------------------------------------------";

	}

	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClients; 
		fstream MyFile; 
		MyFile.open("Clients.txt", ios::in); 
		
		if (MyFile.is_open())
		{
			string Line; 
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToRecordObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close(); 
					return Client; 
				}
				vClients.push_back(Client); 

			}
			MyFile.close(); 
		}
		return _GetEmptyClientObject(); 
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector<clsBankClient>vClient; 

		fstream MyFile; 
		MyFile.open("Clients.txt", ios::in); 

		if (MyFile.is_open())
		{
			string Line; 
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToRecordObject(Line); 
				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close(); 
					return Client; 
				}
				vClient.push_back(Client);
			}
			MyFile.close(); 
		}
		return _GetEmptyClientObject(); 
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty()); 
	}
};

