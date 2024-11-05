
#include <iostream>

using namespace std;

int read(string massage, int from, int to)
{
    int grade;
    do
    {
        cout << massage;
        cin >> grade;
    } while (grade < from || grade > to);
    return grade;
}

char checking(int number)
{
        if (number <=100 && number >=90) {
        return 'A';
    }
    else if (number >= 80) {
        return 'B';
    }
    else if (number >= 70) {
        return 'C';
    }
    else if (number >= 60) {
        return 'D';
    }
    else if (number >= 50) {
        return 'E';
    }
    else {
        return 'F';
    }
}

int main()

{
    cout << checking(read("Please enter your mark: ", 0, 100)) << endl;
    return 0;
}
