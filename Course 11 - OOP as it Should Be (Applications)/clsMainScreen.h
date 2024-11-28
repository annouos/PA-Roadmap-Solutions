#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListClientsScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransActionsScreen.h"
#include "clsManageUsersScreen.h"


using namespace std;

class clsMainScreen : protected clsScreen
{
    private:

    enum enMainMenuOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
                            eFindClient = 5, eShowTransactionsMenu = 6, eManageUsers = 7, eExit = 8 };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1,8,"Enter Number between 1 to 8 ? ");
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
        case enMainMenuOptions::eExit:
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
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }

};

