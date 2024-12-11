#pragma once

#include "iostream"
#include "../../Core/clsCurrency.h"
#include "../../Libraries/clsInputValidate.h"
#include "../../Screens/Main Screen/clsScreen.h"

using namespace std;


class clsUpdateCurrencyScreen : protected clsScreen
{
    private:

    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card: ";
        cout << "\n________________________";
        cout << "\nCountry         : " << Currency.Country();
        cout << "\nCurrency Code   : " << Currency.CurrencyCode();
        cout << "\nCurrency Name   : " << Currency.CurrencyName();
        cout << "\nRate            : " << Currency.Rate();
        cout << "\n________________________";
    }

    public:

    static void ShowUpdateCurrencyScreen()
    {
        _DrawScreenHeader("\nUpdate Currency Screen");

        string CurrencyCode = "";
        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();
        
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Code is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update the rate of this currency? y/n: ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nUpdate Currency Rate: ";
            cout << "\n____________________\n";

            Currency.UpdateRate(_ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
        }
    }


};