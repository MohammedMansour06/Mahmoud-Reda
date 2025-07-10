
#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h" 
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsScreen.h"
#include"Global.h"  

using namespace std;

class clsMainScreen : protected clsScreen
{
	enum enMainMenueOption {
		eListClient = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUser = 7,eLoginRegister = 8  ,eExit = 9
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose What Do You Want to do [1 to  9 ]  ? ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number Between 1 and 9 ?  ");
		return Choise;
	}
	static void _ShowAllClientScreen()
	{
		clsClientListScreen::ShowClientsList(); 

	}
	static void _ShowAddNewClientList()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::showDeleteScreen();
	}
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowFindClientList()
	{
		clsFindClientScreen::ShowFindClientScreen(); 
	}
	static void _ShowTransactionsMenue()
	{
		clsTransactionsScreen::ShowTransactionsMenue(); 
	}
	static void _ShowManageUserScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenue();
	}
	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void _LogOut()
	{
		CurrentUser = clsUser::Find("", ""); 
		// clsLoginScreen::ShowLoginnScreen(); ---> Circular Refrences ; 

	}
	static void _ShowGoBackTomainMenueScreen()
	{
		cout << "\n PLease Enter Any Key To Go Back To Main Menue ......" << endl;
		system("pause>0");
		ShowMainMunueScreen();
	}

	static void _PerformMainMenueOption(enMainMenueOption MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOption::eListClient:
		{
			system("cls");
			_ShowAllClientScreen();
			_ShowGoBackTomainMenueScreen();
			break;
		}
		case enMainMenueOption::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientList();
			_ShowGoBackTomainMenueScreen();
			break;
		}
		case enMainMenueOption::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_ShowGoBackTomainMenueScreen();
			break;
		}
		case enMainMenueOption::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_ShowGoBackTomainMenueScreen();

			break;
		}
		case enMainMenueOption::eFindClient:
		{
			system("cls");
			_ShowFindClientList();
			_ShowGoBackTomainMenueScreen();
			break;

		}
		case enMainMenueOption::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsMenue();
			_ShowGoBackTomainMenueScreen();
			break;

		}
		case enMainMenueOption::eManageUser:
		{
			system("cls");
			_ShowManageUserScreen();
			_ShowGoBackTomainMenueScreen();
			break;
		}
		case enMainMenueOption::eLoginRegister  :
		{
			system("cls"); 
			_ShowLoginRegisterScreen(); 
			_ShowGoBackTomainMenueScreen(); 
			break; 
		}
		case enMainMenueOption::eExit:
		{
			system("cls");
			_LogOut(); 
			break;
		}
		}
	}

public:
	static void ShowMainMunueScreen()
	{
		system("cls");

		_DrawScreenHeader("\t\t Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register\n";
		cout << setw(37) << left << "" << "\t[9] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenueOption((enMainMenueOption)_ReadMainMenueOption());
	}


};






