#pragma once
#include<iostream>  
#include"clsScreen.h"  
#include"clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen	  : protected clsScreen
{
private:



	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\n______________________________________________________________"; 
		cout << "\n Country           :  " << Currency.Country();  
		cout << "\n Code              :  " << Currency.CurrencyCode(); 
		cout << "\n Name              :  " << Currency.CurrencyName(); 
		cout << "\n Rate(1$) =        :  " << Currency.Rate();
		cout << "\n______________________________________________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n Currency Found :-) \n";
			_PrintCurrency(Currency);
		}
		else
			cout << "\n Currency Was Not Found \n ";
	}

public: 

	static void _ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");
		cout << "\n Find By : [1] Code Or [2] Country ? ";
		short Choise = 1; 
		cin >> Choise; 

		if (Choise == 1)
		{
			string CurrencyCode = ""; 
			cout << "\n Please Enter CurrencyCode ? "; 
			CurrencyCode =clsInputValidate::ReadNumber<string>();
			clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency1); 
	       
		}
		else
		{

			string CurrencyCountry = "";
			cout << "\n Please Enter CountryName ? ";
			CurrencyCountry = clsInputValidate::ReadNumber<string>();
			clsCurrency Currency2 = clsCurrency::FindByCountry(CurrencyCountry);
			_ShowResults(Currency2); 

		}
	}
};

