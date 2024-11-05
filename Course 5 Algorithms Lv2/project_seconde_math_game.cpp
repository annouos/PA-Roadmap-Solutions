
#include <iostream>
#include <cstdlib>

using namespace std;

enum level { easy = 1, meduim = 2, hard = 3, mixo = 4};
enum operation { add = 1, sub = 2, multi = 3, devid = 4, mixa = 5};

string the_level(level self)
{
    string ray_level[4] = {"Easy", "Meduim", "Hard", "Mix"};
    return ray_level[self - 1];
}

string symbol(operation self)
{
    switch (self)
    {
        case operation::add :
        return "+";
        case operation::sub :
        return "-";
        case operation::multi :
        return "*";
        case operation::devid :
        return "/";
        default :
        return "Mix";
    }
}

struct question
{
    int num_1 = 0;
    int num_2 = 0;
    level type_question;
    operation type_operation;
    int correct_answer = 0;
    int choise_player = 0;
    bool result_answer = false;
};

struct quizz
{
    question list_question[100];
    short number_question;
    level level_question ;
    operation op_type;
    short wrong_answer = 0;
    short right_answer = 0;
    bool is_pass = false;
};

int random_number(int from, int to)
{
    int rand_num = rand() % (to - from + 1) + from;
    return rand_num;
}

short read_how_many()
{
    short number = 1;
    do
    {
        cout << "How Many Questions Do You Want to Answer ? ";
        cin >> number;       
    } while (number < 1 || number > 10);
    return number;
}

level read_level()
{
    short number = 1;
    do
    {
        cout << "\nEnter Question Level: [1]: Easy, [2]: Med, [3]: Hard, [4]: Mix ? ";
        cin >> number;        
    } while (number < 1 || number > 4);
    return (level) number;
}

operation read_operation()
{
    short number = 1;
    do
    {
        cout << "\nEnter Operation Type: [1]: Add, [2]: Minus, [3]: Multi, [4]: Devid, [5]: Mix ? ";
        cin >> number;        
    } while (number < 1 || number > 5);
    return (operation) number;
}

int read_answer()
{
    int answer = 0;
    cin >> answer;
    return answer;
}

void set_screen(bool right)
{
    if(right)
        cout << "--------------------------------------------\n";
    else
    {
        cout << "____________________________________________\n";
    }
}

int simple_calculator(int num_1, int num_2, operation op_type)
{
    switch (op_type)
    {
        case operation::add :
        return num_1 + num_2;
        case operation::sub :
        return num_1 - num_2;
        case operation::multi :
        return num_1 * num_2;
        case operation::devid :
            if (num_2 != 0)
                return num_1 / num_2;
            else
                return -000;
        default:
        return 0000007;
    }
}

operation mix_operation()
{
    int number = random_number(1,4);
    return (operation) number;
} 

question generat_question(level level_question, operation op_type)
{
    question self;
    if (level_question == level::mixo)
    {
        level_question = (level) random_number(1,3);
    }
    if (op_type == operation::mixa)
    {
        op_type = mix_operation();
    }

    self.type_operation = op_type;

    switch (level_question)
    {
        case level::easy :
        self.num_1 = random_number(1,10);
        self.num_2 = random_number(1,10);
        self.correct_answer = simple_calculator(self.num_1, self.num_2, self.type_operation);
        self.type_question = level_question;
        return self;

        case level::meduim :
        self.num_1 = random_number(11,100);
        self.num_2 = random_number(11,100);
        self.correct_answer = simple_calculator(self.num_1, self.num_2, self.type_operation);
        self.type_question = level_question;
        return self;

        case level::hard :
        self.num_1 = random_number(101,1000);
        self.num_2 = random_number(101,1000);
        self.correct_answer = simple_calculator(self.num_1, self.num_2, self.type_operation);
        self.type_question = level_question;
        return self;
    }
    return self;
}

void generat_quizz(quizz &self)
{
    for (short counter = 0; counter < self.number_question; counter++)
    {
        self.list_question[counter] = generat_question(self.level_question, self.op_type);
    }
}

void print_question(quizz &self, short number)
{
    cout << "\n";
    cout << "Question [" << number + 1 << "/" << self.number_question << "] \n\n";
    cout << self.list_question[number].num_1 << endl;
    cout << self.list_question[number].num_2 << " ";
    cout << symbol(self.list_question[number].type_operation);
    cout << "\n_________" << endl;
}

