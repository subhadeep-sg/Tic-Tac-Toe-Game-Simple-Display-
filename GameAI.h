#pragma once
#include<iostream>
#include "TicTacHead.h"

int centreseek(char gameboard[Row][Col], int p)      //Seeks centre if possible
{
    if (gameboard[1][1] == space)
    {
        return update(gameboard, p, 5);
    }
    return 2;
}




int seekdiag(char gameboard[Row][Col], int p)       //Seeks to play a diagonal if possible
{
    if (gameboard[0][0] == space)
        return update(gameboard, p, 1);
    else if (gameboard[2][2] == space)
        return update(gameboard, p, 9);
    else if (gameboard[2][0] == space)
        return update(gameboard, p, 7);
    else if (gameboard[0][2] == space)
        return update(gameboard, p, 3);
    return 2;
}

int danger(char gameboard[Row][Col], int p)      //Prevents a win possibility
{
    int a;
    for (int i = 0; i < 3; ++i)
    {   //Row check danger
        if ((gameboard[i][0] == gameboard[i][1] && gameboard[i][2] == space && gameboard[i][0] != space) ||
            (gameboard[i][0] == space && gameboard[i][1] == gameboard[i][2] && gameboard[i][1] != space) ||
            (gameboard[i][1] == space && gameboard[i][0] == gameboard[i][2] && gameboard[i][0] != space))
        {
            if (gameboard[i][0] == space)
                a = (i == 0) ? 1 : (i == 1) ? 4 : 7;
            else if (gameboard[i][1] == space)
                a = (i == 0) ? 2 : (i == 1) ? 5 : 8;
            else if (gameboard[i][2] == space)
                a = (i == 0) ? 3 : (i == 1) ? 6 : 9;
            return update(gameboard, p, a);
        }
        //Column Check Danger
        else if ((gameboard[0][i] == gameboard[1][i] && gameboard[2][i] == space && gameboard[0][i] != space) ||
            (gameboard[0][i] == space && gameboard[1][i] == gameboard[2][i] && gameboard[1][i] != space) ||
            (gameboard[1][i] == space && gameboard[0][i] == gameboard[2][i] && gameboard[0][i] != space))
        {
            if (gameboard[0][i] == space)
                a = (i == 0) ? 1 : (i == 1) ? 2 : 3;
            else if (gameboard[1][i] == space)
                a = (i == 0) ? 4 : (i == 1) ? 5 : 6;
            else if (gameboard[2][i] == space)
                a = (i == 0) ? 7 : (i == 1) ? 8 : 9;
            return update(gameboard, p, a);
        }
        //Diagonal Check Danger
        else if ((gameboard[0][0] == gameboard[1][1] && gameboard[2][2] == space && gameboard[0][0] != space) ||
            (gameboard[0][0] == space && gameboard[1][1] == gameboard[2][2] && gameboard[1][1] != space) ||
            (gameboard[1][1] == space && gameboard[0][0] == gameboard[2][2] && gameboard[0][0] != space))
        {
            if (gameboard[0][0] == space)
                return update(gameboard, p, 1);
            else if (gameboard[i][1] == space)
                return update(gameboard, p, 5);
            else if (gameboard[i][0] == space)
                return update(gameboard, p, 9);

        }
        //Minor Diagonal Check Danger
        else if ((gameboard[2][0] == gameboard[1][1] && gameboard[0][2] == space && gameboard[2][0] != space) ||
            (gameboard[2][0] == space && gameboard[1][1] == gameboard[0][2] && gameboard[1][1] != space) ||
            (gameboard[1][1] == space && gameboard[2][0] == gameboard[0][2] && gameboard[2][0] != space))
        {
            if (gameboard[2][0] == space)
                return update(gameboard, p, 7);
            else if (gameboard[1][1] == space)
                return update(gameboard, p, 5);
            else if (gameboard[0][2] == space)
                return update(gameboard, p, 3);

        }

    }
    return 2;
}



