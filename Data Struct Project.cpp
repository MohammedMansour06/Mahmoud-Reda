


#include <iostream>
using namespace std; 
#include"clsMyStackArr.h"
#include"clsMyString.h"
#include"clsMyStackArr.h"
#include"clsQueueLine.h"
#include"clsDynamicArray.h"

int main()
{
	clsQueueLine PayBillsQueue("A0" , 10);  
	 
	PayBillsQueue.IssueTicket(); 
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	PayBillsQueue.PrintInfo(); 

	PayBillsQueue.PrintTicketsLineRTL();

	PayBillsQueue.PrintTicketsLineLTR(); 

	PayBillsQueue.PrintAllTickets(); 

	
	



	


  
}


