#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTotalBalance :protected clsScreen
{
    static void _PrintClientListAstotalBalance(clsBankClient client)
    {
        cout << "| " << left << setw(15) << client.AccountNumber();
        cout << "| " << left << setw(40) << client.FullName();
        cout << "| " << left << setw(12) << client.AccountBalance;

    }

public:

    static void ShowtotalBalance()
    {
        double TotalBalance = clsBankClient::GetTotalBalance();
        vector <clsBankClient> Vclient = clsBankClient::GetclientList();

        string titile = "Balance List Screen ";
        string subtitle = " (" + to_string(Vclient.size()) + ") Client(s)";

        _DrawScreenHeader(titile, subtitle);

        cout << "----------------------------------------------------------------------------";
        cout << "--------------------------------------------\n\n";
        cout << "| " << left << setw(15) << "Account number ";
        cout << "| " << left << setw(40) << "Client name ";
        cout << "| " << left << setw(12) << "Balance ";
        cout << "\n---------------------------------------------------------------------------";
        cout << "--------------------------------------------\n\n";
        if (Vclient.size() == 0)
        {
            cout << "\n\n\n No clients available in the system: ";

        }
        else
        {
            for (clsBankClient& client : Vclient)
            {
                _PrintClientListAstotalBalance(client);
                cout << endl;
            }
            cout << "\n-------------------------------------------------------------------------";
            cout << "-----------------------------------------------\n\n";
            cout << " \t\t\t\t\t\t\t total Balance is  " << TotalBalance << endl;
            cout << "\t\t\t\t\t\t\t\t\t(" << clsString::NumberToText(TotalBalance) << ")";
        }

    }


};

