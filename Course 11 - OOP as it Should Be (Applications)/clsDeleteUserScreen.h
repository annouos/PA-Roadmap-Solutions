#pragma once

#include <iostream>
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;


class clsDeleteUserScreen : protected clsScreen
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

    static void ShowDeleteUser()
    {
        _DrawScreenHeader("\t  Delete User Screen");

        string Username = "";

        cout << "\nPlease Enter Username: ";
        Username = clsInputValidate::ReadString();
        
        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUsername is not found, choose another one: ";
            Username = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(Username);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this User y/n? ";
        
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }
};