#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h";
#include "clsInputValidate.h"


class clsFindCurrencyScreen :protected clsScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency :";
        cout << "\n___________________";
        cout << "\nCountry       : " << Currency.Country();
        cout << "\nCurrency code : " << Currency.CurrencyCode();
        cout << "\Currency Name  : " << Currency.CurrencyName();
        cout << "\Rate           : " << Currency.Rate();
        cout << "\n___________________\n";
    }

    static string _ReadCurrencybyCode(string messsege)
    {
        cout << messsege;
        string CountryOrCodeName = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CountryOrCodeName))
        {
            cout << "the Currency is not found please try again :\n";
             CountryOrCodeName = clsInputValidate::ReadString();

        }
        return CountryOrCodeName;
            
    }

    static string _ReadCurrencyBycountry(string messsege)
    {
        cout << messsege;
        string CountryOrCodeName = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExistByCountry(CountryOrCodeName))
        {
            cout << "the Currency is not found please try again :\n";
            CountryOrCodeName = clsInputValidate::ReadString();

        }
        return CountryOrCodeName;

    }


public:
    static void FindCurrency()
    {
        string titile = "Find Currency Screen ";

        _DrawScreenHeader(titile);
        short Choise;
        cout << "Find By: [1] Code or [2] Country: ";
        Choise = clsInputValidate::ReadShortNumberBetween(1, 2, "enter number between 1 and 2:");

       
        if (Choise == 1)
        {
            string Code = _ReadCurrencybyCode("Enter Code Name: ");
            clsCurrency Currency = clsCurrency::FindByCode(Code);
            _PrintCurrency(Currency);
        }
        if (Choise == 2)
        {
            string Country = _ReadCurrencyBycountry("Enter Country Name: ");
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _PrintCurrency(Currency);
        }

    }
};

