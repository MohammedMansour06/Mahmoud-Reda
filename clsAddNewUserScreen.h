#pragma once
#include<iostream>  
#include "clsScreen.h"  
#include"clsUser.h"
#include "clsInputValidate.h"  


using namespace std; 
class clsAddNewUserScreen : protected clsScreen
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

		cout << "\n Show Login Register ? y/n ? \n"; 
		cin >> Answer; 
		if (Answer == 'Y' || Answer == 'y')
		{
			Permissions += clsUser::enPermissions::pShowLoginRegister; 
		}
		return Permissions;  

	}
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\n Enter First Name ? ";
		User.FirstName = clsInputValidate::ReadNumber<string>();
		cout << "\n Enter Last Name ?  ";
		User.LastName = clsInputValidate::ReadNumber<string>();
		cout << "\n Enter Email  ?";
		User.Email = clsInputValidate::ReadNumber<string>();
		cout << "\n Enter Phone ? ";
		User.Phone = clsInputValidate::ReadNumber<string>();
		cout << "\n Enter PassWord ? ";
		User.PassWord = clsInputValidate::ReadNumber<string>();
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
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\ Add New User Screen "); 

		string UserName = ""; 
		cout << "\n Please Enter User Name ? "; 
		UserName = clsInputValidate::ReadNumber<string>();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\n User Name Is Already Exist , Enter Another ? ";
			UserName = clsInputValidate::ReadNumber<string>();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);  
		_ReadUserInfo(NewUser); 

		clsUser::enSaveResult SaveResult; 
		SaveResult = NewUser.Save();  

		switch (SaveResult)
		{
		case clsUser::enSaveResult ::svSucceeded  :
		{
			cout << "\n User Added SuccessFully :-) \n"; 
			_PrintUser(NewUser); 
			break; 
			
		}
		case clsUser::enSaveResult::svFailedEmptyObject :
		{
			cout << "\n Error User Was Not Saved Because Its Empty ...."; 
			break; 
		}
		case clsUser::enSaveResult::svFailedUserExist  :
		{
			cout << "\n Error User Was not Saved Because UserName Is Used ! \n"; 
			break; 
		}
		}


	}
};

