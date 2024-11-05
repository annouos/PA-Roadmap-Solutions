
#include <iostream>
#include <cstdlib>

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

void fill_array(int number, int ray[100], int &lenth)
{
    lenth++;
    ray[lenth -1] = number;
}

void check_array(int ray[100], int &lenth)
{
    bool add = true;
    do
    {
        fill_array(positiv_number("Please enter a number: "), ray, lenth);
        cout << "Do you want enter again: ";
        cin >> add;
    } while(add);
    return;
}

void print_array(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl ;
}


int main()
{
    srand((unsigned)time(NULL));

    int ray[100], lenth = 0;
    check_array(ray, lenth);
    cout << "Length of array: " << lenth << endl;
    print_array(ray, lenth);
    
    return 0;
}



// #include <iostream>
// #include <cstdlib>

// using namespace std;

// int positiv_number(string massage)
// {
//     int number = 0;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number < 0);
//     return number;
// }

// void fill_array(int ray[100], int &number, short &add)
// {
//     int counter = 0;
//     do
//     {
//         ray[counter] = positiv_number("Please enter a number: ");
//         cout << "Do you want enter again: ";
//         cin >> add;
//         counter++;

//     } while(add != 0);
    
//     cout << "Array length: " << counter << endl;
//     cout << "Elements in Array: ";
//     for(int i = 0; i < counter; i++)
//     {
//         cout << ray[i] << " " ;
//     }
//     cout << endl;
// }


// int main()
// {
//     srand((unsigned)time(NULL));
//     int ray[100];
//     int number = 0;
//     short add = 0;

//     fill_array(ray, number, add);
//     return 0;
// }
