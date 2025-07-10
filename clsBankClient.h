#pragma once
#include<iostream>
#include<string>
#include"clsString.h"
#include"clsPerson.h"
#include"clsDate.h"	  
#include<vector>
#include"fstream"

using namespace std;

class clsBankClient : public clsPerson
{


private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddnewMode = 2 };	 // For Object ; 
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkToDelete = false;

	static clsBankClient _ConvertLineToRecordObject(string Line, string Seperator = "#//#")
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

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}
	struct stTransferData;
	 string _PrepareTransferLogRecord(double Amount ,clsBankClient DestinationClient,
		        string UserName,string Seperator = "#//#")
	{
		string TransferLogRecord = ""; 
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator; 
		TransferLogRecord += GetAccountNumber() + Seperator; 
		TransferLogRecord += DestinationClient.GetAccountNumber() + Seperator; 
		TransferLogRecord += to_string(Amount) + Seperator; 
		TransferLogRecord += to_string(AccountBalance) + Seperator; 
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator; 
		TransferLogRecord += UserName; 

		return TransferLogRecord;	
		
	}

	void _RegisterTransferLog(double Amount, clsBankClient DestinationClient,string UserName)
	{
		string Line = _PrepareTransferLogRecord(Amount, DestinationClient, CurrentUser.UserName); 
		fstream MyFile; 
		MyFile.open("TransferLog.txt", ios::out | ios::app); 
		if (MyFile.is_open())
		{
			MyFile << Line << endl; 
			MyFile.close(); 
		}

	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToRecordObject(Line);
				vClient.push_back(Client);
			}
			MyFile.close();
		}
		return vClient;
	}
	

	static void _SaveClientDataToFile(vector<clsBankClient>vClient)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : vClient)
			{
				if (C._MarkToDelete == false)
				{

					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();

		}
	}

	

	void _Update()
	{
		vector<clsBankClient> _vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClient);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		
	}
	}

	static stTransferData _ConvertLineTransferLogToRecord(string Line, string Seperator = "#//#")
	{
		vector<string> vData = clsString::Split(Line, Seperator); 
		stTransferData TransferData; 
		TransferData.DateTime = vData[0];
		TransferData.SourceAccountNumber = vData[1];
		TransferData.DestenationAccountNumber = vData[2];
		TransferData.TransferAmount = stoi(vData[3]); 
		TransferData.SourceClientBalance = stoi(vData[4]);
		TransferData.DestinationClientBalance = stoi(vData[5]);
		TransferData.User = vData[6]; 

		return TransferData; 

	}

public:

	struct stTransferData {
		string DateTime = ""; 
		string SourceAccountNumber = ""; 
		string DestenationAccountNumber = ""; 
		double TransferAmount = 0; 
		double SourceClientBalance = 0; 
		double DestinationClientBalance = 0; 
		string User = ""; 
	};
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
	bool MarkedForDeleted()
	{
		return _MarkToDelete;
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

	//void Print()
	//{
	//	cout << "\n Client Card : ";
	//	cout << "\n ---------------------------------------------";
	//	cout << "\n First Name           : " << FirstName;
	//	cout << "\n Last Name            : " << LastName;
	//	cout << "\n Full Name            : " << FullName();
	//	cout << "\n Email                : " << Email;
	//	cout << "\n Phone                : " << Phone;
	//	cout << "\n Acc. Number          : " << _AccountNumber;
	//	cout << "\n PassWord             : " << _PinCode;
	//	cout << "\n Balance              : " << _AccountBalance;
	//	cout << "\n ---------------------------------------------";

	//}

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

	static clsBankClient GetAddNewClient(string AccountNumber)
	{
		return clsBankClient(enMode::AddnewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient> GetClientList()
	{
		return _LoadClientsDataFromFile();
	}
	static double GetTotalBalance()
	{
		vector <clsBankClient> vClient = clsBankClient::GetClientList();
		double TotalBalance = 0;

		for (clsBankClient Client : vClient)
		{
			TotalBalance += Client.AccountBalance;
		}
		return TotalBalance;

	}

	void Deposite(double Amount)
	{
		_AccountBalance += Amount; 
		Save();
	}

	bool  WithDraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else {
			_AccountBalance -= Amount;
			Save();
			return true; 
		}
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClient = clsBankClient::GetClientList(); 
		double TotalBalances = 0; 

		for (clsBankClient C : vClient)
		{
			TotalBalances += C.AccountBalance; 
		}
		return TotalBalances;  
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C._MarkToDelete = true;
				_SaveClientDataToFile(_vClients);
				return true;
				break;
			}

		}


		*this = _GetEmptyClientObject();


	}

	bool Transfer(double Amount, clsBankClient& DestinationClient)
	{
		if (Amount > AccountBalance)
		{
			return false; 
		}
		WithDraw(Amount); 
		DestinationClient.Deposite(Amount); 
		_RegisterTransferLog(Amount, DestinationClient,CurrentUser.UserName);
		return true;
	  }

	static vector<stTransferData> GetTransferLogData()
	{
		vector<stTransferData> vData; 
		fstream MyFile; 
		MyFile.open("TransferLog.txt", ios::in); 

		if (MyFile.is_open())
		{
			string Line; 
			stTransferData TransferData; 
			while (getline(MyFile, Line))
			{
				TransferData = _ConvertLineTransferLogToRecord(Line); 
				vData.push_back(TransferData); 
			}
			MyFile.close(); 
		}
		return vData; 
	}



	enum enSaveResult { svFailedEmptyObject = 0, svSucceeded = 1 };
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResult::svFailedEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		case enMode::AddnewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResult::svFailedEmptyObject;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;
		}
		}
	}
};












