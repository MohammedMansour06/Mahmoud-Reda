

#include <iostream>
#include"clsLoginScreen.h"  
//#include"clsMainScreen.h"

using namespace std; 

int main()
{
	//clsMainScreen::ShowMainMunueScreen(); 
	
	
	while (true)
	{
		
		if (!clsLoginScreen::ShowLoginnScreen())
		{
			break;  
		}
		
	

	}

	system("pause>0"); 
	return 0;
}


