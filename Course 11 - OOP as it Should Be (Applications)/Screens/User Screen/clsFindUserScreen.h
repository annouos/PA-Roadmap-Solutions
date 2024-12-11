#pragma once

#include <iostream>
#include "../../Core/clsPerson.h"
#include "../../Core/clsUser.h"
#include "../../Libraries/clsInputValidate.h"
#include "../../Screens/Main Screen/clsScreen.h"

using namespace std;


class clsFindUserScreen : protected clsScreen
{
    private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n__________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUsername    : " << User.GetUsername();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n__________________" << endl;
    }

    public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind User Screen");

        string Username;
        cout << "\nPlease Enter Username: ";
        Username = clsInputValidate::ReadString();
        
        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUsername is not found, choose another one: ";
            Username = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(Username);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }
        
        _PrintUser(User1);
    }

};