#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "clsScreen.h";


class clsDeleteClietnScreen :protected clsScreen
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
    static void DeleteClient()
    {
        string titile = "Delete Client Screen ";

        _DrawScreenHeader(titile);

        string AccountNumber;
        cout << "Enter Your Account Number:";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number is not found please try again :\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient ClientToDelete = clsBankClient::Find(AccountNumber);
        _PrintClient(ClientToDelete);
        if (clsInputValidate::AreYouSure("Are you Sure You Want to Delete this client? "))
        {
            ClientToDelete.DeleteClient();
            _PrintClient(ClientToDelete);
        }




    }


};

