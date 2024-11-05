
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

void read_array(int ray[100], int &lenth)
{
    cout << "Please enter how many: ";
    cin >> lenth;

    cout << "Enter array elements: \n";
    for (int i = 0; i < lenth; i++)
    {
        cout << "number [" << i+1 << "] : ";
        cin >> ray[i] ;
    }
    cout << endl ;
}

void print_array(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl ;
}

int repeate_number(int number, int ray[100], int lenth)
{
    int count = 0;
    for(int i = 0; i < lenth; i++)
    {
        if(number == ray[i])
            count++;
    }
    return count;
}

int main()
{
    int ray[100];
    int lenth = 0;

    read_array(ray, lenth);
    int number = positiv_number("Please enter the check: ");

    print_array(ray, lenth);
    cout << repeate_number(number, ray, lenth) << endl;
    return 0;
}




// #include <iostream>
// #include <cstdlib>

// using namespace std;

// struct info {
//     int ray[100] ;
//     int lenth = 0;
//     int number = 0;
// };

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

// info read_numbers()
// {
//     info self;
//     self.lenth = positiv_number("Please enter how many numbers: ");
//     for(int i = 0; i < self.lenth; i++)
//     {
//         cout << "please enter " << i+1 << " : ";
//         cin >> self.ray[i];
//     }
//     self.number = positiv_number("\nPlease enter a number to check: ");
//     return self;
// }

// int checking(info self)
// {
//     int sum = 0;
//     for(int i = 0; i < self.lenth; i++)
//     {
//         if(self.number == self.ray[i])
//             sum++;
//     }
//     return sum;
// }

// void print(info self)
// {
//     cout << "\nThe orginal number is: ";
//     for(int i = 0; i < self.lenth; i++)
//     {
//         cout << self.ray[i];
//         if(i < self.lenth)
//             cout << " ";
//     }
//     cout << endl << self.number << " is repeated " << checking(self) << " times" << endl;
// }

// int main()
// {
//     srand((unsigned)time(NULL));
//     print(read_numbers());
//     return 0;
// }
