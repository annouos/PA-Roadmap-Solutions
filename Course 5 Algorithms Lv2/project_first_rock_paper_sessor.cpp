
#include <iostream>
#include <cstdlib>

using namespace std;

enum choise { Rock = 1, Paper = 2, Scissor = 3};
enum winner { Player = 1, PC = 2, Draw = 3};

string the_items(choise self)
{
    string ray_items[3] = {"Rock", "Paper", "Scissor"};
    return ray_items[self - 1];
}      

string the_champion(winner self)
{
    string ray_winner[3] = {"Player", "PC", "No Winner"};
    return ray_winner[self - 1];
}

struct info
{
    short round_number = 0;
    choise player_choise;
    choise pc_choise;
    winner hero;
    string winner_name;
};

struct result
{
    short game_round = 0;
    short player_win_times = 0;
    short pc_win_times = 0;
    short draw_times = 0;
    winner game_winner;
    string winner_name = "";
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
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> number;       
    } while (number < 1 || number > 10);
    return number;
}

choise read_player()
{
    short number = 1;
    do
    {
        cout << "\nYour Choice: [1]: Rock, [2]: Paper, [3]: Scissors ? ";
        cin >> number;        
    } while (number < 1 || number > 3);
    return (choise) number;
}

choise read_pc()
{
    return (choise) random_number(1,3);
}

winner who_won_round(info self)
{
    if (self.player_choise == self.pc_choise)
    {
        return winner::Draw;
    }
    switch (self.player_choise)
    {
        case choise::Rock :
        if (self.pc_choise == choise::Paper)
        {
            return winner::PC;
        }
        break;
        case choise::Paper :
        if (self.pc_choise == choise::Scissor)
        {
            return winner::PC;
        }
        break;
        case choise::Scissor :
        if (self.pc_choise == choise::Rock)
        {
            return winner::PC;
        }
        break;
    }
    return winner::Player;
}

winner who_won_game(short player_win_times, short pc_win_times)
{
    if (player_win_times > pc_win_times)
        return winner::Player;
    else if (pc_win_times > player_win_times)
        return winner::PC;
    else
        return winner::Draw;
}

result fill_struct(int rounds, short player_win_times, short pc_win_times, short draw_times)
{
    result self;
    self.game_round = rounds;
    self.player_win_times = player_win_times;
    self.pc_win_times = pc_win_times;
    self.draw_times = draw_times;
    self.game_winner = who_won_game(player_win_times, pc_win_times);
    self.winner_name = the_champion(self.game_winner);
    return self;
}

void screen_color(winner self)
{
    switch (self)
    {
        case winner::Player :
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        break;
        case winner::PC :
        cout << "oooooooooooooooooooooooooooooooooo\n";
        break;
        case winner::Draw :
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        break;
    }
}

void print_round(info self)
{
    cout << "\n____________Round [" << self.round_number << "] ____________\n\n";
    cout << "Player1 Choice: " << the_items(self.player_choise) << endl;
    cout << "Computer Choice: " << the_items(self.pc_choise) << endl;
    cout << "Round Winner: [" << self.winner_name << "]\n";
    cout << "__________________________________\n" << endl;
    screen_color(self.hero);
}

result play_game(short how_many)
{
    info self;
    short player_win_times = 0, pc_win_times = 0, draw_times = 0;
    for(short counter = 1; counter <= how_many; counter++)
    {
        cout << "\nRound [" << counter << "] begins:\n";
        self.round_number = counter;
        self.player_choise = read_player();
        self.pc_choise = read_pc();
        self.hero = who_won_round(self);
        self.winner_name = the_champion(self.hero);

        if (self.hero == winner::Player) //Increase win/Draw counters
            player_win_times++;
        else if (self.hero == winner::PC)
            pc_win_times++;
        else
            draw_times++;
        print_round(self);
    }
    return fill_struct(how_many, player_win_times, pc_win_times, draw_times);
}

