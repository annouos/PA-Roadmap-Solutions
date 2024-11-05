
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

short search_array(int ray[100], int lenth, int number)
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

void print_array(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl ;
}

void print_search(short index, int number)
{
    cout << "Number you are looking for: " << index << endl;
    if(index == -1)
        cout << "The number is not found it :-( " << endl;
    else
    {
        cout << "The number found at position: " << index << endl;
        cout << "The number found it's ordered: " << index + 1 << endl;
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
    short index = search_array(ray, lenth, number);
    print_search(index, number);
    return 0;
}
