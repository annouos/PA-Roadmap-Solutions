
#include <iostream>

using namespace std;

string read_text(string massage)
{
    string text;
    cout << massage;
    cin >> text;
    return text;
}

bool loop(string pass)
{
    string word = ""; int counter = 0;
    for(int i = 65; i <= 90; i++)
    {
        for(int j = 65; j <= 90; j++)
        {
            for(int k = 65; k <= 90; k++)
            {
                counter++;

                word += char(i);
                word += char(j);
                word += char(k);
                cout << word << endl ;

                if(word == pass)
                {
                    cout << "The pass is: " << pass << endl;
                    cout << "We find it after: " << counter << endl;
                    return true;
                }
                word = "";
                // cout << char(i) << char(j) << char(k) << endl;
            }
        }
    }
    return false;
}

int main()
{
    loop(read_text("Please enter your passwaord: "));
    return 0;
}



// int loop(string pass)
// {
//     string word = ""; int counter = 0;
//     for(int i = 65; i <= 90; i++)
//     {
//         for(int j = 65; j <= 90; j++)
//         {
//             for(int k = 65; k <= 90; k++)
//             {
//                 word += char(i);
//                 word += char(j);
//                 word += char(k);
//                 counter++;
//                 if(word == pass)
//                     return counter;
//                 word = "";
//             }
//         }
//     }
// }

// void print(string pass)
// {
//     cout << "The pass is: " << pass << endl;
//     cout << "We find it after: " << loop(pass) << endl;
// }