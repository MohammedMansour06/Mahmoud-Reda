#pragma once
#include<iostream>  
#include"clsUser.h"	 
#include"clsScreen.h" 
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"Global.h"


using namespace std;

class clsTransferScreen	: protected clsScreen 
{
private   : 
	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n Client Card : \n"; 
		cout << "\n ___________________________________________"; 
		cout << "\n Full Name : " << Client.FullName(); 
		cout << "\n Acc.Number : " << Client.GetAccountNumber(); 
		cout << "\n Balance  : " << Client.AccountBalance; 
		cout << "\n ___________________________________________";

	 }

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadNumber<string>();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadNumber<string>();
		}
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadNumber<double>();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadNumber<double>();
		}
		return Amount;
	}

public :  
	    
	void static ShowTransferScreen()
	{

		_DrawScreenHeader("\t Transfer Screen"); 
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber()); 
		_PrintClientCard(SourceClient);  

		
		
		clsBankClient DestinationsClient = clsBankClient::Find(_ReadAccountNumber()); 

		_PrintClientCard(DestinationsClient);

		double Amount = _ReadAmount(SourceClient);  


		cout << "\n Are You Sure You Want To Perform This Opiration ? y/n ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationsClient))
			{
				cout << "\n Transfer Done SuccessFully \n";

			}
			else
			{
				cout << "\n Transfer Failed \n";
			}
		}

		_PrintClientCard(SourceClient); 
		_PrintClientCard(DestinationsClient); 


	}
	
};

