#pragma once
#include<iostream>
#include"clsBankClient.h"  
#include"clsPerson.h" 
#include"clsScreen.h"  
#include"clsUser.h" 
#include"clsInputValidate.h"  


class clsUpdateClientScreen : protected clsScreen
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
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\n Enter First Name ? ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\n Enter Last Name ?  ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\n Enter Email  ?";
		Client.Email = clsInputValidate::ReadString();
		cout << "\n Enter Phone ? ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\n Enter Pin Code ? ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\n Enter Account Balance ? ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

public:

	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return; 
		}
		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber = "";
		cout << "\n Please Enter Account Number ? ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account NumberIs Not Found , please Enter Another One ? ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\n Are You Sure To Update This Client  ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\n Update Client Info : ";
			cout << "\n---------------------------------\n";

			_ReadClientInfo(Client1);

			clsBankClient::enSaveResult SaveResult;
			SaveResult = Client1.Save();

			switch (SaveResult)
			{
			case clsBankClient::enSaveResult::svSucceeded:
			{
				cout << "\n Client Updated SuccessFully :-) \n";
				break;
			}
			case clsBankClient::enSaveResult::svFailedEmptyObject:
			{
				cout << "\n  Error Client Updated ....\n ";
				break;
			}
			}
		}
	}

};


