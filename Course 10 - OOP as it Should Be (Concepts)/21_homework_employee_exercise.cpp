
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

    public:

    person(int id, string first_name, string last_name, string email, int phone) //constractor
    {
        set_id(id);
        set_first_name(first_name);
        set_last_name(last_name);
        get_full_name();
        set_email(email);
        set_phone(phone);
        // print();
    }

    ~person()
    {
        cout << "\nSee Yaaa...\n\n" << endl;
    }

    void set_id(int id)
    {
        _ID = id;
    }

    int get_id()
    {
        return _ID;
    }

    void set_first_name(string first_name)
    {
        _first_name = first_name;
    }

    string get_first_name()
    {
        return _first_name;
    }

    void set_last_name(string last_name)
    {
        _last_name = last_name;
    }

    string get_last_name()
    {
        return _last_name;
    }

    string get_full_name()
    {
        return _first_name + " " + _last_name;;
    }

    void set_email(string email)
    {
        _email = email;
    }

    string get_email()
    {
        return _email;
    }

    void set_phone(int phone)
    {
        _phone = phone;
    }

    int get_phone()
    {
        return _phone;
    }

    void print()
    {
        cout << "Info Person:" << endl;
        cout << "____________________________" << endl;
        cout << "ID         : " << _ID << endl;
        cout << "First Name : " << _first_name << endl;
        cout << "Last Name  : " << _last_name << endl;
        cout << "Full Name  : " << get_full_name() << endl;
        cout << "Email      : " << _email << endl;
        cout << "Phone      : " << _phone << endl;
        cout << "____________________________" << endl;
    }

    void send_by_email(string subject, string body)
    {;
        cout << "\nThe fallowing massage sent seccessfully to email: " << endl;
        cout << "Email: " << _email << endl;
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

class employee : public person
{
    private:
    
    string _title = "";
    string _department = "";
    float _salary = 0;

    public:

    employee(int id, string first_name, string last_name, string email, int phone, string title, string department, float salary)
            : person(id, first_name, last_name, email, phone)
    {
        set_title(title);
        set_department(department);
        set_salary(salary);
    }

    ~employee()
    {
        cout << "\nSee Yooo...\n\n" << endl;
    }

    void set_title(string title)
    {
        _title = title;
    }

    string get_title()
    {
        return _title;
    }

    void set_department(string department)
    {
        _department = department;
    }

    string get_department()
    {
        return _department;
    }

    void set_salary(float salary)
    {
        _salary = salary;
    }

    float get_salary()
    {
        return _salary;
    }

    void print()
    {
        cout << "Info Employee:" << endl;
        cout << "____________________________" << endl;
        cout << "ID         : " << get_id() << endl;
        cout << "First Name : " << get_first_name() << endl;
        cout << "Last Name  : " << get_last_name() << endl;
        cout << "Full Name  : " << get_full_name() << endl;
        cout << "Email      : " << get_email() << endl;
        cout << "Phone      : " << get_phone() << endl;
        cout << "Title      : " << _title << endl;
        cout << "Department : " << _department << endl;
        cout << "Salary     : " << _salary << endl;
        cout << "____________________________" << endl;
    }

};

class developer : public employee
{
    private:

    string _language = "";

    public:

    developer(int id, string first_name, string last_name, string email, int phone, string title, string department, float salary, string language)
            : employee(id, first_name, last_name, email, phone, title, department, salary)
        {
            set_language(language);
        }

    ~developer()
    {
        cout << "\nSee Yiii...\n\n" << endl;
    }

    void set_language(string language)
    {
        _language = language;
    }

    void print()
    {
        cout << "Info Developer:" << endl;
        cout << "____________________________" << endl;
        cout << "ID         : " << get_id() << endl;
        cout << "First Name : " << get_first_name() << endl;
        cout << "Last Name  : " << get_last_name() << endl;
        cout << "Full Name  : " << get_full_name() << endl;
        cout << "Email      : " << get_email() << endl;
        cout << "Phone      : " << get_phone() << endl;
        cout << "Title      : " << get_title() << endl;
        cout << "Department : " << get_department() << endl;
        cout << "Salary     : " << get_salary() << endl;
        cout << "Language   : " << _language << endl;
        cout << "____________________________" << endl;
    }
};

int main()
{
    person self (7, "Anas", "Al-Jaradi", "annouos@yahoo.com", 771894491);
    self.print();
    self.send_by_email("Marhaba", "I'll came to buy your project");
    self.send_by_sms("Wait.. I miss you bitch");

    cout << "\n\n===============================================================\n" << endl;

    employee info (7, "Anas", "Al-Jaradi", "annouos@yahoo.com", 771894491, "Kiera", "Dev-Ops", 12400);
    info.print();

    cout << "\n\n===============================================================\n" << endl;

    developer lol (7, "Anas", "Al-Jaradi", "annouos@yahoo.com", 771894491, "Kiera", "Dev-Ops", 12400, "C++");
    lol.print();

    return 0;
}
