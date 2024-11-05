
#include <iostream>

using namespace std;

struct self
{
    int age;
    bool has_licens;
};

self reedo()
{
    self info;

    cout << "Please enter your age: \n";
    cin >> info.age;
    cout << "Do you have a licens ? (enter 0 or 1): \n";
    cin >> info.has_licens;

    return info;
}

bool is_accepted(self info)
{
    return (info.age > 21 && info.has_licens);
}

void print(self info)
{
    if(is_accepted(info))
        cout << "Hired";
    else
        cout << "Rejected";
}

int main(){
    print(reedo());

    return 0;
}
