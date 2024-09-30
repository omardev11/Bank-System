#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsGlobal.h"
#include "clsLoginRegisterScreen.h"


class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FailedToLogincount = 0;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FailedToLogincount++;
                cout << "\nInvlaid Username/Password!\n";
                cout << "You Have " << 3-(FailedToLogincount) << " Trials to Login\n\n";
            }
            if (FailedToLogincount == 3)
            {
                cout << "\nYour Are Locked After 3 Fails Trails" << endl;
                return false;

            }
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
            
        

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();

    }

public:

    
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
        
    }

};

