#pragma once

#include <iostream>
#include <iomanip>
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include "../../Core/clsUser.h"
#include "../../Libraries/clsInputValidate.h"
#include "../../Screens/Main Screen/clsScreen.h"

using namespace std;


class clsCurrencyScreen : protected clsScreen
{
    private:

    enum enCurrencyMenuOptions { eList = 1, eFind = 2, eUpdate = 3, eCalculate = 4, eBackMain = 5};

    static short _ReadCurrencyMenuOption()
    {
        cout << setw(37) << left << "" << "Chose what do you want to do ? [1 to 5] ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number Between 1 to 5: ");
        return Choice;
    }

    static void _ShowListCurrenciesScreen()
    {
        clsListCurrenciesScreen::ShowCurrencyList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoBackToCurrencyMenu()
    {
        string Blank = ""; // for linux can't pause;
        cout << setw(34) << left << "\n\nPress any key to go back to Currency Menu...";
        cin >> Blank;
        ShowCurrencyMenu();
    }

    static void _PerformCurrencyMenuOption(enCurrencyMenuOptions CurrencyMenuOptions)
    {
        switch (CurrencyMenuOptions)
        {
            case enCurrencyMenuOptions::eList :
            {
                system("clear");
                _ShowListCurrenciesScreen();
                _GoBackToCurrencyMenu();
                break;
            }

            case enCurrencyMenuOptions::eFind :
            {
                system("clear");
                _ShowFindCurrencyScreen();
                _GoBackToCurrencyMenu();
                break;
            }

            case enCurrencyMenuOptions::eUpdate :
            {
                system("clear");
                _ShowUpdateRateScreen();
                _GoBackToCurrencyMenu();
                break;
            }

            case enCurrencyMenuOptions::eCalculate :
            {
                system("clear");
                _ShowCurrencyCalculatorScreen();
                _GoBackToCurrencyMenu();
                break;
            }

            case enCurrencyMenuOptions::eBackMain :
            {
                //do nothing here the main screen will handle it :-) ;
            }
        }
    }

    public:

    static void ShowCurrencyMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        system("clear");
        _DrawScreenHeader("\t  Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Cureencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyMenuOption((enCurrencyMenuOptions)_ReadCurrencyMenuOption());
    }

};
