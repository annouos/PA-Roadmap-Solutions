
#include <iostream>
#include <fstream>

using namespace std;



void print_file(string the_file)
{
    fstream self;

    self.open(the_file, ios::in);

    if (self.is_open())
    {
        string lines;

        while (getline(self, lines))
        {
            cout << lines << endl;
        }

        self.close();
    }
}



int main()
{
    print_file("Testo.txt");
    return 0;
}
