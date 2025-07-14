#pragma once
#include<iostream>
#include"clsScreen.h" 
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include<iomanip>


using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:

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

	static void ShowAddNewClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return; 
		}
		_DrawScreenHeader("\t Add New Client Screen ");

		string AccountNumber = "";
		cout << "\n Please Enter Account Number ?";
		AccountNumber = clsInputValidate::ReadNumber<string>();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account Number Is Already Used , Choose Another Account Number ? ";
			AccountNumber = clsInputValidate::ReadNumber<string>();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);

		_ReadClientInfo(NewClient);
		clsBankClient::enSaveResult SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResult::svSucceeded:
		{
			cout << "\n Acount Added SuccessFully :-)\n";

			_PrintClient(NewClient);
			break;

		}
		case clsBankClient::enSaveResult::svFailedEmptyObject:
		{
			cout << "\n Error Account Was Not Saved Because It Is Empty ... \n";
			break;
		}
		}

	}
};



