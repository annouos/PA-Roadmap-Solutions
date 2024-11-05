
#include <iostream>

using namespace std;

int main() 

{

    string line = "\n______________________________\n";

    // virtical one
    cout << endl << "(5 > 6 and 7 = 7) OR (1 or 0) = " << (5 > 6 && 7 == 7) || (1 || 0);
    cout << endl << "NOT(5 > 6 and 7 = 7) OR (1 or 0) = " << !(5 > 6 && 7 == 7) || (1 || 0);
    cout << endl << "NOT(5 > 6 and 7 = 7) OR NOT(1 or 0) = " << !(5 > 6 && 7 == 7) || !(1 || 0);
    cout << endl << "NOT(5 > 6 or 7 = 7) AND NOT(1 or 0) = " << !(5 > 6 || 7 == 7) && !(1 || 0);
    cout << endl << "((5 > 6 and 7 <= 8) OR (8 > 1 and 4 <= 3)) AND TRUE = " << ((5 > 6 && 7 <= 8) || (8 > 1 && 4 <= 3)) && true;
    cout << endl << "((5 > 6 and not(7 <= 8)) AND (8 > 1 or 4 <= 3)) OR TRUE = " << ((5 > 6 && !(7 <= 8)) && (8 > 1 || 4 <= 3)) || true;
    cout << line;

    return 0;
    
}
