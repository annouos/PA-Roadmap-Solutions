
#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;


class clsUser : public clsPerson
{
    private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _Username;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = false;

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
                                                vUserData[3], vUserData[4], vUserData[5], stod(vUserData[6]));
    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        string stUserRecord = "";
        stUserRecord += User.GetFirstName() + Seperator;
        stUserRecord += User.GetLastName() + Seperator;
        stUserRecord += User.GetEmail() + Seperator;
        stUserRecord += User.GetPhone() + Seperator;
        stUserRecord += User.GetUsername() + Seperator;
        stUserRecord += User.GetPassword() + Seperator;
        stUserRecord += to_string(User.GetPermissions());

        return stUserRecord;
    }

    static void _SaveCleintsDataToFile(vector <clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

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

    static  vector <clsUser> _LoadUsersDataFromFile()
    {
        vector <clsUser> vUsers;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

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
        _SaveCleintsDataToFile(vUsers);
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

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

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }


    public:

    enum enPermissions { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64 };

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->GetPermissions() == enPermissions::eAll)
            return true;

        if ((Permission & this->GetPermissions()) == Permission)
            return true;
        else
            return false;
    }

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _Username = Username;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    void GetUsername(string Username)
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
        MyFile.open("Users.txt", ios::in);//read Mode

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
        MyFile.open("Users.txt", ios::in);//read Mode

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

        _SaveCleintsDataToFile(vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }

};