void correct_answer(quizz &self, short number)
{
    if (self.list_question[number].choise_player != self.list_question[number].correct_answer)
    {
        self.list_question[number].result_answer = false;
        self.wrong_answer++;

        cout << "Worng Answer :-( \n";
        cout << "The right answer is: ";
        cout << self.list_question[number].correct_answer;
        cout << "\n";
    }
    else
    {
        self.list_question[number].result_answer = true;
        self.right_answer++;
        cout << "Right Answer :-) \n";
    }
    cout << endl;
    set_screen(self.list_question[number].result_answer);
}

void ask_list(quizz &self)
{
    for (short counter = 0; counter < self.number_question; counter++)
    {
        print_question(self, counter);
        self.list_question[counter].choise_player = read_answer();
        correct_answer(self, counter);
    }
    self.is_pass = (self.right_answer >= self.wrong_answer);
}

string final_text(bool Pass)
{
    if (Pass)
        return "PASS :-)";
    else
        return "Fail :-(";
}

void print_result(quizz self)
{
    cout << "\n";
    cout << "______________________________\n\n";
    cout << "Final Result is " << final_text(self.is_pass) << endl;
    cout << "\n______________________________\n\n";
    cout << "Number of Questions: " << self.number_question << endl;
    cout << "Questions Level: " << the_level(self.level_question) << endl;
    cout << "OpType: " << symbol(self.op_type) << endl;
    cout << "Number of Right Answers: " << self.right_answer << endl;
    cout << "Number of Wrong Answers: " << self.wrong_answer << endl;
    cout << "______________________________\n";
}

void math_game()
{
    quizz self;

    self.number_question = read_how_many();
    self.level_question = read_level();
    self.op_type = read_operation();

    generat_quizz(self);
    ask_list(self);
    print_result(self);
}

void reset()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void start_game()
{
    char play = 'Y';
    do
    {
        reset();
        math_game();
        cout << endl << "Do you want to play again? Y/N? ";
        cin >> play;
    } while (play == 'Y' || play == 'y');
}




int main()
{
    srand((unsigned)time(nullptr)); //Seeds the random number generator in C++, called only once
    start_game();
    return 0;
}




// for ubuntu from chatgpt:

// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// enum level { easy = 1, meduim = 2, hard = 3, mixo = 4 };
// enum operation { add = 1, sub = 2, multi = 3, devid = 4, mixa = 5 };

// string the_level(level self)
// {
//     string ray_level[4] = { "Easy", "Meduim", "Hard", "Mix" };
//     return ray_level[self - 1];
// }

// string symbol(operation self)
// {
//     switch (self)
//     {
//     case operation::add:
//         return "+";
//     case operation::sub:
//         return "-";
//     case operation::multi:
//         return "*";
//     case operation::devid:
//         return "/";
//     default:
//         return "Mix";
//     }
// }

// void set_screen(bool right)
// {
//     if (right)
//         cout << "\033[32mRight Answer :-) \033[0m\n"; // تغيير اللون إلى الأخضر
//     else
//     {
//         cout << "\033[31mWrong Answer :-( \033[0m\n"; // تغيير اللون إلى الأحمر
//     }
// }

// int random_number(int from, int to)
// {
//     int rand_num = rand() % (to - from + 1) + from;
//     return rand_num;
// }

// short read_how_many()
// {
//     short number = 1;
//     do
//     {
//         cout << "How Many Questions Do You Want to Answer ? ";
//         cin >> number;
//     } while (number < 1 || number > 10);
//     return number;
// }

// level read_level()
// {
//     short number = 1;
//     do
//     {
//         cout << "\nEnter Question Level: [1]: Easy, [2]: Med, [3]: Hard, [4]: Mix ? ";
//         cin >> number;
//     } while (number < 1 || number > 4);
//     return (level)number;
// }

// operation read_operation()
// {
//     short number = 1;
//     do
//     {
//         cout << "\nEnter Operation Type: [1]: Add, [2]: Minus, [3]: Multi, [4]: Devid, [5]: Mix ? ";
//         cin >> number;
//     } while (number < 1 || number > 5);
//     return (operation)number;
// }

// int read_answer()
// {
//     int answer = 0;
//     cin >> answer;
//     return answer;
// }

// struct question
// {
//     int num_1 = 0;
//     int num_2 = 0;
//     level type_question;
//     operation type_operation;
//     int correct_answer = 0;
//     int choise_player = 0;
//     bool result_answer = false;
// };

// struct quizz
// {
//     question list_question[100];
//     short number_question;
//     level level_question;
//     operation op_type;
//     short wrong_answer = 0;
//     short right_answer = 0;
//     bool is_pass = false;
// };

