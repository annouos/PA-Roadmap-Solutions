
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void load_data(string the_file, vector <string> & content)
{
    fstream self;

    self.open(the_file, ios::in);

    if (self.is_open())
    {
        string lines;

        while (getline(self, lines))
        {
            content.push_back(lines);
        }

        self.close();
    }
}

int main()
{

    vector <string> content;

    load_data("Testo.txt", content);

    for (string &lines : content)
    {
        cout << lines << endl;
    }

    return 0;
}
