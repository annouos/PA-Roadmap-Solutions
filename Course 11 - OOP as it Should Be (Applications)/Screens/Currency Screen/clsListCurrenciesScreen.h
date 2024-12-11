#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../../Core/clsCurrency.h"
#include "../../Screens/Main Screen/clsScreen.h"

using namespace std;


class clsListCurrenciesScreen : protected clsScreen
{
    private:

    static void _PrintClientRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(34) << left << Currency.Country();
        cout << "| " << setw(12) << left << Currency.CurrencyCode();
        cout << "| " << setw(42) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();
    }

    public:

    static void ShowCurrencyList()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currency List Screen";
        string SubTitle ="\t    (" + to_string(vCurrency.size()) + ") Currency(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_____________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(34) << "Accout Number";
        cout << "| " << left << setw(12) << "Client Name";
        cout << "| " << left << setw(42) << "Phone";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_____________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else
        {
            for (clsCurrency Currency : vCurrency)
            {
                _PrintClientRecordLine(Currency);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t_____________________________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

};