
#include <iostream>

using namespace std;

int main() 

{

    string line = "\n______________________________\n";

    // virtical one
    cout << endl << "12 >= 12 = " << (12 >= 12);
    cout << endl << "12 > 7 = " << (12 > 7);
    cout << endl << "8 < 6 = " << (8 < 6);
    cout << endl << "8 = 6 = " << (8 == 6);
    cout << endl << "12 <= 12 = " << (12 <= 12);
    cout << endl << "7 = 5 = " << (7 == 5);
    cout << line;
    
    // virtical tow
    cout << endl << "NOT(12 >= 12) = " << !(12 >= 12);
    cout << endl << "NOT(12 > 7) = " << !(12 > 7);
    cout << endl << "NOT(8 < 6) = " << !(8 < 6);
    cout << endl << "NOT(8 = 6) = " << !(8 == 6);
    cout << endl << "NOT(12 <= 12) = " << !(12 <= 12);
    cout << endl << "NOT(7 = 5) = " << !(7 == 5);
    cout << line;

    // virtical three
    cout << endl << "1 AND 1 = " << (1 && 1);
    cout << endl << "TRUE AND 0 = " << (true && 0);
    cout << endl << "0 OR 1 = " << (0 || 1);
    cout << endl << "0 OR 0 = " << (0 || 0);
    cout << endl << "Not 0 = " << (! 0);
    cout << endl << "Not(1 OR 0) = " << !(1 || 0);
    cout << line;

    // virtical four
    cout << endl << "(7 = 7) AND (7 > 5) = " << ((7 == 7) && (7 > 5));
    cout << endl << "(7 = 7) AND (7 < 5) = " << ((7 == 7) && (7 < 5));
    cout << endl << "(7 = 7) OR (7 < 5) = " << ((7 == 7) && (7 < 5));
    cout << endl << "(7 < 7) OR (7 > 5) = " << ((7 < 7) && (7 > 5));
    cout << endl << "NOT(7 = 7) AND (7 > 5) = " << !((7 == 7) && (7 > 5));
    cout << endl << "(7 = 7) AND NOT(7 < 5) = " << ((7 == 7) && !(7 < 5));

    cout << line;

    return 0;
    
}
