#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h";
#include "clsMainScreen.h";
#include "clsDepositScreen.h";
#include "clsWhithdrawScreen.h";
#include "clsTotalBalance.h";
#include "clsTransferScreen.h"
#include "clsTransferRegisterScreen.h"
using namespace std;


class clsTransactionsScreen :protected clsScreen
{
    enum enTransactionMenueOptions {
        Deposit = 1, whithdraw = 2, totalbalance = 3, Transfer = 4,

        TransferLog = 5, mainMenu = 6
    };

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowtTransactionMenue();
    }


    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _DepositScreen()
    {
       // cout << "\nClient List Screen Will be here...\n";
        clsDepositScreen::ShowDepositScreen();


    }

    static void _WhithDrawScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
        clsWhithdrawScreen::ShowWhithdrawScreen();
    }

    static void _TotalBalanceScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsTotalBalance::ShowtotalBalance();
    }

    static void _TransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _TransferRegisterScreen()
    {
        clsTransferRegisterScreen::ShowTransferRegisterScreen();
    }

    

    

    static void _PerfromMainMenueOption(enTransactionMenueOptions TransactionMenueOption)
    {
        switch (TransactionMenueOption)
        {
        case enTransactionMenueOptions::Deposit:
        {
            system("cls");
            _DepositScreen();
            _GoBackToMainMenue();
            break;
        }
        case enTransactionMenueOptions::whithdraw:
        {  system("cls");
        _WhithDrawScreen();
        _GoBackToMainMenue();
        break;
        }
        case enTransactionMenueOptions::totalbalance:
        {  system("cls");
        _TotalBalanceScreen();
        _GoBackToMainMenue();
        break;
        }
        case enTransactionMenueOptions::Transfer:
        {  system("cls");
        _TransferScreen();
        _GoBackToMainMenue();
        break;
        }
        case enTransactionMenueOptions::TransferLog:
        {  system("cls");
        _TransferRegisterScreen();
        _GoBackToMainMenue();
        break;
        }
        case enTransactionMenueOptions::mainMenu:
        {  
            break;
        }
       

            
        }

    }


public:

    static void ShowtTransactionMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tTransaction Screen ");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit .\n";
        cout << setw(37) << left << "" << "\t[2] WhithDraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer .\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enTransactionMenueOptions)_ReadMainMenueOption());
    }

};

