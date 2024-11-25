
#include <iostream>

using namespace std;

class calculate
{

    private:

    float _result = 0;
    float _last_number = 0; 
    float _previous_result = 0;
    string _last_operation = "Clear";

    bool _is_it_zero(float number)
    {
        return (number == 0);
    }

    public:

    void Add(float number)
    {
        _last_number = number;
        _previous_result = _result;
        _result += number;
        _last_operation = "Adding";
    }

    void Subtract(float number)
    {
        _last_number = number;
        _previous_result = _result;
        _result -= number;
        _last_operation = "Subtracting";
    }

    void Divide(float number)
    {
        _last_number = number;
        _previous_result = _result;
        _last_operation = "Divide";
        
        if (_is_it_zero(number))
        {
            number = 1;
        }
        
        _result /= number;
    }

    void Multiply(float number)
    {
        _last_number = number;
        _previous_result = _result;
        _result *= number;
        _last_operation = "Multiply";
    }

    void Clear()
    {
        _last_number = 0;
        _previous_result = 0;
        _result *= 0;
        _last_operation = "Clear";
    }


    void cancel_last_operation()
    {
        _last_number = 0;
        _result = _previous_result;
        _last_operation = "Cancel Last Operation";
    }

    void print_result()
    {
        cout << "Result After " << _last_operation << " " << _last_number << " is: " << _result << endl;
    }

};

int main()
{
    calculate self;
    self.Add(57);
    self.print_result();
    self.Subtract(8);
    self.print_result();
    self.Multiply(49);
    self.print_result();
    self.Divide(7);
    self.print_result();
    self.cancel_last_operation();
    self.print_result();
    self.Clear();
    self.print_result();
    return 0;
}





// #include <iostream>

// using namespace std;

// class Calculate
// {
//     private:

//     int _num = 0;
//     int _result = 0;

//     int _set_num(int number)
//     {
//         return _num = number;
//     }

//     int _get_result()
//     {
//         return _result;
//     }

    
//     public:

//     void ADD(int number)
//     {
//         _result += _set_num(number);
//         cout << " The result add of " << number << " is: " << _get_result() << endl;
//     }

//     void SUB(int number)
//     {
//         _result -= _set_num(number);
//         cout << " The result sub of " << number << " is: " << _get_result() << endl;
//     }

//     void DEVI(int number)
//     {
//         if (number == 0)
//         {
//             _result /= _set_num(1);
//             cout << " The result devid of " << number << " is: " << _get_result() << endl;
//         }
//         else
//         {
//             _result /= _set_num(number);
//             cout << " The result devid of " << number << " is: " << _get_result() << endl;
//         }
//     }

//     void MULTI(int number)
//     {
//         _result *= _set_num(number);
//         cout << " The result multiple of " << number << " is: " << _get_result() << endl;
//     }

//     void Cleer()
//     {
//         _result = 0;
//         cout << " It's Clean now ! the result is: " << _get_result() << endl;
//     }

// };

// int main()
// {
//     Calculate self;
    
//     self.ADD(49);
//     self.ADD(56);
//     self.SUB(7);
//     self.DEVI(2);
//     self.MULTI(7);
//     self.Cleer();
//     self.MULTI(35);
//     self.ADD(49);
//     self.MULTI(49);

//     return 0;
// }
