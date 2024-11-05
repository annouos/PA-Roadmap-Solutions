
#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
    // for int
    int number_1 = 7, number_2 = 49;

    printf("My number is: %0*d \n", 3, number_1);
    printf("The total is: %d x %d = %d \n", number_1, number_2, number_1 * number_2);

    // for float
    float PI = 3.14159265;

    printf("That's it: %f \n", PI);
    printf("That's it: %.3f \n", PI);
    printf("That's it: %.*f \n", 5, PI);

    // for string or char
    char ray[] = {"Amika Qiera"};

    printf("Bonjour %s \n", ray);

    char c = 'X';

    printf("Bonjour %c \n", c);
    printf("Bonjour %2c \n", c);
    printf("Bonjour %*c \n", 4, c);

    return 0;
}
