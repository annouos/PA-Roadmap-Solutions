
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

void update_data(string the_file, string record, string update)
{
    vector <string> content;

    load_data(the_file, content);

    for (string &lines : content)
    {
        if (lines == record)
        {
            lines = update;
        }
    }
    save_data(the_file, content);
}

void print_data(string the_file)
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

    cout << "File content before update: \n";
    print_data("Testo.txt");

    update_data("Testo.txt", "Bitch", "Awesome");

    cout << "File content after update: \n";
    print_data("Testo.txt");

    return 0;
}
