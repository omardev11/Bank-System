#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

class clsTransferRegisterScreen :protected clsScreen
{
private:

    static void _PrintTransferRegisterRecordLine(clsBankClient::stTransferRegisterRecord TransferRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << TransferRegisterRecord.DateAndTime;
        cout << "| " << setw(10) << left << TransferRegisterRecord.s_Account;
        cout << "| " << setw(10) << left << TransferRegisterRecord.d_Account;
        cout << "| " << setw(10) << left << TransferRegisterRecord.amount;
        cout << "| " << setw(10) << left << TransferRegisterRecord.s_balance;
        cout << "| " << setw(10) << left << TransferRegisterRecord.d_balance;
        cout << "| " << setw(10) << left << TransferRegisterRecord.User;

    }

public:

    static void ShowTransferRegisterScreen()
    {

        vector <clsBankClient::stTransferRegisterRecord> VTransferRegisterRecord = clsBankClient::GetTransferRegisterList();

        string Title = "\Transfer Register List Screen";
        string SubTitle = "\t\t(" + to_string(VTransferRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t________________________________________________";
        cout << "__________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acount";
        cout << "| " << left << setw(10) << "D.Acount";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S.balance";
        cout << "| " << left << setw(10) << "D.balance";
        cout << "| " << left << setw(10) << "User ";
        cout << setw(8) << left << "" << "\n\t________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (VTransferRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Transfer Available In the System!";
        else

            for (clsBankClient::stTransferRegisterRecord Record : VTransferRegisterRecord)
            {

                _PrintTransferRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t____________________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

