#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

using namespace std;

class clsCurrencyCalculaterScreen : protected clsScreen
{
private: 

	static void _PrintCurrency(clsCurrency Currency, string Title = "Currency Card ")
	{
		cout << "\n" << Title << "\n";
		cout << "\n______________________________________________________________";
		cout << "\n Country           :  " << Currency.Country();
		cout << "\n Code              :  " << Currency.CurrencyCode();
		cout << "\n Name              :  " << Currency.CurrencyName();
		cout << "\n Rate(1$) =        :  " << Currency.Rate();
		cout << "\n______________________________________________________________\n";

	}

	static clsCurrency _GetCurrency(string Masseg)
	{

		string CurrencyCode = ""; 
		cout << Masseg << endl; 

		CurrencyCode = clsInputValidate::ReadNumber<string>();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n Currency Code Not Found , Enter Another Currency Code ? "; 
			CurrencyCode = clsInputValidate::ReadNumber<string>(); 
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode); 
		return Currency; 
	}

	static float _ReadAmount()
	{
		float Amount =0; 
		do
		{
			cout << "\n Enter Amount To Exchange ? "; 
		 Amount = clsInputValidate::ReadNumber<float>(); 
		} while (Amount <= 0); 
		return Amount; 
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrency(Currency1, "Convert From :");

		float AmountInUSD = Currency1.ConvertAmountToUsd(Amount);
		cout << "\n\n "; 
		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD \n"; 

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\n Converting From USD To : \n"; 
		_PrintCurrency(Currency2, "To:"); 

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2); 
		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();


	}

public : 

	static void ShowCurrencyCalculator()
	{
		char Continue = 'y'; 

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t Currency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code ? "); 
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code ? "); 
			float Amount = _ReadAmount(); 

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo); 

			cout << "\n\n Do You Want To Perform Another Calculations ? y/n ? "; 
			cin >> Continue; 

		}
		


	}
};

