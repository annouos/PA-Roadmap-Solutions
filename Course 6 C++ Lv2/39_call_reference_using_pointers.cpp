
#include <iostream>

using namespace std;

void swap_ref(int &num_1, int &num_2)
{
    int temp = num_1;
    num_1 = num_2;
    num_2 = temp;
}

void swap_poin(int * num_1, int * num_2)
{
    int temp = * num_1;
    * num_1 = * num_2;
    * num_2 = temp;
}



int main()
{
    // References:
    int a = 7;
    int c = 16;

    cout << "Before swapping: " << endl;
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;

    swap_ref(a, c);

    cout << "After swapping: " << endl;
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;



    // Pointers:
    int x = 14;
    int y = 35;

    cout << "Before swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    swap_poin(&x, &y);

    cout << "After swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    return 0;
}







// #include <iostream>

// using namespace std;

// void swap(int x, int y)
// {
//     int temp = x;
//     x = y;
//     y = temp;

//     cout << "After swap " << x << " - " << y << endl;
// }

// int main()
// {
//     int num_1 = 7;
//     int num_2 = 21;

//     cout << "Before swap " << num_1 << " - " << num_2 << endl;
//     swap(num_1, num_2);
//     return 0;
// }
