#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

int main()
{

    time_t now = time(0);

    char * date = ctime(&now);
    cout << "Local Date & Time is: " << date << endl << endl;

    tm * london = gmtime(&now);

    date = asctime(london);
    cout << "UTC Date & Time is: " << date << endl << endl;

    return 0;
}
