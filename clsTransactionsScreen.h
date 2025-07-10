#pragma once

#include<iostream>
#include"clsScreen.h"  
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsUser.h"	 
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include<iomanip>  

using namespace std;
class clsTransactionsScreen	: protected clsScreen 
{
private : 
	enum enTransactionsMenueOptions {
		eDeposite  =1 , eWithDraw = 2 , eShowTotalBalance = 3 ,eShowTransferScreen=4
		,  eShowTransferLog=5,eShowMainMenue = 6 
	};
	static short ReadTransactionsOptions()
	{
		cout << setw(37) << left << "" << "Choose What Do You Want To Do ? ... [1 To 6] "; 
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6); 
		return Choice;
	}
	static void _GoBackToTransactionsMenueScreen()
	{
		cout << "\n Please Enter Any Key To Go Back To Transactions Menue Screen .... ";  
		system("pause>0"); 
			ShowTransactionsMenue(); 

	}

	static void _ShowDepositeScreen()
	{
		clsDepositScreen::ShowDepositeScreen(); 
	}  

	static void _ShowWithDrawScreen()
	{
		clsWithdrawScreen::ShowWithDrawScreen(); 
	}

	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances(); 
	}

	static void _ShowTransferScreen()
	{
	
		clsTransferScreen::ShowTransferScreen(); 
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen(); 
	}

	

	static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions TransactionsMenueOptions)
	{
		switch (TransactionsMenueOptions)
		{
		case enTransactionsMenueOptions ::eDeposite  :
		{
			system("cls"); 
			_ShowDepositeScreen();
			_GoBackToTransactionsMenueScreen(); 
			break;

		}
		case enTransactionsMenueOptions::eWithDraw:
		{
			system("cls");  
			_ShowWithDrawScreen(); 
			_GoBackToTransactionsMenueScreen();  
			break; 
		}
		case enTransactionsMenueOptions::eShowTotalBalance  :
		{
			system("cls"); 
			_ShowTotalBalanceScreen(); 
			_GoBackToTransactionsMenueScreen(); 
			break;
		}
		case enTransactionsMenueOptions::eShowTransferScreen : 
		{
			system("cls");
			_ShowTransferScreen(); 
			_GoBackToTransactionsMenueScreen();
			break;

		}
		case enTransactionsMenueOptions::eShowTransferLog:
		{
			system("cls"); 
			_ShowTransferLogScreen(); 
			_GoBackToTransactionsMenueScreen(); 
			break;
		}
		
		case enTransactionsMenueOptions::eShowMainMenue:
		{
		

		}
	   }
	}

public  : 
	static void ShowTransactionsMenue()
	{
		system("cls");  
		
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return; 
		}
		_DrawScreenHeader("\t Transactions Screen ");

		cout << setw(37) << left << "" << "========================================================\n"; 
		cout << setw(37) << left << "" << "\t\t Transactions Menue \n "; 
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t [1] Deposite \n "; 
		cout << setw(37) << left << "" << "\t [2] WithDraw \n";
		cout << setw(37) << left << "" << "\t [3] Total Balance \n "; 
		cout << setw(37) << left << "" << "\t [4] Transfer \n ";
		cout << setw(37) << left << "" << "\t [5] Transfer Log \n"; 
		cout << setw(37) << left << "" << "\t [6] Main Menue \n ";
		cout << setw(37) << left << "" << "========================================================\n";

		_PerformTransactionsMenueOptions((enTransactionsMenueOptions)ReadTransactionsOptions()); 
	}
};

