
#pragma once
#include<iostream>
#include"clsScreen.h" 
#include"clsBankClient.h"  
#include"clsPerson.h"  
#include"clsUser.h"
#include"clsInputValidate.h"  


class clsDeleteClientScreen :protected clsScreen
{
private:
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
	static void showDeleteScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return; 
		}
		_DrawScreenHeader("\t Delete Client Screen ");

		string AccountNumber = "";
		cout << "\n Please Enter Account Number ?";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account Number IS NOT Found   , Choose Another Account Number ? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\n Are you Sure To Delete This Client ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Delete())
			{
				cout << "\n Client Deleted successFully :_) \n";
				_PrintClient(Client1);
			}
			else
			{
				cout << "\n Error client Was Not Deleted ... \n";
			}
		}


	}
};



