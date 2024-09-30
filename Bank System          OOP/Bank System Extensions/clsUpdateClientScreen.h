#pragma once

#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h";
#include "clsClientListScreen.h";
#include "clsBankClient.h";


using namespace std;


class clsUpdateClientScreen :protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter Your Frist Name";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter your last name";
        Client.LastName = clsInputValidate::ReadString();
        cout << "\nEnter your Email";
        Client.Email = clsInputValidate::ReadString();
        cout << "\nenter Your Phone ";
        Client.Phone = clsInputValidate::ReadString();
        cout << "\nenter your Pincode";
        Client.PinCode = clsInputValidate::ReadString();
        cout << "\nenter your balance";
        Client.AccountBalance = clsInputValidate::ReadDoubleNumber("invalid number enter again:");
    }
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

    static void UpdateClient()
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
        _PrintClient(Client1);
        cout << "\n\nUpdate Client Info \n";
        cout << "---------------------------\n";
        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "\nError Account was not found is was empty:" << endl;
            break;
        case clsBankClient::svSucceeded:
            cout << "\nUpdate Succesfully \n";
            break;
        default:
            break;
        }
        _PrintClient(Client1);

    }

};

