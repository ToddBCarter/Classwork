/*Todd Carter
Section 3
Assignment 10
10-31-2021*/

/*This is the expanded boardgame.  This version puts you into the seat of
a maverick container ship captain racing against a rival maverick container
ship captain in a high-stakes gambit on the sea.  It features a board made of
waves with representations of each ship and their pursuers as they attempt
to flee from persecution to safety.  If the pursuing ship, labeled USN,
catches a player, that player loses immediately and the other wins, otherwise
either player that reaches the end of the board will win.  The navy ships
move slowly and fairly steadily across the board, whereas player movement
will be disrupted by frequent events.  The enemy ships represent the requested
extra variable that can end the game, as well as adding to the improved output.
The game itself can use a "clear" command sent to the system to refresh the 
screen so as to make following the movement of the ships intuitive, though 
the sample output does not use this clearing so as to be more easily copied out.*/

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
// Declaration of the square class
class square {
private:
    int move, fuzz;
    char symbol;
    string message;
public:
    square();
    void print();
    int action();
    int fuzzMod();
    void messag();
    void set(int, int, char, string);

};
// Function Prototypes
void print_board(square[], int, int, int);
void read_board(square[]);
void check_position(int&, int&);
// Global variables
const int board_length = 17;

int main() {
    int current_player = 1, roll;
    int player1_position = 0, player2_position = 0;
    int p1_heat = 0, p2_heat = 0;
    int nabbed1 = 1, nabbed2 = 1;
    square the_board[board_length];  // declare an array of squares
    srand(time(NULL));

    cout << "The sound of a foghorn catches your attention.\n";
    cout << "You lower your captain's binoculars, and see a fellow merchant vessel flashing their lights.\n";
    cout << "Your first mate grimaces.  He knows that look in your eye.\n";
    cout << "You push the pilot aside and slam the throttle forward.\n";
    cout << "Half a million tons of orange-clad container ship rumble, sending quakes through the stacks of multi-hued containers.\n";
    cout << "The crew begins running for cover as the alarms sound.\n";
    cout << "There's a distant sound of a dock being obliterated, but you ignore the chaos as cranes topple into the sea.\n";
    cout << "All you can see is the sea churning around the prow of the other container ship.\n";
    cout << "They've hit their engines.  That's it.\n";
    cout << "It's time.\nThe race is on!\n";
    cout << "\nThe rules are simple:  \n";
    cout << "Randomly rolled numbers send you from one wave to the next.\n";
    cout << "Each wave will have something happen, good, bad, or neither.\n";
    cout << "Only one ship makes it to safety, and the other gets nabbed by the Navy!\n";
    cout << "Be warned, the Navy has an APB out for you both!\n";
    cout << "If they end up on the same wave as you, you're nicked!\n";
    cout << "When you're ready, press enter!\nGood luck!\n\n\n";
    cin.ignore();

    system("cls");  //This is the clear command for Visual Studio.  Clearing here and in the do_while is needed.
    //system("clear");  //This is the clear command for Linux.  Clearing here and in the do_while is needed.
    read_board(the_board);
    cout << "The race begins!  Better hope luck is on your side, because the USN is not!\n\n";
    print_board(the_board, player1_position, 1, p1_heat);
    print_board(the_board, player2_position, 2, p2_heat);
    do {
        cout << "\n\n\nPlayer " << current_player << " press enter to roll.\n";
        cin.ignore();
        //system("clear");  //Clearing here and after the introduction is needed.
        system("cls");  //Clearing here and after the introduction is needed.
        roll = 1 + (rand() % 5);
        cout << "Player " << current_player << " rolled a " << roll << ".\n";
        if (current_player == 1) {
            player1_position += roll;
            check_position(player1_position, p1_heat);
            the_board[player1_position].messag();
            p1_heat += the_board[player1_position].fuzzMod();
            player1_position += the_board[player1_position].action();
            if (p1_heat == player1_position)
            {
                nabbed1 = 0;
            }
            check_position(player1_position, p1_heat);
        }
        else {
            player2_position += roll;
            check_position(player2_position, p2_heat);
            the_board[player2_position].messag();
            p2_heat += the_board[player2_position].fuzzMod();
            player2_position += the_board[player2_position].action();
            if (p2_heat == player2_position)
            {
                nabbed2 = 0;
            }
            check_position(player2_position, p2_heat);
        }
        print_board(the_board, player1_position, 1, p1_heat);
        print_board(the_board, player2_position, 2, p2_heat);
        current_player = (current_player % 2) + 1;
    } while ((player1_position < board_length - 1) && (player2_position < board_length - 1) && (nabbed1 != 0) && (nabbed2 != 0));
    current_player = (current_player % 2) + 1;

    if (nabbed1 == 0)
    {
        cout << "\nThe Navy catches up to Player 1!\n";
        cout << "\nThey're immediately blown to smithereens without warning.\nAmazon raises the deductible on their employee's health insurance to cover the cost.\n";
        cout << "\nPlayer 2 wins by still being alive!\n";
    }
    else if (nabbed2 == 0)
    {
        cout << "\nThe Navy catches up to Player 2!\n";
        cout << "\nPlayer 2 is captured and sent to live the rest of their days in Guantanamo.\n";
        cout << "\nPlayer 1 wins by default!\n";
    }
    else if (nabbed2 != 0 && nabbed1 != 0)
    {
        cout << "\nPlayer " << current_player << " makes it to safe waters!\n";
    }
    cout << "\n\n\Game Over!\n\n\n";
    return 0;
}

