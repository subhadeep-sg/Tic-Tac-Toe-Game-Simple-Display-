// TicTacToeAttem2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>
#include "TicTacHead.h"
#include "GameAI.h"
using namespace std;

char gameboard[Row][Col] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };

int main()
{
    int p=0,mode;
    cout << "Welcome!\n"
         << "Simply enter the position where you would like to place your X or O\n"
         << "Note if you want to exit the game pls enter 0\n";
    init(gameboard);
    disp_board(gameboard);
    board_reset(gameboard);
    cout << "\n"
         << "Multiplayer or Single Player? 1.Multi 2.Single";
    cin >> mode;
    
    (mode == 1) ? Multimode(gameboard, p) :(mode==2)? Singlemode(gameboard,  p): error();
    
    cout << "\nGAME TERMINATED!";
    return 0;
}



