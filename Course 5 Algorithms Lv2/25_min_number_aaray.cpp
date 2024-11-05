
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

int min_number(int ray[100], int lenth)
{
    int Min = 0;
    Min = ray[0];
    for(int i = 0; i < lenth; i++)
    {
        if(ray[i] < Min)
            Min = ray[i];
    }
    return Min;
}

int main()
{
    srand((unsigned)time(NULL));
    int ray[100];
    int lenth = 0;

    fill_array_randomly(ray, lenth);
    print_array(ray, lenth);
    cout << "The min number is: " << min_number(ray, lenth) << endl;
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

// void max_number(int ray[100], int lenth)
// {
//     int Min = 0;
//     Min = ray[0];
//     for(int i = 0; i < lenth; i++)
//     {
//         if(ray[i] < Min)
//             Min = ray[i];
//     }
//     cout << "The min number is: " << Min << endl;
// }

// int main()
// {
//     srand((unsigned)time(NULL));

//     int ray[100];
//     int lenth = positiv_number("Please enter how many: ");

//     print(lenth, ray);
//     max_number(ray, lenth);
//     return 0;
// }
