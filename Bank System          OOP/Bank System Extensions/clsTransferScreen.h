#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


class clsTransferScreen :protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();   
        cout << "\nAcc. Number : " << Client.AccountNumber();    
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber(string messege)
    {
        string AccountNumber = "";
        cout << endl<<messege;
        cin >> AccountNumber;
        return AccountNumber;
    }

    static clsBankClient _ReturnFullClient(string messege)
    {
        string AccountNumber1 = _ReadAccountNumber(messege);
        while (!clsBankClient::IsClientExist(AccountNumber1))
        {
            cout << "\nClient with [" << AccountNumber1 << "] does not exist.\n";
            AccountNumber1 = _ReadAccountNumber(messege);
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber1);
        return Client1;
    }



public:
    
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");

        clsBankClient SourceClient = _ReturnFullClient("Please Enter Account Number To transfer From: ");
        _PrintClient(SourceClient);


        clsBankClient DestinationClient = _ReturnFullClient("Please Enter Account Number To transfer To: ");
        _PrintClient(DestinationClient);


        double Amount = 0;
        cout << "\nPlease enter Transfer amount? ";
        Amount = clsInputValidate::ReadDoubleNumber("invalid number enter again:");

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\n Amount Exceeds The Available Amount, Enter another Amount: ";
            Amount = clsInputValidate::ReadDoubleNumber("invalid number enter again:");
        }

        if (clsInputValidate::AreYouSure("Are You sure You want to Transfer this ammount? "))
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nTransfer Done Successfully.\n";
                _PrintClient(SourceClient);
                _PrintClient(DestinationClient);
                //SourceClient.RegisterTransferInfo(DestinationClient, Amount);

            }
            else
            {
                cout << "\nOperation was cancelled.\n";
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};