string tabs(short number)
{
    string t = "";
    for (int i = 0; i < number; i++)
    {
        t += "\t";
    }
    return t;
}

void game_over()
{
    cout << tabs(2) << "__________________________________________________________\n\n";
    cout << tabs(2) << "              +++ G a m e O v e r +++\n";
    cout << tabs(2) << "__________________________________________________________\n\n";
}

void show_final(result self)
{
    cout << tabs(2) << "_____________________ [Game Results]_____________________\n\n";
    cout << tabs(2) << "Game Rounds: " << self.game_round << endl;
    cout << tabs(2) << "Player1 won times : " << self.player_win_times << endl;
    cout << tabs(2) << "Computer won times : " << self.pc_win_times << endl;
    cout << tabs(2) << "Draw times: " << self.draw_times << endl;
    cout << tabs(2) << "Final Winner: " << self.winner_name << endl;
    cout << tabs(2) << "___________________________________________________________\n";
    screen_color(self.game_winner);
}

void reset()
{
    cout << "\n__________________________________\n\n";
}

void start_game()
{
    char play_again = 'Y';
    do
    {
        reset();
        result self = play_game(read_how_many());
        game_over();
        show_final(self);
        cout << endl << tabs(3) << "Do you want to play again? Y/N? ";
        cin >> play_again; 
    } while (play_again == 'Y' || play_again == 'y');
}



int main()
{
    srand((unsigned)time(nullptr));
    start_game();
    return 0;
}









// #include <iostream>
// #include <cstdlib>

// using namespace std;

// string ray[3] = {"Rock ", "Paper ", "Scissor "};
// struct info {int win = 0, loss = 0, draw = 0;};

// int positiv_number(string massage)
// {
//     int number = 0;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number < 0 && number >= 3);
//     return number;
// }

// int get_round(string massage)
// {
//     int number = 0;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number <= 0);
//     return number;
// }

// int random(int from, int to)
// {
//     int random = rand() % (to - from + 1) + from;
//     return random;
// }

// string read_janki(int number)
// {
//     return ray[number-1];
// }

// short the_game(int player, int pc)
// {
//     if(read_janki(player) == read_janki(pc))
//     {
//         cout << ray[player-1] << ray[pc-1] << "You are DRAW " << endl;
//         return 3;
//     }
//     else if(read_janki(player) == "Rock " && read_janki(pc) == "Scissor ")
//     {
//         cout << ray[player-1] << ray[pc-1] << "Player WIN " << endl;
//         return 1;
//     }
//     else if(read_janki(player) == "Paper " && read_janki(pc) == "Rock ")
//     {
//         cout << ray[player-1] << ray[pc-1] << "Player WIN " << endl;
//         return 1;
//     }
//     else if(read_janki(player) == "Scissor " && read_janki(pc) == "Paper ")
//     {
//         cout << ray[player-1] << ray[pc-1] << "Player WIN " << endl;
//         return 1;
//     }
//     else if(read_janki(player) == "Scissor " && read_janki(pc) == "Rock ")
//     {
//         cout << ray[player-1] << ray[pc-1] << "PC WIN " << endl;
//         return 2;
//     }
//     else if(read_janki(player) == "Rock " && read_janki(pc) == "Paper ")
//     {
//         cout << ray[player-1] << ray[pc-1] << "PC WIN " << endl;
//         return 2;
//     }
//     else if(read_janki(player) == "Paper " && read_janki(pc) == "Scissor ")
//     {
//         cout << ray[player-1] << ray[pc-1] << "PC WIN " << endl;
//         return 2;
//     }
//     else
//     {
//         return 0;
//     }
// }

// void rounds(int number, info &self)
// {
//     for(int i = 1; i <= number; i++)
//     {
//         cout << "Round number [" << i << "]: " << endl;
//         int result = the_game(positiv_number("Enter choise 1 or 2 or 3: "), random(1,3));
//         switch(result)
//         {
//             case 1 :
//             self.win++;
//             break;
//             case 2 :
//             self.loss++;
//             break;
//             case 3 :
//             self.draw++;
//             break;
//             default :
//             cout << "Dame Li";
//         }
//     }
// }

