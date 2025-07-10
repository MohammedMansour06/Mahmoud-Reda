#pragma once
#include<iostream>  
#include"clsBankClient.h"  
#include"clsInputValidate.h"
#include"clsPerson.h"
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;
class clsFindClientScreen :protected clsScreen
{
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

public:

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return; 
		}
		_DrawScreenHeader("\t Find Client Screen ");

		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n The Account Number Is Not Founded , Enter Another Account Number ? ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\n Client Found :-)\n";
		}
		else
		{
			cout << "\n Client Not Found \n";
		}

		_PrintClient(Client1);
	}
};