int winningplay(char gameboard[Row][Col], int p)
{
    int a;
    char s = (p == 0) ? 'X' : 'O';
    for (int i = 0; i < 3; ++i)
    {   //Row check danger
        if ((gameboard[i][0] == gameboard[i][1] && gameboard[i][2] == space && gameboard[i][0] == s) ||
            (gameboard[i][0] == space && gameboard[i][1] == gameboard[i][2] && gameboard[i][1] == s) ||
            (gameboard[i][1] == space && gameboard[i][0] == gameboard[i][2] && gameboard[i][0] == s))
        {
            if (gameboard[i][0] == space)
                a = (i == 0) ? 1 : (i == 1) ? 4 : 7;
            else if (gameboard[i][1] == space)
                a = (i == 0) ? 2 : (i == 1) ? 5 : 8;
            else if (gameboard[i][2] == space)
                a = (i == 0) ? 3 : (i == 1) ? 6 : 9;
            return update(gameboard, p, a);
        }
        //Column Check Danger
        else if ((gameboard[0][i] == gameboard[1][i] && gameboard[2][i] == space && gameboard[0][i] == s) ||
            (gameboard[0][i] == space && gameboard[1][i] == gameboard[2][i] && gameboard[1][i] == s) ||
            (gameboard[1][i] == space && gameboard[0][i] == gameboard[2][i] && gameboard[0][i] == s))
        {
            if (gameboard[0][i] == space)
                a = (i == 0) ? 1 : (i == 1) ? 2 : 3;
            else if (gameboard[1][i] == space)
                a = (i == 0) ? 4 : (i == 1) ? 5 : 6;
            else if (gameboard[2][i] == space)
                a = (i == 0) ? 7 : (i == 1) ? 8 : 9;
            return update(gameboard, p, a);
        }
        //Diagonal Check Danger
        else if ((gameboard[0][0] == gameboard[1][1] && gameboard[2][2] == space && gameboard[0][0] == s) ||
            (gameboard[0][0] == space && gameboard[1][1] == gameboard[2][2] && gameboard[1][1] == s) ||
            (gameboard[1][1] == space && gameboard[0][0] == gameboard[2][2] && gameboard[0][0] == s))
        {
            if (gameboard[0][0] == space)
                return update(gameboard, p, 1);
            else if (gameboard[i][1] == space)
                return update(gameboard, p, 5);
            else if (gameboard[i][0] == space)
                return update(gameboard, p, 9);

        }
        //Minor Diagonal Check Danger
        else if ((gameboard[2][0] == gameboard[1][1] && gameboard[0][2] == space && gameboard[2][0] == s) ||
            (gameboard[2][0] == space && gameboard[1][1] == gameboard[0][2] && gameboard[1][1] == s) ||
            (gameboard[1][1] == space && gameboard[2][0] == gameboard[0][2] && gameboard[2][0] == s))
        {
            if (gameboard[2][0] == space)
                return update(gameboard, p, 7);
            else if (gameboard[1][1] == space)
                return update(gameboard, p, 5);
            else if (gameboard[0][2] == space)
                return update(gameboard, p, 3);

        }

    }
    return 2;
}

int idealpos(char gameboard[Row][Col], int p)
{
    return winningplay(gameboard, p);
    return danger(gameboard, p);
    return 0;
}

void react(char gameboard[Row][Col], int p)
{
    int stat = 1, stat2, stat3;
    if (p != 0)
        stat = centreseek(gameboard, p);
    if (stat == 1)
    {
        stat2 = seekdiag(gameboard, p);
        if (stat2 == 1)
        {
            stat3 = idealpos(gameboard, p);
        }
    }
}

