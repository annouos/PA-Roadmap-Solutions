
#include <iostream>

using namespace std;

enum eninfo {sam=1,dim=2,lun=3,mar=4,mer=5,jeu=6,van=7};

int read(string massage, int from, int to)
{
    int number;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < from || number > to);
    return number;
}

eninfo convert(int number)
{
    return (eninfo) number;
}

string checking(eninfo day) {

    switch (day)
    {
    case eninfo::sam :
        return "Samdi";
    case eninfo::dim :
        return "Dimanch";
    case eninfo::lun :
        return "Lundi";
    case eninfo::mar :
        return "Mardi";
    case eninfo::mer :
        return "Mercurdi";
    case eninfo::jeu :
        return "Jeudi";
    case eninfo::van :
        return "Vandurdi";
    default:
        return "Oop!";
    }
}

void print(string day)
{
    cout << endl << day << endl << endl;
}

int main() 
{
    print(checking(convert(read("Please enter a number of day: ", 0, 8))));
    return 0;
}




// #include <iostream>

// using namespace std;

// enum eninfo {sam=1,dim=2,lun=3,mar=4,mer=5,jeu=6,van=7};

// int read(string massage, int from, int to)
// {
//     int number;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number < from || number > to);
//     return number;
// }

// string checking(int number) {

//     switch (number)
//     {
//     case eninfo::sam :
//         return "Samdi";
//     case eninfo::dim :
//         return "Dimanch";
//     case eninfo::lun :
//         return "Lundi";
//     case eninfo::mar :
//         return "Mardi";
//     case eninfo::mer :
//         return "Mercurdi";
//     case eninfo::jeu :
//         return "Jeudi";
//     case eninfo::van :
//         return "Vandurdi";
//     default:
//         return "Oop!";
//     }
// }

// void print(string day)
// {
//     cout << endl << day << endl << endl;
// }

// int main() 
// {
//     print(checking(read("Please enter a number of day: ", 0, 8)));
//     return 0;
// }
