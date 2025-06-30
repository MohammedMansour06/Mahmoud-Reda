

#include <iostream>
#include"clsBankClient.h"

using namespace std; 

int main()
{
	clsBankClient Client = clsBankClient::Find("A101");
	Client.Print(); 

	clsBankClient Client2 = clsBankClient::Find("A101", "123456"); 
	Client2.Print(); 


}
