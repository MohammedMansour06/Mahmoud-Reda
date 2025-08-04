#pragma once
#include<iostream>  
#include<queue>
#include<stack>
#include<string>
#include"clsDate.h"
#include<iomanip>
using namespace std;


class clsQueueLine
{
private: 

	short _TotalTickets = 0; 
	short _AvaregServeTime = 0; 
	string _Prefix = "";

	class clsTicket {

		short _Number = 0; 
		string _Prefix; 
		string _TicketTime; 
		short _WaitingClients = 0;
		short _AvaregServeTime = 0;  
		short _ExpectedServetime; 

	public  :  

		clsTicket(string Prefix, short Number, short WaitingClients, short AvaregServeTime)
		{
			_Number = Number;  
			_TicketTime = clsDate::GetSystemDateTimeString(); 
			_Prefix = Prefix; 
			_WaitingClients = WaitingClients; 
			_AvaregServeTime = AvaregServeTime; 
		}
		string Prefix()
		{
			return _Prefix; 
		}
		short  Number()
		{
			return _Number; 
		}
		string FullNumber()
		{
			return _Prefix + to_string(_Number); 
		}
		string TicketTime()
		{
			return _TicketTime; 
		}
		short WaitingClients()
		{
			return _WaitingClients; 
		}
		short ExpectedServeTime()
		{
			return _AvaregServeTime * _WaitingClients;
		}

		void Print()
		{
			cout << "\n\t\t\t ____________________________\n";
			cout << "\n\t\t\t     " << FullNumber(); 
			cout << "\n\t\t\t     " << _TicketTime; 
			cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients; 
			cout << "\n\t\t\t      Serve Time In ";
			cout << "\n\t\t\t        " << ExpectedServeTime() << " Minutes "; 
			cout << "\n\t\t\t ____________________________\n";			 
		}
	};
	
public  : 
	queue <clsTicket> QueueLine; 

	clsQueueLine(string Prefix, short AvaregServeTime)
	{
		_Prefix = Prefix; 
		_TotalTickets = 0;
		_AvaregServeTime = AvaregServeTime; 
	}

	void IssueTicket()
	{
		_TotalTickets++; 
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AvaregServeTime);  
		QueueLine.push(Ticket); 

	}

	int WaitingClients()
	{
		return QueueLine.size(); 
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			return  "\n No Client Left .\n";
		else
			return QueueLine.front().FullNumber();
	}

	bool ServerNextClient()
	{
		if (QueueLine.empty())
			return false;
		else
			QueueLine.pop();
		return true;
	}

	short ServedClients()
	{
		return _TotalTickets - QueueLine.size(); 
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t ____________________________\n";  
		cout << "\n\t\t\t\tQueue Info ";  
		cout << "\n\t\t\t ____________________________\n";
		cout << "\n\t\t\t     Prefix          = " << _Prefix;	  
		cout << "\n\t\t\t     Total Tickets   = " << _TotalTickets; 
		cout << "\n\t\t\t     Served Clients  = " << ServedClients(); 
		cout << "\n\t\t\t     Waiting Clients = " << WaitingClients(); 
		cout << "\n\t\t\t ____________________________\n";  
		cout << "\n";

	}

	void PrintTicketsLineRTL()
	{
		queue<clsTicket> TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			clsTicket Ticket = TempQueueLine.front();
			cout << " " << Ticket.FullNumber() << " <-- ";
			TempQueueLine.pop(); 
		}
		cout << "\n";
		
	}

	void PrintTicketsLineLTR()
	{
		queue<clsTicket> TempQueueLine = QueueLine;
		stack<clsTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front()); 
			TempQueueLine.pop(); 
		}

		while (!TempStackLine.empty())
		{
			clsTicket Ticket = TempStackLine.top(); 
			cout << " " << Ticket.FullNumber() << " --> "; 
			TempStackLine.pop(); 
		}
		cout << "\n"; 

	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t          ---Tickets---";

		if (QueueLine.empty())
		cout << "\n\n\t\t\t     ---No Tickets---\n";



			queue<clsTicket> TempQueueLine = QueueLine;

			while (!TempQueueLine.empty())
			{
				TempQueueLine.front().Print(); 
				TempQueueLine.pop(); 
			}
		
	}

};

