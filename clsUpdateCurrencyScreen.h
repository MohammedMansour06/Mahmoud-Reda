#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurrency.h"

using namespace std; 
class clsUpdateCurrencyScreen  : protected clsScreen
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
	static float _ReadRate()
	{
		cout << "\n Enter New Rate ? "; 
		float NewRate = 0; 

		NewRate = clsInputValidate::ReadNumber<float>(); 
		return NewRate; 
	}

		
	

public: 

	static void _ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\t Update Currency Screen"); 

		string CurrencyCode = ""; 
		cout << "\n Please Enter Currency Code ? "; 
		CurrencyCode = clsInputValidate::ReadNumber<string>();
	
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n Currency Code Not Found , Enter Another one ? "; 
			CurrencyCode = clsInputValidate::ReadNumber<string>();;
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency1);

		cout << "\n\n Are You Sure You Want To Update The Rate Of This Currency ? y/n"; 
		char Answer = 'n'; 
		cin >> Answer; 
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\n\n Update Currency Rate : \n";
			cout << "_____________________________\n"; 
			
		
			Currency1.UpdateRate(_ReadRate()); 
			cout << "\n\n Currency Rate Updated SuccessFully :-)\n"; 

			cout << "\n\n Currency Card : \n\n ";
			_PrintCurrency(Currency1); 

		}

	}
};

