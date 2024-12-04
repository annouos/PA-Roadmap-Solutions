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

    static bool _Login()
    {
        string Username = "";
        string Password = "";
        bool LoginFaild = false;
        short LoginFaildCount = 0;

        do
        {
            if (LoginFaild)
            {
                LoginFaildCount++;
                cout << "\nInvalaid Username/Password!\n" << endl;
                cout << "\nYou Have [" << (3 - LoginFaildCount) << "] Trials to login.\n" << endl;
            }

            if (LoginFaildCount == 3)
            {
                "\nYour are Locked after 3 faild trail \n";
                return false;
            }

            cout << "Enter Username: ";
            cin >> Username;

            cout << "Enter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

            
        } while (LoginFaild);

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenu();
        return true;
    }

    public:

    static bool ShowLoginScreen()
    {
        system("clear");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }

};



// #pragma once

// #include <iostream>
// #include <iomanip>
// #include "Global.h"
// #include "clsUser.h"
// #include "clsScreen.h"
// #include "clsMainScreen.h"

// using namespace std;


// class clsLoginScreen : protected clsScreen
// {
//     private:

//     static void _Login()
//     {
//         string Username   = "";
//         string Password   = "";
//         short  Lock       = 0;
        
//         do
//         {
//             cout << "Enter Username: ";
//             cin >> Username;

//             cout << "Enter Password: ";
//             cin >> Password;

//             CurrentUser = clsUser::Find(Username, Password);

//             if (!CurrentUser.IsEmpty())
//             {
//                 clsMainScreen::ShowMainMenu();
//                 return;
//             }
//             else
//             {
//                 cout << "\nInvalaid Username/Password! Tray Again:\n" << endl;
//                 Lock++;
//                 cout << "You Have Try [" << 3 - Lock << "] Left To Login\n" << endl;
//             }

//         } while (Lock < 3);
        
//         cout << "You Can't Tray Again Any More Bitch..." << endl;
//         exit(0);
//     }

//     public:

//     static void ShowLoginScreen()
//     {
//         system("clear");
//         _DrawScreenHeader("\t  Login Screen");
//         _Login();
//     }

// };
