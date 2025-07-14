#pragma once
#include<iostream> 

#include"clsScreen.h"
#include"clsUser.h"	  
#include"clsPerson.h"  
#include"clsInputValidate.h"  
  

using namespace std; 


class clsDeleteUserScreen  : protected clsScreen 
{
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
public : 
	 
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t Delete User Screen ");
		string UserName = ""; 

		UserName = clsInputValidate::ReadNumber<string>();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n User Not Founded ... Enter Another userName ?  "; 
			UserName = clsInputValidate::ReadNumber<string>();
		}

		clsUser User1 = clsUser::Find(UserName); 
		_PrintUser(User1); 

		cout << "\n Are You Want To Delete This User ? "; 
		char Answer = 'n';  
		cin >> Answer;  
		if (Answer == 'y' || Answer == 'Y')
		{
			if (User1.Delete())
			{
				cout << "\n User Deleted SuccessFully :-) \n "; 
				_PrintUser(User1); 
			}
			else
			{
				cout << "\n Error User Not Deleted ... \n "; 
			}
		}
	}
};

