#pragma once

#include<iostream>  
#include"clsScreen.h" 
#include"clsInputValidate.h"   
#include"clsPerson.h"   
#include "clsUser.h"   

using namespace std; 

class clsFindUserScreen	 : protected clsScreen
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

public  : 

	static void ShowFindUsersScreen()
	{
		_DrawScreenHeader("\t Find User Screen"); 

		string UserName = ""; 
		UserName = clsInputValidate::ReadNumber<string>();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n UserName Not Found , Enter Another ?  "; 
			UserName = clsInputValidate::ReadNumber<string>();
		}

		clsUser User1 = clsUser::Find(UserName); 

		if (!User1.IsEmpty())
		{
			cout << "\n User Found :-)\n"; 
		}
		else
		{
			cout << "\n User Doesnt Found\n "; 

		}
		_PrintUser(User1); 
	   }

};

