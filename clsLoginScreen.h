#pragma once
#include<iostream> 	 
#include<iomanip>  
#include"clsScreen.h"   
#include"clsMainScreen.h"
#include"fstream"
#include"clsUser.h"
#include<vector>
#include"clsDate.h"	 
#include"Global.h"  

using namespace std;
class clsLoginScreen :protected clsScreen
{
	
	
	static bool  _Login()
	{
		
		bool LoginFailed = false;
		short FailedToLoginCount = 0; 
		

		string UserName, PassWord; 
		do {

			if (LoginFailed)
			{
				FailedToLoginCount++;

				cout << "\n Invlaid UserName/PassWord \n";
				cout << " You Have " << (3 - FailedToLoginCount ) << "  Trials To Login \n\n"; 
			}
			if (FailedToLoginCount == 3)
			{
				cout << "\n You are Locked After 3 Failed Trials To Login  \n\n"; 
				return false; 
			}
			cout << "\n Enter UserName ? "; 
			cin >> UserName; 

			cout << "\n Enter PassWord  ?"; 
			cin >> PassWord; 

			CurrentUser = clsUser::Find(UserName, PassWord); 

			LoginFailed = CurrentUser.IsEmpty();
			
		} while (LoginFailed);

		CurrentUser.RegisterLogin();  
		clsMainScreen::ShowMainMunueScreen();
		return true;

	  }



public  :

	static bool ShowLoginnScreen()
	{
		system("cls"); 
		_DrawScreenHeader("\t Login Screen");
		
		 return _Login(); 
	}
};

