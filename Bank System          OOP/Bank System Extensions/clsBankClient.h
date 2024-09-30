#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsGlobal.h"
#include "clsUtill.h"


    using namespace std;
    class clsBankClient : public clsPerson
    {
    private:

        enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
        enMode _Mode;
        string _AccountNumber;
        string _PinCode;
        float _AccountBalance;
        bool MarketeToDelete = false;

        struct stTransferRegisterRecord;
        static stTransferRegisterRecord _ConvertTransferRegisterLineToRecord(string Line, string Seperator = "#//#")
        {
            stTransferRegisterRecord TransferRegisterRecord;


            vector <string> TransferRegisterDataLine = clsString::Split(Line, Seperator);
            TransferRegisterRecord.DateAndTime = TransferRegisterDataLine[0];
            TransferRegisterRecord.s_Account = TransferRegisterDataLine[1];
            TransferRegisterRecord.d_Account = TransferRegisterDataLine[2];
            TransferRegisterRecord.amount = stoi(TransferRegisterDataLine[3]);
            TransferRegisterRecord.s_balance = stoi(TransferRegisterDataLine[4]);
            TransferRegisterRecord.d_balance = stoi(TransferRegisterDataLine[5]);
            TransferRegisterRecord.User = TransferRegisterDataLine[6];


            
            return TransferRegisterRecord;

        }

      

        static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
        {
            vector<string> vClientData;
            vClientData = clsString::Split(Line, Seperator);

            return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
                vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

        }

        static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
        {

            string stClientRecord = "";
            stClientRecord += Client.FirstName + Seperator;
            stClientRecord += Client.LastName + Seperator;
            stClientRecord += Client.Email + Seperator;
            stClientRecord += Client.Phone + Seperator;
            stClientRecord += Client.AccountNumber() + Seperator;
            stClientRecord += Client.PinCode + Seperator;
            stClientRecord += to_string(Client.AccountBalance);

            return stClientRecord;

        }

        static  vector <clsBankClient> _LoadClientsDataFromFile()
        {

            vector <clsBankClient> vClients;

            fstream MyFile;
            MyFile.open("Clients.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {

                string Line;


                while (getline(MyFile, Line))
                {

                    clsBankClient Client = _ConvertLinetoClientObject(Line);
                    vClients.push_back(Client);
                }

                MyFile.close();

            }

            return vClients;

        }

        static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
        {

            fstream MyFile;
            MyFile.open("Clients.txt", ios::out);//overwrite

            string DataLine;

            if (MyFile.is_open())
            {

                for (clsBankClient C : vClients)
                {
                    if (C.MarketeToDelete == false)
                    {
                        DataLine = _ConverClientObjectToLine(C);
                        MyFile << DataLine << endl;
                    }
                  

                }

                MyFile.close();

            }

        }

        void _Update()
        {
            vector <clsBankClient> _vClients;
            _vClients = _LoadClientsDataFromFile();

            for (clsBankClient& C : _vClients)
            {
                if (C.AccountNumber() == AccountNumber())
                {
                    C = *this;
                    break;
                }

            }

            _SaveCleintsDataToFile(_vClients);

        }

        void _AddNewClient()
        {
            _AddDataLineToFile(_ConverClientObjectToLine(*this));
        }

  
        
        void _AddDataLineToFile(string  stDataLine)
        {
            fstream MyFile;
            MyFile.open("Clients.txt", ios::out | ios::app);

            if (MyFile.is_open())
            {

                MyFile << stDataLine << endl;

                MyFile.close();
            }

        }

        static clsBankClient _GetEmptyClientObject()
        {
            return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
        }

        string _PrepareTransfeRecord(clsBankClient &DestinationClient,double amount)
        {
            string Seperator = "#//#";

            string LoginRecord = "";
            LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
            LoginRecord += AccountNumber() + Seperator;
            LoginRecord += DestinationClient.AccountNumber()  + Seperator;
            LoginRecord += to_string(amount) + Seperator;
            LoginRecord += to_string(AccountBalance) + Seperator;
            LoginRecord += to_string(DestinationClient.AccountBalance) + Seperator;
            LoginRecord += CurrentUser.UserName;
            return LoginRecord;
        }

        void _RegisterTransferInfo(clsBankClient& DestinationClient, double amount)
        {

            string stDataLine = _PrepareTransfeRecord(DestinationClient, amount);

            fstream MyFile;
            MyFile.open("TransferLog.txt", ios::out | ios::app);

            if (MyFile.is_open())
            {

                MyFile << stDataLine << endl;

                MyFile.close();
            }

        }




    public:

        struct stTransferRegisterRecord
        {
            string DateAndTime;
            string s_Account;
            string d_Account;
            double s_balance;
            double d_balance;
            double amount;
            string User;
        };


        clsBankClient(enMode Mode, string FirstName, string LastName,
            string Email, string Phone, string AccountNumber, string PinCode,
            float AccountBalance) :
            clsPerson(FirstName, LastName, Email, Phone)

        {
            _Mode = Mode;
            _AccountNumber = AccountNumber;
            _PinCode = PinCode;
            _AccountBalance = AccountBalance;

        }

        bool IsEmpty()
        {
            return (_Mode == enMode::EmptyMode);
        }


        string AccountNumber()
        {
            return _AccountNumber;
        }

        void SetPinCode(string PinCode)
        {
            _PinCode = PinCode;
        }

        string GetPinCode()
        {
            return _PinCode;
        }
        __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

        void SetAccountBalance(float AccountBalance)
        {
            _AccountBalance = AccountBalance;
        }

        float GetAccountBalance()
        {
            return _AccountBalance;
        }
        __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

      

        static clsBankClient Find(string AccountNumber)
        {


            fstream MyFile;
            MyFile.open("Clients.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsBankClient Client = _ConvertLinetoClientObject(Line);
                    if (Client.AccountNumber() == AccountNumber)
                    {
                        MyFile.close();
                        return Client;
                    }

                }

                MyFile.close();

            }

            return _GetEmptyClientObject();
        }

        static clsBankClient Find(string AccountNumber, string PinCode)
        {



            fstream MyFile;
            MyFile.open("Clients.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsBankClient Client = _ConvertLinetoClientObject(Line);
                    if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                    {
                        MyFile.close();
                        return Client;
                    }

                }

                MyFile.close();

            }
            return _GetEmptyClientObject();
        }

        enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFiledAccountNumberExists = 2 };

        enSaveResults Save()
        {

            switch (_Mode)
            {
            case enMode::EmptyMode:
            {

                return enSaveResults::svFaildEmptyObject;
            }

            case enMode::UpdateMode:
            {


                _Update();

                return enSaveResults::svSucceeded;

                break;
            }

            case enMode::AddNewMode:
            {

                if (IsClientExist(_AccountNumber))
                {
                    return enSaveResults::svFiledAccountNumberExists;
                }
                else
                {
                    _AddNewClient();
                }
                _Mode = enMode::UpdateMode;
                _Update();
                return enSaveResults::svSucceeded;

                break;
            }
            case enMode::DeleteMode:
            {

                if (IsClientExist(_AccountNumber))
                {
                    return enSaveResults::svFiledAccountNumberExists;
                }
                else
                {
                    _AddNewClient();
                }
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;

                break;
            }


            }



        }

        static bool IsClientExist(string AccountNumber)
        {

            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            return (!Client1.IsEmpty());
        }

        static clsBankClient GetAddNewClientObject(string accountNumber)
        {
            return (clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "", 0));
        }

        static clsBankClient GetDeleteClientObject()
        {
            return (clsBankClient(enMode::DeleteMode, "", "", "", "", "", "", 0));
        }

          bool DeleteClient()
        {
            vector <clsBankClient> _vClients;
            _vClients = _LoadClientsDataFromFile();

            for (clsBankClient& C : _vClients)
            {
                if (C.AccountNumber() == _AccountNumber)
                {
                    C.MarketeToDelete = true;
                    break;
                }

            }

            _SaveCleintsDataToFile(_vClients);
            *this = _GetEmptyClientObject();
            return true;

        }

         static vector <clsBankClient> GetclientList()
         {
             return _LoadClientsDataFromFile();
         }

         static double GetTotalBalance()
         {
             double TotalBalance = 0;
             vector <clsBankClient> Vclient = clsBankClient::GetclientList();
             for (clsBankClient& client : Vclient)
             {
                 TotalBalance += client.AccountBalance;
                
             }
             return TotalBalance;
         }

         void Deposit(double Amount)
         {
             _AccountBalance += Amount;
             Save();

         }

         bool Whithdraw(double amount)
         {
             if (amount > _AccountBalance)
             {
                 return false;
             }
             else
             {
                 _AccountBalance -= amount;
                 Save();
                 return true;
             }
           
         }

          bool Transfer(double amount, clsBankClient& DestinationClient)
         {
             if (Whithdraw(amount))
             {
                 DestinationClient.Deposit(amount);
                 _RegisterTransferInfo(DestinationClient, amount);
                 return true;
             }
             else
             {
                 return false;
             }
         }

          static  vector <stTransferRegisterRecord> GetTransferRegisterList()
          {
              vector <stTransferRegisterRecord> vLoginRegisterRecord;

              fstream MyFile;
              MyFile.open("TransferLog.txt", ios::in);//read Mode

              if (MyFile.is_open())
              {

                  string Line;

                  stTransferRegisterRecord LoginRegisterRecord;

                  while (getline(MyFile, Line))
                  {

                      LoginRegisterRecord = _ConvertTransferRegisterLineToRecord(Line);

                      vLoginRegisterRecord.push_back(LoginRegisterRecord);

                  }

                  MyFile.close();

              }

              return vLoginRegisterRecord;

          }



};

