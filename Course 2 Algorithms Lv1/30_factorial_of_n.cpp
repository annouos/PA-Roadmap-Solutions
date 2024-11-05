
#include <iostream>

using namespace std;

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

int loop(int number)
{
    int sum = 1;
    for(int counter = number; counter >= 1; counter--)
    {
        cout << sum << " x " << counter << endl;
        sum *= counter; 
    }
    return sum; 
}

void print(int number)
{
    cout << "The total of Factorial is: " << number << endl;
}

int main()
{
    int factorial = positiv_number("Please enter a number: ");
    print(loop(factorial));
    return 0;
}






// #include <iostream>

// using namespace std;

// struct info {
//     int num;
//     string line = "\n______________________\n";
// };

// // void loop(info vib) {

// //     int j=1;
// //     for (int i = vib.num; i >= 1; i--)

// //     {
// //     cout << endl << i << " >> " << j;
// //     cout << vib.line;
// //     j= j*i;
// //     }
// //     cout << endl << j << vib.line;
// // }

// // loop by while
// void loop(info vib) {
//     int i = vib.num;
//     int j = 1;
//     while (i >= 1)
//     {
//         {
//             cout << endl << i << " X " << j;
//             cout << vib.line;
//             j *= i;
//             i--;
//         }
//         cout << endl << j << vib.line;
//     }
// }

// void checking(info vib) {
//     while (vib.num <= 0)
//     {
//         cout << endl << " Please enter more than 0: ";
//         cin >> vib.num;
//     }
//     loop(vib);
// }

// void read(info &vib)

// {

//     cout << endl << " Please enter the number to count: ";
//     cin >> vib.num;

// }

// // void print(info vib)

// // {

// //     cout << vib.line;
// //     cout << endl << " XXX " << " XXXX ";
// //     cout << vib.line << endl;

// // }

// int main() 

// {

//     info count;

//     read(count);
//     checking(count);
//     // print(count);

//     return 0;

// }