void secplr(char gameboard[Row][Col])
{
    int p = 1, a, st, sta, stat, state;
    st = centreseek(gameboard, 0);
    disp_board(gameboard);
    while (win_con(gameboard) == 2 && draw_cond(gameboard) == 2)
    {
        cout << "\nPlayer " << p + 1 << " enter position";
        cin >> a;
        if (a == 0)
        {
            cout << "\nGame Terminated!\n";
            break;
        }
        stat = update(gameboard, 1, a);
        if (stat == 0)
        {
            state = winningplay(gameboard, 0);
            if (state == 2)
                sta = danger(gameboard, 0);
            if (sta == 2 && state == 2)
                react(gameboard, 0);
            disp_board(gameboard);
        }
    }
    if (win_con(gameboard) != 2)
        cout << "\nPLAYER " << win_con(gameboard) + 1 << " WINS THE GAME!";
    else if (draw_cond(gameboard) != 2)
        cout << "\nGAME IS A DRAW!";
}
int weakness(char gameboard[Row][Col], int p)   //The diagonal trap is avoided
{
    int a;
    if (gameboard[0][0] == gameboard[2][2] && gameboard[0][0] != space)
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if ((j + i) % 2 != 0)
                {
                    a = (i == 0) ? 2 : ((j == 0) ? 4 : ((i == 2) ? 8 : 6));
                    if (gameboard[i][j] == space)
                        return update(gameboard, p, a);

                }
            }
        }
    else if (gameboard[0][2] == gameboard[2][0] && gameboard[0][2] != space)
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if ((j + i) % 2 != 0)
                {
                    a = (i == 0) ? 2 : ((j == 0) ? 4 : ((i == 2) ? 8 : 6));
                    if (gameboard[i][j] == space)
                        return update(gameboard, p, a);

                }
            }
        }
    return 2;
}

int index(int i, int j)
{
    if (i == 0)
        if (j == 0)
            return 1;
        else if (j == 1)
            return 2;
        else
            return 3;
    else if(i==1)
        if (j == 0)
            return 4;
        else if (j == 1)
            return 5;
        else
            return 6;
    else
        if (j == 0)
            return 7;
        else if (j == 1)
            return 8;
        else
            return 9;
}

int playrand(char gameboard[Row][Col], int p)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (gameboard[i][j] == space)
            {
                int a = index(i, j);
                return update(gameboard, p, a);
            }
        }
    }
    return 2;
}
//Reactionary moves to previous plays
void firreact(char gameboard[Row][Col], int p)
{
    int prio1, prio2, prio3, prio4;
    prio1 = centreseek(gameboard, p);
    if (prio1 == 2)
    {
        prio2 = seekdiag(gameboard, p);
        if (prio2 == 2)
        {
            prio3 = idealpos(gameboard, p);
            if (prio3 == 2)
               prio4 = playrand(gameboard, p);
        }
    }
}

void firplr(char gameboard[Row][Col])       //User plays first and Computer plays second
{
    int p = 0, a, st, sta, stat, state, state1;
    while (win_con(gameboard) == 2 && draw_cond(gameboard) == 2)
    {
        cout << "\nPlayer " << p + 1 << " enter position";
        cin >> a;
        if (a == 0)
        {
            cout << "\nGame Terminated!\n";
            break;
        }
        stat = update(gameboard, 0, a);
        if (stat == 0)
        {
            state = winningplay(gameboard, 1);
            if (state == 2)
            {
                sta = danger(gameboard, 1);
                if (sta == 2)
                {
                    state1 = weakness(gameboard, 1);
                }
            }
            if (sta == 2 && state == 2 && state1 == 2)
                firreact(gameboard, 1);
            disp_board(gameboard);
        }
    }
    //st = centreseek(gameboard, 0);
   // disp_board(gameboard);

    if (win_con(gameboard) != 2)
        cout << "\nPLAYER " << win_con(gameboard) + 1 << " WINS THE GAME!";
    else if (draw_cond(gameboard) != 2)
        cout << "\nGAME IS A DRAW!";
}
void Singlemode(char gameboard[Row][Col], int p)
{
    int turn;
    // cout << "\nUnder work!\n";
    cout << "Do you want to go first? 1.Yes 2.No";
    cin >> turn;
    (turn == 1) ? firplr(gameboard) : (turn == 2) ? secplr(gameboard) : error();
}