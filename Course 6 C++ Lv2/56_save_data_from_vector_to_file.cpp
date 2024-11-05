
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void save_data(string the_file, vector <string> content)
{
    fstream self;

    self.open(the_file, ios::out);

    if (self.is_open())
    {
        string lines;

        for (string &lines : content)
        {
            if (lines != "")
            {
                self << lines << endl;
            }
        }

        self.close();
    }
}

int main()
{

    vector <string> content {"Hot", "Sexy", "Beauty", "Lovely", "Cute"};

    save_data("Testo.txt", content);

    return 0;
}