// int simple_calculator(int num_1, int num_2, operation op_type)
// {
//     switch (op_type)
//     {
//     case operation::add:
//         return num_1 + num_2;
//     case operation::sub:
//         return num_1 - num_2;
//     case operation::multi:
//         return num_1 * num_2;
//     case operation::devid:
//         if (num_2 != 0)
//             return num_1 / num_2;
//         else
//             return 0; // تجنب القسمة على الصفر
//     default:
//         return 0;
//     }
// }

// operation mix_operation()
// {
//     int number = random_number(1, 4);
//     return (operation)number;
// }

// question generat_question(level level_question, operation op_type)
// {
//     question self;
//     if (level_question == level::mixo)
//     {
//         level_question = (level)random_number(1, 3);
//     }
//     if (op_type == operation::mixa)
//     {
//         op_type = mix_operation();
//     }

//     self.type_operation = op_type;

//     switch (level_question)
//     {
//     case level::easy:
//         self.num_1 = random_number(1, 10);
//         self.num_2 = random_number(1, 10);
//         self.correct_answer = simple_calculator(self.num_1, self.num_2, self.type_operation);
//         self.type_question = level_question;
//         return self;

//     case level::meduim:
//         self.num_1 = random_number(11, 100);
//         self.num_2 = random_number(11, 100);
//         self.correct_answer = simple_calculator(self.num_1, self.num_2, self.type_operation);
//         self.type_question = level_question;
//         return self;

//     case level::hard:
//         self.num_1 = random_number(101, 1000);
//         self.num_2 = random_number(101, 1000);
//         self.correct_answer = simple_calculator(self.num_1, self.num_2, self.type_operation);
//         self.type_question = level_question;
//         return self;
//     }
//     return self;
// }

// void generat_quizz(quizz& self)
// {
//     for (short counter = 0; counter < self.number_question; counter++)
//     {
//         self.list_question[counter] = generat_question(self.level_question, self.op_type);
//     }
// }

// void print_question(quizz& self, short number)
// {
//     cout << "\n";
//     cout << "Question [" << number + 1 << "/" << self.number_question << "] \n\n";
//     cout << self.list_question[number].num_1 << " ";
//     cout << symbol(self.list_question[number].type_operation) << " ";
//     cout << self.list_question[number].num_2;
//     cout << "\n_________" << endl;
// }

// void correct_answer(quizz& self, short number)
// {
//     if (self.list_question[number].choise_player != self.list_question[number].correct_answer)
//     {
//         self.list_question[number].result_answer = false;
//         self.wrong_answer++;

//         cout << "Wrong Answer :-( \n";
//         cout << "The right answer is: ";
//         cout << self.list_question[number].correct_answer;
//         cout << "\n";
//     }
//     else
//     {
//         self.list_question[number].result_answer = true;
//         self.right_answer++;
//         cout << "Right Answer :-) \n";
//     }
//     cout << endl;
//     set_screen(self.list_question[number].result_answer);
// }

// void ask_list(quizz& self)
// {
//     for (short counter = 0; counter < self.number_question; counter++)
//     {
//         print_question(self, counter);
//         self.list_question[counter].choise_player = read_answer();
//         correct_answer(self, counter);
//     }
//     self.is_pass = (self.right_answer >= self.wrong_answer);
// }

// string final_text(bool Pass)
// {
//     if (Pass)
//         return "PASS :-)";
//     else
//         return "Fail :-(";
// }

// void print_result(quizz self)
// {
//     cout << "\n";
//     cout << "______________________________\n\n";
//     cout << " Final Result is " << final_text(self.is_pass) << endl;
//     cout << "Number of Questions: " << self.number_question << endl;
//     cout << "Questions Level: " << the_level(self.level_question) << endl;
//     cout << "OpType: " << symbol(self.op_type) << endl;
//     cout << "Number of Right Answers: " << self.right_answer << endl;
//     cout << "Number of Wrong Answers: " << self.wrong_answer << endl;
//     cout << "______________________________\n";
// }

// void math_game()
// {
//     quizz self;

//     self.number_question = read_how_many();
//     self.level_question = read_level();
//     self.op_type = read_operation();

//     generat_quizz(self);
//     ask_list(self);
//     print_result(self);
// }

// void reset()
// {
//     cout << "\033[H\033[J"; // تنظيف الشاشة
// }

// void start_game()
// {
//     char play = 'Y';
//     do
//     {
//         reset();
//         math_game();
//         cout << endl << "Do you want to play again? Y/N? ";
//         cin >> play;
//     } while (play == 'Y' || play == 'y');
// }

// int main()
// {
//     srand((unsigned)time(nullptr)); //Seeds the random number generator in C++, called only once
//     start_game();
//     return 0;
// }
