#pragma once

#include <iostream>
#include <iomanip>
#include "../../Libraries/clsUtil.h"
#include "../../Core/clsBankClient.h"
#include "../../Libraries/clsInputValidate.h"
#include "../../Screens/Main Screen/clsScreen.h"

using namespace std;


class clsTotalBalanceScreen : protected clsScreen
{

    private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << "| " << setw(16) << left << Client.AccountNumber();
        cout << "| " << setw(31) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();
    }

    public:

    static void ShowTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Client List Screen";
        string SubTitle ="\t    (" + to_string(vClients.size()) + ") Client(s).";
        
        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t\t\tBalances List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(16) << "Accout Number";
        cout << "| " << left << setw(31) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\tNo Clients Available In the System!";
        else

            for (clsBankClient C : vClients)
            {
                _PrintClientRecordBalanceLine(C);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t Total Balances = " << TotalBalances << endl;
        cout << "\t\t ( " << clsUtil::NumberToText(TotalBalances) << ")\n" << endl;
    }
};
