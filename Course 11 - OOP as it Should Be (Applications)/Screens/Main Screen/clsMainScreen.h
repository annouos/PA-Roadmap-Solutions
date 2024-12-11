#pragma once
#include <iostream>
#include <iomanip>
#include "../../Global.h"
#include "../../Libraries/clsInputValidate.h"
#include "../../Screens/Main Screen/clsScreen.h"
#include "../../Screens/Main Screen/clsRegisterLogin.h"
#include "../../Screens/User Screen/clsManageUsersScreen.h"
#include "../../Screens/Currency Screen/clsCurrencyScreen.h"
#include "../../Screens/Client Screen/clsFindClientScreen.h"
#include "../../Screens/Client Screen/clsListClientsScreen.h"
#include "../../Screens/Client Screen/clsAddNewClientScreen.h"
#include "../../Screens/Client Screen/clsDeleteClientScreen.h"
#include "../../Screens/Client Screen/clsUpdateClientScreen.h"
#include "../../Screens/Trans Action Screen/clsTransActionsScreen.h"


using namespace std;

class clsMainScreen : protected clsScreen
{
    private:

    enum enMainMenuOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
                            eFindClient = 5, eShowTransactionsMenu = 6, eManageUsers = 7, eRegisterLogin = 8, eCurrencies = 9, eExit = 10 };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1,10,"Enter Number between 1 to 10 ? ");
        return Choice;
    }

    static void _GoBackToMainMenu()
    {
        string Blank = ""; // for linux can't pause;
        cout << setw(34) << left << ""<<"\n\tPress any key to go back to Main Menu...";
        cin >> Blank;
        ShowMainMenu();
    }
    
    static void _ShowAllClientsScreen()
    {
        clsListClientsScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClient();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenu()
    {
        clsTransActionsScreen::ShowTransActionsMenu();
    }

    static void _ShowManageUsersMenu()
    {
        clsManageUsersScreen::ShowManageUsersMenu();
    }

    static void _ShowRegisterLoginScreen()
    {
        clsRegisterLoginScreen::ShowRegisterLoginScreen();
    }

    static void _ShowCurrencyMenu()
    {
        clsCurrencyScreen::ShowCurrencyMenu();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        cout << "-------------------------------------------------" << endl;
        cout << "\t Logout Program :-)" << endl;
        cout << "-------------------------------------------------" << endl;
    }

    static void _PerfromMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenuOptions::eListClients:
        {
            system("clear");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
            system("clear");
        _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eDeleteClient:
            system("clear");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eUpdateClient:
            system("clear");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eFindClient:
            system("clear");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eShowTransactionsMenu:
            system("clear");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eManageUsers:
            system("clear");
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eRegisterLogin :
            system("clear");
            _ShowRegisterLoginScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eCurrencies :
            system("clear");
            _ShowCurrencyMenu();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eExit :
            system("clear");
            _Logout();
            break;
        }
    }

    public:

    static void ShowMainMenu()
    {
        system("clear");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left <<""<< "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[01] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[02] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[03] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[04] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[05] Find Client.\n";
        cout << setw(37) << left << "" << "\t[06] Transactions.\n";
        cout << setw(37) << left << "" << "\t[07] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[08] Register Login.\n";
        cout << setw(37) << left << "" << "\t[09] Currencies.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }

};

