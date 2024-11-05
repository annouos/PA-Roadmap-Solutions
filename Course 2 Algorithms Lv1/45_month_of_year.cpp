
#include <iostream>

using namespace std;

enum eninfo {jan=1,fev=2,mar=3,avr=4,mai=5,jun=6,jul=7,aut=8,sep=9,oct=10,nov=11,dec=12};

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

string checking(int number) {

    switch (number)
    {
    case eninfo::jan :
        return "Janvier";
    case eninfo::fev :
        return "Fevrier";
    case eninfo::mar :
        return "March";
    case eninfo::avr :
        return "Avril";
    case eninfo::mai :
        return "Mai";
    case eninfo::jun :
        return "Jeune";
    case eninfo::jul :
        return "Juillet";
    case eninfo::aut :
        return "Aoute";
    case eninfo::sep :
        return "Septemre";
    case eninfo::oct :
        return "Octobre";
    case eninfo::nov :
        return "Novembre";
    case eninfo::dec :
        return "Decembre";
    
    default:
        return "Oop!";
        
    }
}

void print(string month)
{
    cout << endl << month << endl << endl;
}

int main() 
{
    print(checking(read("Please enter a number of month: ", 0, 13)));
    return 0;
}
