#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h";

class clsListCurrencyScreen :protected clsScreen
{


    void static _PrintCurrencyList(clsCurrency Currency)
    {
        cout << "| " << left << setw(30) << Currency.Country();
        cout << "| " << left << setw(10) << Currency.CurrencyCode();
        cout << "| " << left << setw(40) << Currency.CurrencyName();
        cout << "| " << left << setw(10) << Currency.Rate();
       

    }
public:

    static void ShowCurrencyList()
    {
        vector <clsCurrency> VCurrency = clsCurrency::GetCurrenciesList();

        string titile = "Currency List Screen ";
        string subtitle = " (" + to_string(VCurrency.size()) + ") Currency(s)";

        _DrawScreenHeader(titile, subtitle);

        cout << "----------------------------------------------------------------------------";
        cout << "--------------------------------------------\n\n";
        cout << "| " << left << setw(30) << "Country ";
        cout << "| " << left << setw(10) << "Code ";
        cout << "| " << left << setw(40) << "Name ";
        cout << "| " << left << setw(10) << "Rate/(1$) ";
        cout << "\n---------------------------------------------------------------------------";
        cout << "--------------------------------------------\n\n";
        if (VCurrency.size() == 0)
        {
            cout << "\n\n\n No Currency available in the system: ";

        }
        else
        {
            for (clsCurrency& client : VCurrency)
            {
                _PrintCurrencyList(client);
                cout << endl;
            }
            cout << "\n-------------------------------------------------------------------------";
            cout << "-----------------------------------------------\n\n";
        }


    }


};

