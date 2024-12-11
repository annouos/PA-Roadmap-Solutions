#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../../Core/clsUser.h"
#include "../../Libraries/clsUtil.h"
#include "../../Screens/Main Screen/clsScreen.h"

using namespace std;


class clsRegisterLoginScreen : protected clsScreen
{
    private:
    
    static void PrintRegisterLoginRecordLine(clsUser::stRegisterLoginRecord RegisterLoginRecord)
    {
        cout << setw(7) << left << "" << "| " << setw(34) << left << RegisterLoginRecord.DateTime;
        cout << "| " << setw(19) << left << RegisterLoginRecord.UserName;
        cout << "| " << setw(19) << left << clsUtil::EncryptText(RegisterLoginRecord.Password, 34);
        cout << "| " << setw(12) << left << RegisterLoginRecord.Permissions;
    }

    public:

    static void ShowRegisterLoginScreen()
    {
                if (!CheckAccessRights(clsUser::enPermissions::pRegisterLogin))
        {
            return;// this will exit the function and it will not continue
        }

        vector <clsUser::stRegisterLoginRecord> vRegisterLoginRecord = clsUser::GetRegisterLoginList();

        string Title = "\tRegister Login List Screen";
        string SubTitle =  "\t\t(" + to_string(vRegisterLoginRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(7) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(7) << left << "" << "| " << left << setw(34) << "Date/Time";
        cout << "| " << left << setw(19) << "UserName";
        cout << "| " << left << setw(19) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(7) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vRegisterLoginRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else
        {
            for (clsUser::stRegisterLoginRecord Record : vRegisterLoginRecord)
            {
                PrintRegisterLoginRecordLine(Record);
                cout << endl;
            }
        }

        cout << setw(7) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

};
