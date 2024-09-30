#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsScreen.h";
#include "clsClientListScreen.h";
#include "clsBankClient.h";


using namespace std;

class clsAddNewClient :protected clsScreen
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
        cout << "\nFirstName   : " <<client.FirstName;
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

    static void AddNewClient()
    {
        string titile = "Add New Client Screen ";
        //string subtitle = " (" + to_string(Vclient.size()) + ") Client(s)";

        _DrawScreenHeader(titile);
        string AccountNumber;
        cout << "Enter Your Account Number:";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number is exist please enter another one :\n";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Newclietnt = clsBankClient::GetAddNewClientObject(AccountNumber);

        cout << "\nAdd New Client Info \n";
        cout << "----------------------------\n\n";

        _ReadClientInfo(Newclietnt);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Newclietnt.Save();

        switch (SaveResult)
        {
        case clsBankClient::svFaildEmptyObject:
            cout << "\nError Account was not found is was empty:" << endl;
            break;
        case clsBankClient::svSucceeded:

            cout << "\n\nAdded Succesfully \n";
            _PrintClient(Newclietnt);
            break;
        case clsBankClient::svFiledAccountNumberExists:
            cout << "\nError Account was  exists:" << endl;
            break;
        default:
            break;
        }

    }

};

