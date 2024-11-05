
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

void fill_array_randomly(int ray[100], int &lenth)
{
    cout << "Enter number how many: ";
    cin >> lenth;

    for(int i = 0; i < lenth; i++)
    {
        ray[i] = random(1, 100);
    }
}

short search_array(int ray[100], int number, int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        if(number == ray[i])
        {
            return i;
        }
    }
    return -1;
}

bool number_in_array(int ray[100], int number, int lenth)
{
    return search_array(ray, number, lenth) != -1;
}

void print_array(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl ;
}

void print_search(int ray[100], int number, int lenth)
{
    cout << "Number you are looking for: " << number << endl;
    if(!number_in_array(ray, number, lenth))
    {
        cout << "The number is not found it :-( " << endl;
    }
    else
    {
        cout << "The number is found it :-) " << number << endl;
    }
}


int main()
{
    srand((unsigned)time(NULL));
    
    int ray[100];
    int lenth = 0;

    fill_array_randomly(ray, lenth);
    print_array(ray, lenth);

    int number = positiv_number("Please enter a number to search for: ");
    print_search(ray, number, lenth);
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
//     return random ;
// }

// void fill_array_randomly(int ray[100], int &lenth)
// {
//     cout << "Enter number how many: ";
//     cin >> lenth;

//     for(int i = 0; i < lenth; i++)
//     {
//         ray[i] = random(1, 100);
//     }
// }

// bool search_array(int ray[100], int lenth, int number)
// {
//     for(int i = 0; i < lenth; i++)
//     {
//         if(number == ray[i])
//         {
//             return true;
//         }
//     }
//     return false;
// }

// void print_array(int ray[100], int lenth)
// {
//     for(int i = 0; i < lenth; i++)
//     {
//         cout << ray[i] << " ";
//     }
//     cout << endl ;
// }

// void print_search(short index, int number)
// {
//     cout << "Number you are looking for: " << number << endl;
//     if(!index)
//         cout << "The number is not found it :-( " << endl;
//     else
//     {
//         cout << "The number is found it :-) " << index << endl;
//     }
// }


// int main()
// {
//     srand((unsigned)time(NULL));
    
//     int ray[100];
//     int lenth = 0;

//     fill_array_randomly(ray, lenth);
//     print_array(ray, lenth);

//     int number = positiv_number("Please enter a number to search for: ");
//     bool index = search_array(ray, lenth, number);
//     print_search(index, number);
//     return 0;
// }
