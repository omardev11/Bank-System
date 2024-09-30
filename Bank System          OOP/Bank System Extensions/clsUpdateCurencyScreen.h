#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h";
#include "clsInputValidate.h"


class clsUpdateCurencyScreen :protected clsScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency :";
        cout << "\n___________________";
        cout << "\Country       : " << Currency.Country();
        cout << "\Currency Code : " << Currency.CurrencyCode();
        cout << "\Currency Name : " << Currency.CurrencyName();
        cout << "\Rate          : " << Currency.Rate();
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
    static void UpdateCurrency()
    {
        string titile = "Update Currency Screen ";

        _DrawScreenHeader(titile);
    
        double NewRate = 0;
        string Code = _ReadCurrencybyCode("Please Enter Currency Code: ");
        clsCurrency Currency = clsCurrency::FindByCode(Code);

        _PrintCurrency(Currency);
        if (clsInputValidate::AreYouSure("Are You Sure You want to update the rate of this curency y/n"))
        {
            cout << "Update Currency Rate: \n\n";
            cout << "_______________________________\n\n";
            cout << "Enter New Rate: ";
            cin >> NewRate;
            Currency.UpdateRate(NewRate);
            cout << "Currency Rate Updated Sucesfully :-) \n\n";
            _PrintCurrency(Currency);

        }


      

    }
};

