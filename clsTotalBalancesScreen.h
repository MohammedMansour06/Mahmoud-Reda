#pragma once
#include<iostream>  
#include"clsBankClient.h"  
#include"clsInputValidate.h" 
#include "clsScreen.h"  
#include"clsUtil.h"
#include <vector>  
#include<iomanip>

class clsTotalBalancesScreen :protected clsScreen 
{

private : 
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "|  " << setw(15) << left << "";
		cout << "|  " << setw(40) << left << Client.FullName(); 
		cout << "|  " << setw(12) << left << Client.AccountBalance; 
	 }

public  :
	
	static void ShowTotalBalances()
	{
		vector <clsBankClient > vClient = clsBankClient::GetClientList();

		string Title = "\t Balance List Screen ";
		string SubTitle = "\t  (" + to_string(vClient.size()) + ") Clients";

		_DrawScreenHeader(Title, SubTitle); 

		cout << setw(25) << left << "" << "|  " << setw(15) << left << "" << "\n\t\t ------------------------------------------------"; 
		cout << "----------------------------------------------\n";

		cout << setw(25) << left << "" << "|  " << setw(15) << left << "";
		cout << "|  " << setw(40) << left << "Client Name ";
		cout << "|  " << setw(12) << left << "Balance";

		cout << setw(25) << left << "" << "|  " << setw(15) << left << "" << "\n\t\t ------------------------------------------------";
		cout << "----------------------------------------------\n";

		double TotalBalances = clsBankClient::GetTotalBalance();  

		if (vClient.size() == 0)
		{
			cout << "\t\t\t\t No Clients Avaliable In The System ....." << endl;
		}
		else
		{
			for (clsBankClient Client : vClient)
			{
				_PrintClientRecordBalanceLine(Client); 
				cout << endl; 

			}
		}	
		cout << setw(25) << left << "" << "|  " << setw(15) << left << "" << "\n\t\t ------------------------------------------------";
		cout << "----------------------------------------------\n";

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t    Total Balances  = " << TotalBalances << endl; 
		cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText(TotalBalances) << endl; 
	}
};

