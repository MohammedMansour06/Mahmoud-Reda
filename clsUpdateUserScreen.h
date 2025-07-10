#pragma once
#include<iostream>
#include"clsInputValidate.h"  
#include"clsScreen.h" 
#include"clsUser.h"	 
#include"clsPerson.h"  

using namespace std;  

class clsUpdateUserScreen : protected clsScreen 
{

private : 

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';
		cout << "\n Do You Want To Give Full Access ? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}
		cout << "\n Do You Want To Give Access To : \n ";
		cout << "\n Show Client List ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}
		cout << "\n Add New Clients  ? y/n \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\n Delete Client  ?y/n  \n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}
		cout << "\n Update Clients ?y/n \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}
		cout << "\n Find Clients ?y/n \n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}
		cout << "\n Transactions ? y/n \n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;

		}
		cout << "\n Manage User ? y/n \n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}
		return Permissions;

	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\n Enter First Name ? ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\n Enter Last Name ?  ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\n Enter Email  ?";
		User.Email = clsInputValidate::ReadString();
		cout << "\n Enter Phone ? ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\n Enter PassWord ? ";
		User.PassWord = clsInputValidate::ReadString();
		cout << "\n Enter Permissions  ? ";
		User.Permissions = _ReadPermissionsToSet();
	}

	static void _PrintUser(clsUser User)
	{

		cout << "\n Client Card : ";
		cout << "\n ---------------------------------------------";
		cout << "\n First Name           : " << User.FirstName;
		cout << "\n Last Name            : " << User.LastName;
		cout << "\n Full Name            : " << User.FullName();
		cout << "\n Email                : " << User.Email;
		cout << "\n Phone                : " << User.Phone;
		cout << "\n Acc. Number          : " << User.UserName;
		cout << "\n PassWord             : " << User.PassWord;
		cout << "\n Balance              : " << User.Permissions;
		cout << "\n ---------------------------------------------";


	}

public  : 

	static void ShowUpdatetoUserScreen()
	{
		_DrawScreenHeader("\t Update User Screen"); 

		string UserName = "";  

		UserName = clsInputValidate::ReadString(); 

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n UserName Is Not Found ... Enter Another ? "; 
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName); 
		_PrintUser(User1); 

		cout << "\n \n Are You Sure To Update This User ? ";  
		char Answer = 'n'; 
		cin >> Answer; 

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n \n Update User Info : "; 
			cout << "\n -------------------------\n"; 

			_ReadUserInfo(User1); 
             
			clsUser::enSaveResult SaveResult; 
			SaveResult = User1.Save(); 

			switch (SaveResult)
			{
			case clsUser::enSaveResult ::svSucceeded  :
			{
				cout << "\n User Updated SuccessFully :-) \n"; 
				_PrintUser(User1); 
				break; 
			}
			case clsUser::enSaveResult::svFailedEmptyObject  :
			{
				cout << "\n Error Update, Because The User Is Empty .... \n ";  
				break; 
			}
		
			}
		}

		 }
};

