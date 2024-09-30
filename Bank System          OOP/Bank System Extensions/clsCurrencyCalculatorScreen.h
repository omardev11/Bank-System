#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h";
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen
{

    static void _PrintCurrency(clsCurrency Currency, string messege)
    {
        cout << messege << endl;
        cout << "\n___________________";
        cout << "\nCountry       : " << Currency.Country();
        cout << "\nCurrency Code : " << Currency.CurrencyCode();
        cout << "\nCurrency Name : " << Currency.CurrencyName();
        cout << "\nRate          : " << Currency.Rate();
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

    static void _PrintCalculationResult(double amount, clsCurrency Currency1, clsCurrency Currency2)
    {
        _PrintCurrency(Currency1, "\nConvert from:");
        double AmountInUSD = Currency1.ConvertToUSD(amount);
        cout << "\n\n" << amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD "
            << endl << endl;
        if ((Currency2.CurrencyCode() == "USD"))
        {
            return;
        }
        cout << "Converting From USD to: \n";
        _PrintCurrency(Currency2, "\nTo: ");
        double AmounINCurrency2 = Currency1.ConvertToatherCurrency(amount, Currency2);
        cout << "\n\n" << amount << " " << Currency1.CurrencyCode() << " = " << AmounINCurrency2 << " " << Currency2.CurrencyCode()
            << endl << endl;



    }


public:
    static void CalculateCurrency()
    {
        string titile = "Update Currency Screen ";


        double Amount = 0;
        double AmountAfterExchange = 0;
        double AmountAfterSecondExchange = 0;
        do
        {
            system("cls");
            _DrawScreenHeader(titile);
            string Code1 = _ReadCurrencybyCode("Please Enter Currency1 Code: ");
            clsCurrency Currency1 = clsCurrency::FindByCode(Code1);

            string Code2 = _ReadCurrencybyCode("\nPlease Enter Currency2 Code: ");
            clsCurrency Currency2 = clsCurrency::FindByCode(Code2);

            cout << "Enter Amount to Exchange : ";
            cin >> Amount;

            _PrintCalculationResult(Amount, Currency1, Currency2);

           /* _PrintCurrency(Currency1, "\nConvert from:");
            if (Currency1.CurrencyCode() == "USD" && !(Currency2.CurrencyCode() == "USD"))
            {
                AmountAfterExchange = Amount * Currency2.Rate();
                cout << "\n\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountAfterExchange << " " << Currency2.CurrencyCode()
                    << endl << endl;
            }
            if (!(Currency1.CurrencyCode() == "USD") && Currency2.CurrencyCode() == "USD")
            {
                AmountAfterExchange = Amount / Currency1.Rate();
                cout << "\n\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountAfterExchange << " " << Currency2.CurrencyCode()
                    << endl << endl;
            }
            if (!(Currency1.CurrencyCode() == "USD") && !(Currency2.CurrencyCode() == "USD"))
            {
                AmountAfterExchange = Amount / Currency1.Rate();
                cout << "\n\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountAfterExchange << " " << Currency2.CurrencyCode()
                    << endl << endl;
                cout << "Converting From USD to: \n";
                _PrintCurrency(Currency2, "\nTo: ");
                AmountAfterSecondExchange = AmountAfterExchange * Currency2.Rate();
                cout << "\n\n" << Amount << " " << Currency1.CurrencyCode() << " = " << AmountAfterSecondExchange
                    << " " << Currency2.CurrencyCode()
                    << endl << endl;

            }
            if (Currency1.CurrencyCode() == "USD" && Currency2.CurrencyCode() == "USD")
            {
                cout << "\nThe two Curency Code is Same:" << endl;
            }
            if (Currency1.CurrencyCode() == Currency2.CurrencyCode())
            {
                cout << "\nThe two Curency Code is Same:" << endl;
            }*/



        } while (clsInputValidate::AreYouSure("Do You Want To perfom another calculation y/n: ? "));









    }


};