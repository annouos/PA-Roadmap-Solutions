
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

int random(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random ;
}

void fill_array_randomly(int ray[100], int lenth)
{
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

void sum_array(int ray_1[100], int ray_2[100], int ray_3[100], int &lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        ray_3[i] = ray_1[i] + ray_2[i];
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int ray_1[100], ray_2[100], ray_3[100];
    int lenth = positiv_number("Please enter number how many: ");

    fill_array_randomly(ray_1, lenth);
    fill_array_randomly(ray_2, lenth);
    sum_array(ray_1, ray_2, ray_3, lenth);
    print_array(ray_1, lenth);
    print_array(ray_2, lenth);
    print_array(ray_3, lenth);
    return 0;
}



// #include <iostream>
// #include <cstdlib>

// using namespace std;

// int random(int from, int to)
// {
//     int random = rand() % (to - from + 1) + from;
//     return random ;
// }

// void fill_array_randomly(int ray_1[100], int ray_2[100], int &lenth)
// {
//     cout << "Enter number how many: ";
//     cin >> lenth;

//     for(int i = 0; i < lenth; i++)
//     {
//         ray_1[i] = random(1, 100);
//         ray_2[i] = random(1, 100);
//     }
// }

// void print_array(int ray[100], int lenth)
// {
//     for(int i = 0; i < lenth; i++)
//     {
//         cout << ray[i] << " ";
//     }
//     cout << endl ;
// }

// void sum_array(int ray_1[100], int ray_2[100], int ray_3[100], int &lenth)
// {
//     for(int i = 0; i < lenth; i++)
//     {
//         ray_3[i] = ray_1[i] + ray_2[i];
//     }
// }


// int main()
// {
//     srand((unsigned)time(NULL));
//     int ray_1[100];
//     int ray_2[100];
//     int ray_3[100];
//     int lenth = 0;

//     fill_array_randomly(ray_1, ray_2, lenth);
//     sum_array(ray_1, ray_2, ray_3, lenth);
//     print_array(ray_1, lenth);
//     print_array(ray_2, lenth);
//     print_array(ray_3, lenth);
//     return 0;
// }
