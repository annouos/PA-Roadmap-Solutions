
#include <iostream>
#include <string>

using namespace std;

long int positiv_number(string massage)
{
    long int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0);
    return number;
}

string number_to_text(long int number)
{
    if (number == 0)
    {
        return "Zero";
    }
    if(number >= 1 && number <= 19)
    {
        string arr[] = { "", "One", "Two", "Three" , "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
        "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen" "Nineteen"};
        return arr[number] + " ";
    }
    if (number >= 20 && number <= 99)
    {
        string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[number / 10] + " " + number_to_text(number % 10);
    }
    if (number >= 100 && number <= 199)
    {
        return "One Hundred " + number_to_text(number % 100);
    }
    if (number >= 200 && number <= 999)
    {
        return number_to_text(number / 100) + "Hundreds " + number_to_text(number % 100);
    }
    if (number >= 1000 && number <= 1999)
    {
        return "One Thousand " + number_to_text(number % 1000);
    }
    if (number >= 2000 && number <= 999999)
    {
        return number_to_text(number / 1000) + "Thousands " + number_to_text(number % 1000);
    }
    if (number >= 1000000 && number <= 1999999)
    {
        return "One Million " + number_to_text(number % 1000000);
    }
    if (number >= 2000000 && number <= 999999999)
    {
        return number_to_text(number / 1000000) + "Millions " + number_to_text(number % 1000000);
    }
    if (number >= 1000000000 && number <= 1999999999)
    {
        return "One Billion " + number_to_text(number % 1000000000);
    }
    if (number >= 2000000000 && number <= 999999999999)
    {
        return number_to_text(number / 1000000000) + "Billions " + number_to_text(number % 1000000000);
    }
    if (number >= 1000000000000 && number <= 1999999999999)
    {
        return "One Terillion " + number_to_text(number % 1000000000000);
    }
    else
    {
        return number_to_text(number / 1000000000000) + "Trillions " + number_to_text(number % 1000000000000);
    }
}



int main()
{
    long int number = positiv_number("Pleae enter a number: ");
    cout << number_to_text(number) << endl;
    return 0;
}
