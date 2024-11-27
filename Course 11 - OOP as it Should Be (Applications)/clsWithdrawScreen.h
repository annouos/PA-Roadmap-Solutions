#pragma once

#include "iostream"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"



class clsWithdrawScreen : protected clsScreen
{

    private:

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n__________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n__________________" << endl;
    }

    public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if ( Client.Withdraw(Amount) )
            {
                cout << "\nAmount Withdraw Successfully.\n";
                cout << "\nNew Balance Is: " << Client.GetAccountBalance();
            }
            else
            {
                cout << "\nCan not Withdraw Insuffecient Balance!\n";
                cout << "\nAmount Withdraw Is: \n" << Amount;
                cout << "\nYour Balance Is: " << Client.GetAccountBalance();
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }

};