#pragma once

#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"

using namespace std;


class clsLoginScreen : protected clsScreen
{
    private:

    static void _Login()
    {
        string Username = "";
        string Password = "";
        bool LoginFaild = false;

        do
        {
            if (LoginFaild)
            {
                cout << "\nInvalaid Username/Password! Tray Again:\n" << endl;
            }

            cout << "Enter Username: ";
            cin >> Username;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
        } while (LoginFaild);

        clsMainScreen::ShowMainMenu();
    }

    public:

    static void ShowLoginScreen()
    {
        system("clear");
        _DrawScreenHeader("\t  Login Screen");
        _Login();
    }

};
