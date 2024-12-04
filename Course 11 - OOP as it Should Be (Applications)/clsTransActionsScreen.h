#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;



class clsTransActionsScreen : protected clsScreen
{
    private:

    enum enTransActionsMenuOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenu = 6 };

    static short _ReadTransActionsMenuOption()
    {
        cout << setw(37) << left << "" << "Chose what do you want to do ? [1 to 6] ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 to 6 : ");
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

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsMenu()
    {
        string Blank = ""; // for linux can't pause;
        cout << setw(34) << left << "\n\nPress any key to go back to Transactions Menu...";
        cin >> Blank;
        ShowTransActionsMenu();
    }

    static void _PerformTransactionsMenuOption(enTransActionsMenuOptions TransActionsMenuOptions)
    {
        switch (TransActionsMenuOptions)
        {
            case enTransActionsMenuOptions::eDeposit :
            {
                system("clear");
                _ShowDepositScreen();
                _GoBackToTransactionsMenu();
                break;
            }

            case enTransActionsMenuOptions::eWithdraw :
            {
                system("clear");
                _ShowWithdrawScreen();
                _GoBackToTransactionsMenu();
                break;
            }

            case enTransActionsMenuOptions::eShowTotalBalance :
            {
                system("clear");
                _ShowTotalBalancesScreen();
                _GoBackToTransactionsMenu();
                break;
            }

            case enTransActionsMenuOptions::eTransfer :
            {
                system("clear");
                _ShowTransferScreen();
                _GoBackToTransactionsMenu();
                break;
            }

            case enTransActionsMenuOptions::eTransferLog :
            {
                system("clear");
                _ShowTransferLogScreen();
                _GoBackToTransactionsMenu();
                break;
            }

            case enTransActionsMenuOptions::eShowMainMenu :
            {
                //do nothing here the main screen will handle it :-) ;
            }
        }
    }

    public:

    static void ShowTransActionsMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        system("clear");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransActionsMenuOptions)_ReadTransActionsMenuOption());
    }

};
