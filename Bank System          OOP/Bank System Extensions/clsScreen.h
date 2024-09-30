#pragma once
#include <iostream>
#include "clsUser.h";
#include "clsGlobal.h"
#include "clsDate.h";


using namespace std;

class clsScreen /*protected clsDate*/
{
public:
   
protected:
    
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        clsDate date = clsDate::GetSystemDate();
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser:  " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << endl << endl;

    }


    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }


    };
};

