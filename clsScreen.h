#pragma once
#include <iostream>
#include"clsUser.h" 
#include"clsDate.h" 
#include<string>
#include"Global.h"


using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
    
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUser : " << CurrentUser.UserName ;

        clsDate Date = clsDate::GetSystemDate();


        cout << "\n\t\t\t\t\tDate : ";
        Date.Print();
        cout << "\n\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permissions)
    {
        if (!CurrentUser.CheckAccessPermissions(Permissions))
        {
            cout << "\t\t\t\t\t_________________________________________________________________";
            cout << "\n\n\t\t\t\t\t\  You Cant Access To This Page .....\n ";
            cout << "\n\t\t\t\t\t_________________________________________________________________";
            return false; 
      }                     
        else
        {
            return true; 
        }
    }

  

};


