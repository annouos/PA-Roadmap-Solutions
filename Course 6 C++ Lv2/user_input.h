// #pragma once

#include <iostream>
using namespace std;

// #ifndef USER_INPUT
// #define USER_INPUT

namespace inputs
{
    int genric_number(string massage)
    {
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
    }

    int positiv_number(string massage)
    {
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0);
    return number;
    }

    string read_text(string massage)
    {
    string text;
    cout << massage;
    cin >> text;
    return text;
    }
}

// #endif