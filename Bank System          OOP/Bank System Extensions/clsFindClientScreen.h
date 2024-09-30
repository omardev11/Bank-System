#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h";
#include "clsClientListScreen.h";
#include "clsBankClient.h";

using namespace std;

class clsFindClientScreen :protected clsScreen
{
    static void _PrintClient(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.FirstName;
        cout << "\nLastName    : " << client.LastName;
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.Email;
        cout << "\nPhone       : " << client.Phone;
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.PinCode;
        cout << "\nBalance     : " << client.AccountBalance;
        cout << "\n___________________\n";
    }

public:
    static void FindClient()
    {
        string titile = "Update Client Screen ";

        _DrawScreenHeader(titile);
        string AccountNumber;
        cout << "Enter Your Account Number:";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number is not found please try again :\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (Client1.IsEmpty())
        {
            cout << "\nclient not found: " << endl;
        }
        else
        {
            cout << "\nclient  found: " << endl;
        }

        _PrintClient(Client1);
    }

};