void read_board(square b[]) {
    ifstream infile;
    infile.open("game.txt");
    int square_number, square_move, square_fuzz;
    string square_message;
    char square_symbol;
    while (!infile.eof()) {
        infile >> square_number >> square_move >> square_fuzz >> square_symbol;
        getline(infile, square_message);
        if (square_number < board_length)
            b[square_number].set(square_fuzz, square_move, square_symbol, square_message);
    }
}
void print_board(square b[], int player_position, int player_number, int player_heat) 
{   
    for (int i = 0; i < board_length; i++) 
    {
        if (i != player_position && i != player_heat) 
        {
            cout << "       ";
        }
        else if (i == player_position && i == player_heat && i > 1)
        {
            cout << "  ___  ";
        }
        else if (i == player_position)
        {
            cout << " ______";            
        }
        else if (i == player_heat)
        {
            cout << "  ___  ";
        }
    }
    cout << "\n";
    for (int i = 0; i < board_length; i++)
    {
        if (i != player_position && i != player_heat) 
        {
            cout << "   ";
            b[i].print();
            cout << "   ";
        }
        else if (i == player_position && i == player_heat && i > 1)
        {
            cout << " (USN/ ";
        }
        else if (i == player_position)
        {
            cout << "(__" << player_number << "__/";
        }
        else if (i == player_heat)
        {
            cout << " (USN/ ";
        }
    }
    cout << "\n";
    for (int i = 0; i < board_length; i++) {
        cout << "_/)_/)_";
    }
    cout << "\n<-- Persecution of the need for speed";
    cout << "                                                         ";
    cout << "Free port at Singapore -->\n\n\n";
}
void check_position(int& p, int& q) {
    if (p < 0)
        p = 0;
    if (p >= board_length)
        p = board_length - 1;
    if (q < 0)
        q = 0;
    if (q >= board_length)
        q = 0;
}
// Functions of the class square
square::square() {
    symbol = ' ';
    move = 0;
    message = "";
    fuzz = 0;
}
int square::action() {
    //cout << message << endl;
    return move;
}
int square::fuzzMod() {
    //cout << message << endl;
    return fuzz;
}
void square::messag() {
    cout << message << endl;
}
void square::print() {
    cout << symbol;
}
void square::set(int n, int m, char s, string a_message) {
    move = m;
    fuzz = n;
    symbol = s;
    message = a_message;
}
