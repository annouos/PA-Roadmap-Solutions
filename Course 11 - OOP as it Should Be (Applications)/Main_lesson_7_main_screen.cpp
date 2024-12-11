#include <iostream>
#include "./Screens/Main Screen/clsLoginScreen.h"



int main()

{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
    return 0;
}
