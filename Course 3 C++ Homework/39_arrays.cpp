
#include <iostream>

using namespace std;

struct virables {

    int grade[3];

};

float avrage(float rino, float tiro, float kiro)

{
    float total = (rino + tiro + kiro) / 3;
    return total;
}

void read(virables &vib)

{
    cout << "Please enter the first grade: ";
    cin >> vib.grade[0];
    cout << "Please enter the second grade: ";
    cin >> vib.grade[1];
    cout << "Please enter the third grade: ";
    cin >> vib.grade[2];
}


void print(virables vib)

{

    string line = "\n______________________\n";

    cout << line;
    cout << endl << "The avrage of grades is: " << avrage(vib.grade[0], vib.grade[1], vib.grade[2]);
    cout << line << endl;

}

int main() 

{

    virables student_1;
    read(student_1);
    print(student_1);

    return 0;

}
