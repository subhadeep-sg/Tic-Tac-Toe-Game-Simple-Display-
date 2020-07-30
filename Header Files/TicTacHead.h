#pragma once
#include<iostream>
using namespace std;

const char space = ' ';
const int Row = 3;
const int Col = 3;
void init(char gameboard[Row][Col])     //Shows the position labels of the board
{
    char c = '1';
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            gameboard[i][j] = c;
            c += 1;

        }

    }
}
void board_reset(char gameboard[Row][Col])        //Resets the board
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            gameboard[i][j] = space;

        }
    }
}

void disp_board(char gameboard[Row][Col])       //Displays current state of board
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << "| " << gameboard[i][j] << " |";
            if (j == 3 && i != 3)
            {
                cout << "\n____________\n____________";

            }
        }
        cout << "\n";
    }
}

int update(char gameboard[Row][Col], int p, int a)       //Accepts input from either player
{
    switch (a)      //a indicates the position on the board(1,..,9) while p is player
    {
    case 1:   if (gameboard[0][0] != space)
    {
        cout << "Position has already been played!\n";
        return 1;
    }
          gameboard[0][0] =  (p == 0) ? 'X' : 'O';
          break;
    case 2:  if (gameboard[0][1] != space)
    {
        cout << "Position has already been played!\n";
        return 1;
    }
          gameboard[0][1] =  (p == 0) ? 'X' : 'O' ;
          break;
    case 3:  if (gameboard[0][2] != space)
    {
        cout << "Position has already been played!\n";
        return 1;
    }
          gameboard[0][2] = (p == 0) ? 'X' : 'O' ;
          break;
    case 4:  if (gameboard[1][0] != space)
    {
        cout << "Position has already been played!\n";
        return 1;
    }
          gameboard[1][0] = (p == 0) ? 'X' : 'O';
          break;
    case 5:  if (gameboard[1][1] != space)
    {
        cout << "Position has already been played!\n";
        return 1;
    }
          gameboard[1][1] = (p == 0) ? 'X' : 'O';
          break;
    case 6:  if (gameboard[1][2] != space)
    {
        cout << "Position has already been played!\n";
        return 1;
    }
          gameboard[1][2] = (p == 0) ? 'X' : 'O';
          break;
    case 7:  if (gameboard[2][0] != space)
    {
        cout << "Position has already been played!\n";
        return 1;
    }
          gameboard[2][0] = (p == 0) ? 'X' : 'O' ;
          break;
    case 8:   if (gameboard[2][1] != space)
    {
        cout << "Position has already been played!\n";
        return 1;
    }
          gameboard[2][1] = (p == 0) ? 'X' : 'O';
          break;
    case 9: if (gameboard[2][2] != space)
    {
        cout << "Position has already been played!\n";
        return 1;
    }
          gameboard[2][2] =(p == 0) ? 'X' : 'O';
          break;
    default: cout << "Please enter a valid position!!\n";
        return 1;
        break;
    }
    return 0;
}

int win_con(char gameboard[Row][Col])       //Checks for win condtions
{
    for (int i = 0; i < 3; ++i)
    {   //Row win check
        if (gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2] && gameboard[i][0] != space)
        {
            return (gameboard[i][0] == 'X') ? 0 : 1;

        }
        //Column win check
        else if (gameboard[0][i] == gameboard[1][i] && gameboard[0][i] == gameboard[2][i] && gameboard[0][i] != space)
        {
            return (gameboard[0][i] == 'X') ? 0 : 1;
        }
        //Diagonal win check
        else if (gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2] && gameboard[0][0] != space)
        {
            return (gameboard[0][0] == 'X') ? 0 : 1;
        }
        //Minor Diagonal win check
        else if (gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0] && gameboard[0][2] != space)
        {
            return (gameboard[0][2] == 'X') ? 0 : 1;
        }
    }
    return 2;
}

int draw_cond(char gameboard[Row][Col])     //Checks for guaranteed draw condition
{
    int ctr = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (gameboard[i][j] != space)
                ctr++;
        }
        if (ctr >= 8)       //If board is filled with atleast 8 numbers and there isn't a win, it's draw
            return 1;
    }
    return 2;
}

void Multimode(char gameboard[Row][Col], int p)     //Mechanics of the Multiplayer TicTacToe
{
    int stat, a;
    while (win_con(gameboard) == 2 && draw_cond(gameboard) == 2)
    {
        cout << "Player " << p + 1 << " enter position:";
        cin >> a;
        if (a == 0)
        {
            cout << "\nGame Terminated!\n";
            break;
        }
        stat = update(gameboard, p, a);
        if (stat == 0)
            disp_board(gameboard);
        else
            p = !p;
        p = !p;
    }
    if (win_con(gameboard) != 2)
        cout << "\nPLAYER " << win_con(gameboard) + 1 << " WINS THE GAME!";
    else if (draw_cond(gameboard) != 2)
        cout << "\nGAME IS A DRAW!";
}

void error()        //When selecting mode, if any other number is entered error message is shown
{
    cout << "\nPlease enter valid number!\n";
}

