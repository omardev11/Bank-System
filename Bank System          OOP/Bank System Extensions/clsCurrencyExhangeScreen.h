#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h";
#include "clsMainScreen.h";
#include "clsListCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;

class clsCurrencyExhangeScreen :protected clsScreen
{

    enum enCurrencyMenueOptions {
        ListCurrency = 1, FindCurrency = 2, UpdateRate = 3, CurrencyCalculator = 4,

        mainMenu = 5
    };

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowtCurrencyMenue();
    }


    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _ShowListCurrency()
    {
        clsListCurrencyScreen::ShowCurrencyList();


    }

    static void _ShowFindCurrency()
    {
        clsFindCurrencyScreen::FindCurrency();
    }

    static void _ShowUpdateRate()
    {
        clsUpdateCurencyScreen::UpdateCurrency();
    }

    static void _ShowCurrencyCalculator()
    {
        clsCurrencyCalculatorScreen::CalculateCurrency();
    }






    static void _PerfromMainMenueOption(enCurrencyMenueOptions TransactionMenueOption)
    {
        switch (TransactionMenueOption)
        {
        case enCurrencyMenueOptions::ListCurrency:
        {
            system("cls");
            _ShowListCurrency();
            _GoBackToMainMenue();
            break;
        }
        case enCurrencyMenueOptions::FindCurrency:
        {  system("cls");
        _ShowFindCurrency();
        _GoBackToMainMenue();
        break;
        }
        case enCurrencyMenueOptions::UpdateRate:
        {  system("cls");
        _ShowUpdateRate();
        _GoBackToMainMenue();
        break;
        }
        case enCurrencyMenueOptions::CurrencyCalculator:
        {  system("cls");
        _ShowCurrencyCalculator();
        _GoBackToMainMenue();
        break;
        }
        case enCurrencyMenueOptions::mainMenu:
        {
            break;
        }



        }

    }


public:

    static void ShowtCurrencyMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\Currency Exchange Main Screen ");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Curency .\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator .\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enCurrencyMenueOptions)_ReadMainMenueOption());
    }
};

