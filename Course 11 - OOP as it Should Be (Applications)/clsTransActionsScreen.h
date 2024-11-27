#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"

using namespace std;



class clsTransActionsScreen : protected clsScreen
{
    private:

    enum enTransActionsMenuOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenue = 4 };

    static short _ReadTransActionsMenuOptions()
    {
        cout << setw(37) << left << "" << "Chose what do you want to do ? [1 to 4] ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number Between 1 to 4 : ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalanceScreen::ShowTotalBalances();
    }

    static void _GoBackToTransactionsMenue()
    {
        string Blank = ""; // for linux can't pause;
        cout << setw(34) << left << "\n\nPress any key to go back to Transactions Menue...";
        cin >> Blank;
        ShowTransActionsMenu();
    }

    static void _PerformTransactionsMenueOption(enTransActionsMenuOptions TransActionsMenuOptions)
    {
        switch (TransActionsMenuOptions)
        {
            case enTransActionsMenuOptions::eDeposit :
            {
                system("clear");
                _ShowDepositScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransActionsMenuOptions::eWithdraw :
            {
                system("clear");
                _ShowWithdrawScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransActionsMenuOptions::eShowTotalBalance :
            {
                system("clear");
                _ShowTotalBalancesScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransActionsMenuOptions::eShowMainMenue :
            {
                //do nothing here the main screen will handle it :-) ;
            }
        }
    }

    public:

    static void ShowTransActionsMenu()
    {
        system("clear");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransActionsMenuOptions)_ReadTransActionsMenuOptions());
    }

};
