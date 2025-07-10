#pragma once
#include<iostream>  
#include"clsScreen.h"  
#include"clsBankClient.h"  
#include<iomanip>  
#include"fstream"


using namespace std; 

class clsTransferLogScreen	: protected clsScreen
{
private : 

	static void	_PrintTransferLog(clsBankClient::stTransferData TransferLogRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(23)  << TransferLogRecord.DateTime; 
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber; 
		cout << "| " << setw(8) << left << TransferLogRecord.DestenationAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.TransferAmount; 
		cout << "| " << setw(10) << left << TransferLogRecord.SourceClientBalance; 
		cout << "| " << setw(10) << left << TransferLogRecord.DestinationClientBalance;
		cout << "| " << setw(8) << left << TransferLogRecord.User;

		
	}

public: 

	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferData> vTransferLogRecord = clsBankClient::GetTransferLogData(); 

		string Title = "\t Transfer Log List Screen \n";
		string SubTitle = "\t\t (" + to_string(vTransferLogRecord.size()) + ") Record (s)\n"; 
		_DrawScreenHeader(Title, SubTitle); 

		cout << setw(8) << left << "\n\t_________________________________________________________________________";
		cout << "___________________________________________________\n"; 

		cout << setw(8) << left << "" << "| " << setw(23) << "Date/Time"; 
		cout << "| " << left << setw(8) << "S.Acct"; 
		cout << "| " << left << setw(8) << "D.Acct";
		cout << "| " << left << setw(8) << "Amount"; 
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "D.Balance";
		cout << "| " << left << setw(8) << "User"; 

		cout << setw(8) << left << "\n\t_________________________________________________________________________";
		cout << "___________________________________________________\n";


		if (vTransferLogRecord.size() == 0)
		{
			cout << "\n \t\t\t\tNo Transfer Available In The System ! \n "; 
		   }
		else
		{
			for (clsBankClient::stTransferData St : vTransferLogRecord)
			{
				_PrintTransferLog(St);
				cout << endl;
			}  
		}




	

	}
};

