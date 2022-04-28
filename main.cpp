/// Program to run Tic Tac Toe On the terminal.

#include <iostream>
#include <stdlib.h>

using namespace std;
int choice;
char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int row,column;
char turn= 'x';
char x , o;
bool draw= false;

void display_board()
{
    /*
    This function draws the board.
    */

    cout << "\nPlayer 1 [x]   Player 2[o]\n";
    cout << "\n       |       |   \n";
    cout << "  "<<board[0][0]<< "    |  " <<  board[0][1]<< "    | "<< board[0][2]<<"    \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |        \n";
    cout << "  "<<board[1][0]<< "    | " <<   board[1][1]<< "     | "<< board[1][2]<<"    \n";
    cout << "_______|_______|_______ \n";
    cout << "       |       |      \n";
    cout << "  "<<board[2][0]<< "    | " <<   board[2][1]<< "     | "<< board[2][2]<<"    \n";
    cout << "       |       |       \n";

}

void player_turn()
{
    /*
    This function Checks which players' turn it is,
    Then Takes in put from that player and changes value
    of the board array.
    */

    if (turn == 'x')
    cout<< "Player 1's turn:";
    else if (turn == 'o')
    cout<< "Player 2's turn:";

    cin>> choice;

    switch (choice)
    {
        case 1: row = 0 ; column =0;
        break;
        case 2: row = 0 ; column = 1;
        break;
        case 3: row = 0 ; column = 2;
        break;
        case 4: row = 1 ; column = 0;
        break;
        case 5: row = 1 ; column = 1;
        break;
        case 6: row = 1 ; column = 2;
        break ;
        case 7: row = 2 ; column = 0;
        break;
        case 8: row = 2 ; column = 1;
        break;
        case 9: row = 2 ; column = 2;
        break;
        default:
            cout<< "\nInvalid move\n";
    }
        if (turn == 'x' && board [row][column]!= 'x' && board [row][column]!='o')
        {
            board [row][column]= 'x';
            turn = 'o';
        }
        else if (turn == 'o' && board [row][column]!= 'x' && board [row][column]!='o')
        {
            board [row][column]= 'o';
            turn = 'x';
        }
        else
        {
            cout<< "space is filled try again!!";
            player_turn();
        }

    display_board();
}
bool game()
{
    /*
    Checks whether a player has won the game
    */


    // Checking the result by simple horizontal and vertical check
    for (int i=0; i<3; i++)
    if (board [i][0]== board[i][1] && board[i][0]== board [i][2] || board [0][i]== board [1][i] && board [0][i]==board[2][i])
    return false;

    // checking the result by diagonal check
    if (board[0][0]==board [1][1] && board [0][0]== board [2][2] || board [0][2] == board [1][1] && board [0][2] == board [2][0])
    return false;

    // checking if game is continue or not
    for (int i=0; i<3; i++)
    for (int j=0; j<3;j++)

    if (board [i][j]!='x' && board [i][j]!='o')
    return true;

    draw = true;
    return false;


}

int main ()
{
    cout<< "\t\tTIC-TAC-ToE-GAME\n";
    cout<< "\t\tFOR 2 PLAYERS";
    while (game())
    {
        cout<<turn<<endl;
        display_board();
        player_turn();
        game();
    }
    if (turn == 'x'&& draw == false)
    {
        cout << "\n congratulations ! Player with 'o' has won the game";
    }
    else if (turn == 'o' && draw ==false)
    {
        cout << "Congratulations! Player with 'x' has won the game";
    }
    else
        cout << "Game Draw!!";
return 0;

}

