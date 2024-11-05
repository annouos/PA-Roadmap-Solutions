
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream my_file;

    my_file.open("Testo.txt", ios::out | ios::app);

    if (my_file.is_open())
    {
        my_file << "Salut.. mes ami :) \n";
        my_file << "Hello.. my friend :) \n";
        my_file << "Hola.. mon migo :) \n";

        my_file.close();
    }

    return 0;
}
