//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include "clsMyString.h"

using namespace std;


int main()
{
    cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n";

    clsMyString S1;

    cout << "\nS1  = " << S1.Get() << "\n"; 

    S1.Set("Mohammed_1");

    cout << "S1  = " << S1.Get() << "\n";

    S1.Set("Mohammed_2");

    cout << "S1  = " << S1.Get() << "\n";

    S1.Set("Mohammed_3");

    cout << "S1  = " << S1.Get() << "\n";

    cout << "\n\nUndo: ";
    cout << "\n__________\n";

    S1.Undo();
    cout << "\nS1  after undo = " << S1.Get() << "\n";
    
    S1.Undo();
    cout << "S1  after undo = " << S1.Get() << "\n";

    S1.Undo();
    cout << "S1  after undo = " << S1.Get() << "\n";

    cout << "\n\nRedo: ";
    cout << "\n__________\n";

    S1.Redo();
    cout << "\nS1  after Redo = " << S1.Get() << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.Get() << "\n";

    S1.Redo();
    cout << "S1  after Redo = " << S1.Get() << "\n";

    return 0;
}

