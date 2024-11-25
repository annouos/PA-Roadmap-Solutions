
#include <iostream>

using namespace std;

class person
{
    private:

    int _ID = 0;
    string _first_name = "";
    string _last_name = "";
    string _full_name = "";
    string _email = "";
    int _phone = 0;

    void _set_id(int id)
    {
        _ID = id;
    }

    void _set_first_name(string first_name)
    {
        _first_name = first_name;
    }

    string _get_first_name()
    {
        return _first_name;
    }

    void _set_last_name(string last_name)
    {
        _last_name = last_name;
    }

    string _get_last_name()
    {
        return _last_name;
    }

    string _get_full_name()
    {
        return _first_name + " " + _last_name;;
    }

    void _set_email(string email)
    {
        _email = email;
    }

    string _get_email()
    {
        return _email;
    }

    void _set_phone(int phone)
    {
        _phone = phone;
    }

    int _get_phone()
    {
        return _phone;
    }

    public:

    person(int id, string first_name, string last_name, string email, int phone) //constractor
    {
        _set_id(id);
        _set_first_name(first_name);
        _set_last_name(last_name);
        _get_full_name();
        _set_email(email);
        _set_phone(phone);
        // print_person();
    }

    ~person()
    {
        cout << "\nSee Yaaa...\n\n" << endl;
    }

    void print_person()
    {
        cout << "Info:" << endl;
        cout << "____________________________" << endl;
        cout << "ID         : " << _ID << endl;
        cout << "First Name : " << _first_name << endl;
        cout << "Last Name  : " << _last_name << endl;
        cout << "Full Name  : " << _get_full_name() << endl;
        cout << "Email      : " << _email << endl;
        cout << "Phone      : " << _phone << endl;
        cout << "____________________________" << endl;
    }

    void send_by_email(string subject, string body)
    {;
        cout << "\nThe fallowing massage sent seccessfully to email: " << endl;
        cout << "Email: " << _get_email() << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }

    void send_by_sms(string massage)
    {
        cout << "\nThe fallowing massage sent seccessfully to phone: " << endl;
        cout << "Phone: " << _phone << endl;
        cout << "Massage: " << massage << endl;
    }
};



int main()
{
    person self(7, "Anas", "Al-Jaradi", "annouos@yahoo.com", 771894491);
    self.print_person();
    self.send_by_email("Marhaba", "I'll came to buy your project");
    self.send_by_sms("Wait.. I miss you bitch");
    return 0;
}
