#pragma once
#include<iostream>
#include"clsScreen.h"  
#include "clsInputValidate.h"
#include"clsBankClient.h"  

using namespace std; 

class clsWithdrawScreen : protected clsScreen 
{
private : 

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

	static void ShowWithDrawScreen()
	{
		_DrawScreenHeader("\t WithDraw Screen");  

		string AccountNumber = ""; 
		AccountNumber = _ReadAccountNumber(); 

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Client With [" << AccountNumber << "] Is Not Found , Please Enter Again ?"; 
			AccountNumber = _ReadAccountNumber(); 
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber); 

		_PrintClient(Client1); 

		double Amount = 0.0;  
		cout << "\n Please Enter WithDraw Amount ?"; 
		Amount = clsInputValidate::ReadNumber<double>();

		cout << "\n Are You Sure You Want To Perform This Transactions ?  "; 
		char Answer = 'n'; 
		cin >> Answer; 

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.WithDraw(Amount))
			{
				cout << "\n Amount with Draw SuccessFully .. \n ";
				cout << "\n New Balance  : " << Client1.AccountBalance << endl; 
			}
			else
			{
				cout << "\n Cannot WithDraw , Insuffecient Balance ! \n"; 
				cout << "\n Amount to WithDraw is " << Amount << endl; 
				cout << "Your Balance Is : " << Client1.AccountBalance;
			}
		}
		else
		{
			cout << "\n Operation Was Cancelled\n "; 
		}
	}
};

