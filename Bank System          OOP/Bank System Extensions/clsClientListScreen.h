#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsBankClient.h";
#include "clsScreen.h";

using namespace std;

class clsClientListScreen :protected clsScreen
{
    void static _PrintClientList(clsBankClient client)
    {
        cout << "| " << left << setw(15) << client.AccountNumber();
        cout << "| " << left << setw(20) << client.FullName();
        cout << "| " << left << setw(12) << client.Phone;
        cout << "| " << left << setw(20) << client.Email;
        cout << "| " << left << setw(10) << client.PinCode;
        cout << "| " << left << setw(12) << client.AccountBalance;

    }
public:

    static void ShowClientList()
    {
        vector <clsBankClient> Vclient = clsBankClient::GetclientList();

        string titile = "Client List Screen ";
        string subtitle = " (" + to_string(Vclient.size()) + ") Client(s)";

        _DrawScreenHeader(titile, subtitle);

        cout << "----------------------------------------------------------------------------";
        cout << "--------------------------------------------\n\n";
        cout << "| " << left << setw(15) << "Account number ";
        cout << "| " << left << setw(20) << "Client name ";
        cout << "| " << left << setw(12) << "phone ";
        cout << "| " << left << setw(20) << "Email ";
        cout << "| " << left << setw(10) << "Pin code ";
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
                _PrintClientList(client);
                cout << endl;
            }
            cout << "\n-------------------------------------------------------------------------";
            cout << "-----------------------------------------------\n\n";
        }


    }


};

