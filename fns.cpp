#include <iostream>
#include <vector>
#include "fns.hpp"


char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int input;
int row, column;
char turn = 'X';
int counter = 1;


void display_board()
{
if(turn == 'X')
std::cout << "Player - 1 [X]\n";
else
std::cout << "Player - 2 [O]\n";
std::cout << " |     |\n";
std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
std::cout << "_____|_____|_____\n";
std::cout << " | |\n";
std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
std::cout << "_____|_____|_____\n";


std::cout << " | |\n";
std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
std::cout << " | | \n";
}


//=============PLAYER TURN=================
void player_turn()
{
std::cout << "Number from 1-9: ";
std::cin >> input;
counter++;
if(input == 1)
{
row = 0; column = 0;
}
if(input == 2)
{
row = 0; column = 1;
}
if(input == 3)
{
row = 0; column = 2;
}
if(input == 4)
{
row = 1; column = 0;
}
if(input == 5)
{
row = 1; column = 1;
}
if(input == 6)
{
row = 1; column = 2;
}
if(input == 7)
{
row = 2; column = 0;
}
if(input == 8)
{
row = 2; column = 1;
}
if(input == 9)
{
row = 2; column = 2;
}


if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
{
board[row][column] = turn;
turn = 'O';
}
else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
{
board[row][column] = turn;
turn = 'X';
}
else
{
std::cout << "Invalid input\n";
counter--;
}
}


//===========IS GAME OVER?================
bool is_game_over()
{
for(int i = 0; i < 3; i++)
{
//checking rows and columns
if(board[i][0] == board[i][1] && board[i][1] == board[i][2] || board[0][i] == board[1][i]&& board[1][i] == board[2][i] )
{
return false;
}
}
//checking diagonals
if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[2][0] == board[1][1] && board[2][0] == board[0][2])
{
return false;
}


//checking if game should continue
for(int i = 0; i < 3; i++)
{
for(int j = 0; j< 3; j++)
{
if(board[i][j] != 'O' || board[i][j] != 'X')
{
return true;
}
}
}
}


//===========DISPLAY WINNER===========
void display_winner()
{
if(turn == 'X' && counter <= 9)
{
std::cout << "Player - O won!\n";
}
else if(turn == 'O'&& counter <= 9)
{
std::cout << "Player - X won!\n";
}
else
{
std::cout << "Draw!\n";
}
}


int count()
{
return counter;
}