// void start()
// {
//     bool play = true; info self;
//     do 
//     {
//         rounds(get_round("How many do you want play: "), self);
//         cout << "\n\nDo you want play again ! ";
//         cin >> play;
//     } while (play == true);
//     cout << "\nGame Over " << endl;
//     cout << "\nThe Player Win : " << self.win << endl;
//     cout << "\nThe PC Win : " << self.loss << endl;
//     cout << "\nThe Draw : " << self.draw << endl;
// }



// int main()
// {
//     start();
//     return 0;
// }




// #include <iostream>
// #include <cstdlib>

// using namespace std;

// enum eninfo { rock = 1, paper = 2, sissor = 3};
// struct info {int win = 0, loss = 0, draw = 0;};

// int positiv_number(string massage)
// {
//     int number = 0;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number <= 0 || number >= 4);
//     return number;
// }

// int get_round(string massage)
// {
//     int number = 0;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number <= 0);
//     return number;
// }

// int random(int from, int to)
// {
//     int random = rand() % (to - from + 1) + from;
//     return random;
// }

// eninfo read_janki(int number)
// {
//     return (eninfo) number;
// }

// string tools(eninfo self)
// {
//     switch(self)
//     {
//         case eninfo::rock :
//         return "Rock";
//         case eninfo::paper :
//         return "Paper";
//         case eninfo::sissor :
//         return "Scissor";
//         default :
//         return "\0";
//     }
// }

// short the_game(string player, string pc)
// {
//     if( player == "Rock" && pc == "Scissor" )
//     {
//         cout << player << " " << pc << " Player Win" << endl;
//         return 1;
//     }
//     else if(player == "Paper" && pc == "Rock" )
//     {
//         cout << player << " " << pc << " Player Win" << endl;
//         return 1;
//     }
//     else if(player == "Scissor" && pc == "Paper" )
//     {
//         cout << player << " " << pc << " Player Win" << endl;
//         return 1;
//     }
//     else if( player == "Scissor" && pc == "Rock" )
//     {
//         cout << player << " " << pc << " PC Win" << endl;
//         return 2;
//     }
//     else if( player == "Rock" && pc == "Paper" )
//     {
//         cout << player << " " << pc << " PC Win" << endl;
//         return 2;
//     }
//     else if(player == "Paper" && pc == "Scissor" )
//     {
//         cout << player << " " << pc << " PC Win" << endl;
//         return 2;
//     }
//     else
//     {
//         cout << player << " " << pc << " You are DRAW" << endl;
//         return 3;
//     }
// }

// void round_game(int number, info &self)
// {
//     for(int i = 1; i <= number; i++)
//     {
//         cout << "\n\nThe Round [" << i << "] :" << endl;
//         switch(the_game(tools(read_janki(positiv_number("\nPlease enter your choise: [1] Rock [2] Paper [3] Scissor : "))), tools(read_janki(random(1,3)))))
//         {
//             case 1 :
//             self.win++;
//             break;
//             case 2 :
//             self.loss++;
//             break;
//             case 3 :
//             self.draw++;
//             break;
//             default :
//             cout << "Dame Li";
//         }
//     }
// }

// void start()
// {
//     bool play = true; info self;
//     do 
//     {
//         round_game(get_round("\nHow many do you want Play ? "), self);
//         cout << "\n\nDo you want play again ! ";
//         cin >> play;
//     } while (play == true);
//     cout << "\nGame Over " << endl;
//     cout << "\nThe Player Win : " << self.win << endl;
//     cout << "\nThe PC Win : " << self.loss << endl;
//     cout << "\nThe Draw : " << self.draw << endl;
// }



// int main()
// {
//     start();
//     return 0;
// }
