#pragma once
#include<iostream>
#include"clsScreen.h"  
#include"clsInputValidate.h"
#include"clsBankClient.h"


class clsDepositScreen	: protected clsScreen
{
private  :

	static void _PrintClient(clsBankClient Client)
	{

		cout << "\n Client Card : ";
		cout << "\n ---------------------------------------------";
		cout << "\n First Name           : " << Client.FirstName;
		cout << "\n Last Name            : " << Client.LastName;
		cout << "\n Full Name            : " << Client.FullName();
		cout << "\n Email                : " << Client.Email;
		cout << "\n Phone                : " << Client.Phone;
		cout << "\n Acc. Number          : " << Client.GetAccountNumber();
		cout << "\n PassWord             : " << Client.PinCode;
		cout << "\n Balance              : " << Client.AccountBalance;
		cout << "\n ---------------------------------------------";


	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = ""; 

			cout << "\n Please Enter Account Number ? "; 
			cin >> AccountNumber; 
			return AccountNumber; 
	}

public :

	static void ShowDepositeScreen()
	{
		_DrawScreenHeader("\t Deposite Screen "); 


		string AccountNumber = "";
		AccountNumber = _ReadAccountNumber();  

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Client With [" << AccountNumber << "] Does Not Found ... "; 
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber); 
		_PrintClient(Client1); 

		double Amount = 0.0; 
		cout << "\n Please Enter Deposite Amount ? ";  
		Amount = clsInputValidate::ReadDblNumber(); 

		cout << "\n Are You Sure You Want To Perform This Transactions ?  "; 
		char Answer = 'n'; 
		cin >> Answer;  

		if (Answer == 'y' || Answer == 'Y')
		{
			Client1.Deposite(Amount); 
			cout << "\n Amount Deposited SuccessFully . \n ";  
			cout << "\n New Balance Is " << Client1.AccountBalance; 
		}
		else
		{
			cout << "\n Operation Was Cancelled \n "; 
		}


	}
};

