#pragma once

#include <iostream>
#include "../../Core/clsCurrency.h"
#include "../../Libraries/clsInputValidate.h"
#include "../../Screens/Main Screen/clsScreen.h"

using namespace std;


class clsFindCurrencyScreen : protected clsScreen
{
    private:
    
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

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found -:)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency was not found :-(\n";
        }
    }

    public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\tFind Currency Screen");

        cout << "Find by:\n[1] Code \n[2] Country\n";
        cout << "_____________: ";
        short Answer = 1;
        cin >> Answer;

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            cout << "\nPlease Enter Currency Code: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }
    }

};

