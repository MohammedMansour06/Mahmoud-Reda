
#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{

public:

	template<typename T>
	static bool IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	

	static  double ReadPositiveNum()
	{
		double Num = 0;
		cin >> Num; 
		if (Num <= 0)
		{
			cout << "\n Negative Number , Please Enter a Positive Number ? "; 
			cin >> Num; 
		}
		return Num; 
	  }

	

	
	  template<typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	template<typename T>
	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadNumber<T>(ErrorMessage);

		while (!IsNumberBetween<T>(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<T>(ErrorMessage);
		}
		return Number;
	}



	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	
};

