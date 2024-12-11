
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "../Libraries/clsString.h"
#include "../Libraries/clsDate.h"
#include "../Libraries/clsUtil.h"

using namespace std;


class clsUser : public clsPerson
{
    public:

    struct stRegisterLoginRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;
    };

    private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _Username;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = false;

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        string stUserRecord = "";
        stUserRecord += User.GetFirstName() + Seperator;
        stUserRecord += User.GetLastName() + Seperator;
        stUserRecord += User.GetEmail() + Seperator;
        stUserRecord += User.GetPhone() + Seperator;
        stUserRecord += User.GetUsername() + Seperator;
        stUserRecord += clsUtil::EncryptText(User.GetPassword(), 34) + Seperator;
        stUserRecord += to_string(User.GetPermissions());

        return stUserRecord;
    }

    string _PrepareLoginRecord(string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += GetUsername() + Seperator;
        LoginRecord += clsUtil::EncryptText(GetPassword(), 34) + Seperator;
        LoginRecord += to_string(GetPermissions()) + Seperator;
        return LoginRecord;
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("./Core/Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    static vector <clsUser> _LoadUsersDataFromFile()
    {
        vector <clsUser> vUsers;
        fstream MyFile;
        MyFile.open("./Core/Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
                        vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5], 34), stod(vUserData[6])); }

    // struct stRegisterLoginRecord;
    static stRegisterLoginRecord _ConvertRegisterLoginLineToRecord(string Line, string Seperator = "#//#")
    {
        stRegisterLoginRecord RegisterLoginRecord;

        vector <string> vRegisterLoginDataLine = clsString::Split(Line, Seperator);

        RegisterLoginRecord.DateTime = vRegisterLoginDataLine[0];
        RegisterLoginRecord.UserName = vRegisterLoginDataLine[1];
        RegisterLoginRecord.Password = clsUtil::DecryptText(vRegisterLoginDataLine[2], 34);
        RegisterLoginRecord.Permissions = stoi(vRegisterLoginDataLine[3]);

        return RegisterLoginRecord;
    }

    static void _SaveClientsDataToFile(vector <clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("./Core/Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        vector <clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : vUsers)
        {
            if (U.GetUsername() == GetUsername())
            {
                U = *this;
                break;
            }
        }
        _SaveClientsDataToFile(vUsers);
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    public:

    enum enPermissions { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pRegisterLogin = 128 };

    // struct stRegisterLoginRecord
    // {
    //     string DateTime;
    //     string UserName;
    //     string Password;
    //     int Permissions;
    // };

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _Username = Username;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->GetPermissions() == enPermissions::eAll)
            return true;

        if ((Permission & this->GetPermissions()) == Permission)
            return true;
        else
            return false;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    void SetUsername(string Username)
    {
        _Username = Username;
    }

    string GetUsername()
    {
        return _Username;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    static clsUser Find(string Username)
    {
        fstream MyFile;
        MyFile.open("./Core/Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUsername() == Username)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static clsUser Find(string Username, string Password)
    {
        fstream MyFile;
        MyFile.open("./Core/Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUsername() == Username && User.GetPassword() == Password)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUsernameExists = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
            case enMode::EmptyMode:
            {
                if (IsEmpty())
                {
                    return enSaveResults::svFaildEmptyObject;
                }
            }

            case enMode::UpdateMode:
            {
                _Update();
                return enSaveResults::svSucceeded;
                break;
            }

            case enMode::AddNewMode:
            {
                //This will add new record to file or database
                if (clsUser::IsUserExist(_Username))
                {
                    return enSaveResults::svFaildUsernameExists;
                }
                else
                {
                    _AddNew();
                    //We need to set the mode to update after add new
                    _Mode = enMode::UpdateMode;
                    return enSaveResults::svSucceeded;
                }
            }
        }
        return enSaveResults::svFaildEmptyObject;
    }

    static bool IsUserExist(string Username)
    {
        clsUser User = clsUser::Find(Username);
        return (!User.IsEmpty());
    }

    static clsUser GetAddNewUserObject(string Username)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
    }

    bool Delete()
    {
        vector <clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : vUsers)
        {
            if (U.GetUsername() == _Username)
            {
                U._MarkedForDelete = true;
                break;
            }
        }

        _SaveClientsDataToFile(vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }

    void RegisterLogin()
    {
        string stDataLine = _PrepareLoginRecord();

        fstream MyFile;
        MyFile.open("./Screens/Main Screen/RegisterLogin.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    static vector <stRegisterLoginRecord> GetRegisterLoginList()
    {
        vector <stRegisterLoginRecord> vRegisterLoginRecord;
        fstream MyFile;
        MyFile.open("./Screens/Main Screen/RegisterLogin.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                stRegisterLoginRecord RegisterLoginRecord = _ConvertRegisterLoginLineToRecord(Line);
                vRegisterLoginRecord.push_back(RegisterLoginRecord);
            }

            MyFile.close();
        }

        return vRegisterLoginRecord;
    }

};

