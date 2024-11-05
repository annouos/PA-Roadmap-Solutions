
#include <iostream>
#include <cstdlib>

using namespace std;

int random(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random ;
}

void fill_array_randomly(int ray[100], int &lenth)
{
    cout << "Enter number how many: ";
    cin >> lenth;

    for(int i = 0; i < lenth; i++)
    {
        ray[i] = random(1, 100);
    }
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
    int ray[100];
    int lenth = 0;

    fill_array_randomly(ray, lenth);
    print_array(ray, lenth);
    return 0;
}

// struct way:

// #include <iostream>
// #include <cstdlib>

// using namespace std;

// struct info {
//     int ray[100] ;
//     int lenth = 0;
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
//     return self;
// }

// int random(int from, int to)
// {
//     int random = rand() % (to - from + 1) + from;
//     return random ;
// }

// void print(info self)
// {
//     for(int i = 1; i <= self.lenth; i++)
//     {
//         self.ray[i] = random(1,100);
//         cout << self.ray[i];
//         if(i < self.lenth)
//             cout << " - " ;
//     }
//     cout << endl;
// }

// int main()
// {
//     srand((unsigned)time(NULL));
//     print(read_numbers());
//     return 0;
// }


// the best way:


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

// int random(int from, int to)
// {
//     int random = rand() % (to - from + 1) + from;
//     return random;
// }

// void print(int &lenth, int ray[100])
// {
//     for(int i = 0; i < lenth; i++)
//     {
//         ray[i] = random(1,100);
//         cout << ray[i];
//         if(i < lenth)
//             cout << " ";
//     }
//     cout << endl ;
// }

// int main()
// {
//     srand((unsigned)time(NULL));

//     int ray[100];
//     int lenth = positiv_number("Please enter how many: ");

//     print(lenth, ray);
//     return 0;
// }
