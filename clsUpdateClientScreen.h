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
		Client.FirstName = clsInputValidate::ReadNumber<string>();
		cout << "\n Enter Last Name ?  ";
		Client.LastName = clsInputValidate::ReadNumber<string>();
		cout << "\n Enter Email  ?";
		Client.Email = clsInputValidate::ReadNumber<string>();
		cout << "\n Enter Phone ? ";
		Client.Phone = clsInputValidate::ReadNumber<string>();
		cout << "\n Enter Pin Code ? ";
		Client.PinCode = clsInputValidate::ReadNumber<string>();
		cout << "\n Enter Account Balance ? ";
		Client.AccountBalance = clsInputValidate::ReadNumber<float>();
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
		AccountNumber = clsInputValidate::ReadNumber<string>();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account NumberIs Not Found , please Enter Another One ? ";
			AccountNumber = clsInputValidate::ReadNumber<string>();
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


