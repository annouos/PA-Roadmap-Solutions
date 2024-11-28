#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
    private:

    enum enManageUsersMenuOptions { eListCUsers = 1, eAddNewUsers = 2, eDeleteUsers = 3, eUpdateUsers = 4,
                                    eFindUsers = 5, eMainMenu = 6, };

    static short _ReadManageUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Chose what do you want to do ? [1 to 6] ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 to 6 : ");
        return Choice;
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowListUsers();
    }

    static void _ShowAddNewUsersScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUsersScreen()
    {
        clsDeleteUserScreen::ShowDeleteUser();
    }

    static void _ShowUpdateUsersScreen()
    {
        clsUpdateUserScreen::ShowUpdateUser();
    }

    static void _ShowFindUsersScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _GoBackToManageUsersMenu()
    {
        string Blank = ""; // for linux can't pause;
        cout << setw(34) << left << ""<<"\n\tPress any key to go back to Manage Users Menu...";
        cin >> Blank;
        ShowManageUsersMenu();
    }

    static void _PerfromManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOptions)
    {
        switch (ManageUsersMenuOptions)
        {
            case enManageUsersMenuOptions::eListCUsers :
            {
                system("clear");
                _ShowListUsersScreen();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersMenuOptions::eAddNewUsers :
            {
                system("clear");
                _ShowAddNewUsersScreen();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersMenuOptions::eDeleteUsers :
            {
                system("clear");
                _ShowDeleteUsersScreen();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersMenuOptions::eUpdateUsers :
            {
                system("clear");
                _ShowUpdateUsersScreen();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersMenuOptions::eFindUsers :
            {
                system("clear");
                _ShowFindUsersScreen();
                _GoBackToManageUsersMenu();
                break;
            }
            case enManageUsersMenuOptions::eMainMenu :
            {
                //do nothing here the main screen will handle it :-) ;
            }
        }
    }

    public:

    static void ShowManageUsersMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;// this will exit the function and it will not continue
        }

        system("clear");
        _DrawScreenHeader("\t  Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Users List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Users.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Users.\n";
        cout << setw(37) << left << "" << "\t[4] Update Users Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Users.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromManageUsersMenuOption((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
    }

};