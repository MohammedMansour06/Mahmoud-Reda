#pragma once
#include<iostream>  
#include"clsScreen.h"  
#include "clsInputValidate.h"  
#include"clsUser.h" 
#include"clsListUsersScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"  
#include"clsAddNewUserScreen.h"
#include<iomanip>  

using namespace std; 

class clsManageUsersScreen :protected clsScreen
{
private  :
	enum enManageUsersMenueOptions {
		eListUsers = 1 , eAddNewUsers= 2 , eDeleteUsers = 3, 
		eUpdateUsers =4  ,eFindUsers =5 , eMainMenue= 6 
	};

	static short ReadManageUsersMenueOptions()
	{
		short Choise = 0; 
		cout << "\n Choos What Do You To Do  ? "; 
		Choise = clsInputValidate::ReadNumberBetween<short>(1,6); 
		return Choise; 
	}



    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList(); 

    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen(); 

    }

    static void _ShowDeleteUserScreen()
    {
       
        clsDeleteClientScreen::showDeleteScreen(); 
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdatetoUserScreen(); 
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUsersScreen(); 
    }


	static void _PerformManageUsersMenueOptions(enManageUsersMenueOptions  ManageUsersMenueOptions)
	{
        switch (ManageUsersMenueOptions)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUsers:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUsers:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUsers:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUsers:
        {
            system("cls");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

    public  : 
        static void ShowManageUsersMenue()
        {

            system("cls");
            if (!CheckAccessRights(clsUser::pManageUsers))
            {
                return; 
            }
            _DrawScreenHeader("\t Manage Users Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Users.\n";
            cout << setw(37) << left << "" << "\t[2] Add New User.\n";
            cout << setw(37) << left << "" << "\t[3] Delete User.\n";
            cout << setw(37) << left << "" << "\t[4] Update User.\n";
            cout << setw(37) << left << "" << "\t[5] Find User.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerformManageUsersMenueOptions((enManageUsersMenueOptions)ReadManageUsersMenueOptions());
        }
	
};

