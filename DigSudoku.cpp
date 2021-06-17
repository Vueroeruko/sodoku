#include "DigSudoku.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

DigSudoku::DigSudoku(vector < int > board, int n_hole)
{
    srand(time(NULL));//以物件初始化時間設定為亂數種子
    for (i = 0; i < SIZE * SIZE; i++) //建立0到80的數字序列
    {
        number_seres[i] = i;
    }
    for (i = 0; i < SIZE; i++)//將輸入的數獨題目寫入至in_board變數
        for (j = 0; j < SIZE; j++)
        {
            in_board[i][j] = board[i * SIZE + j];

        }
    board_dig(n_hole);//呼叫挖洞函式
}

void DigSudoku::board_dig(int n_hole)
{
    int temp; //置換用暫存變數
    copy_board(); //呼叫複製函數
    for (i = 0; i < 81; i++) //將數字序列打亂
    {
        j = rand() % 81;
        temp = number_seres[i];
        number_seres[i] = number_seres[j];
        number_seres[j] = temp;
    }
    for (i = 0; i < n_hole; i++)
    {
        dig_board[number_seres[i] / SIZE][number_seres[i] % SIZE] = 0;
    }
}

vector < int > DigSudoku::get_board()
/*輸出挖完洞的題目至vector變數*/
{
    vector < int > out_board(SIZE * SIZE);
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            out_board[i * SIZE + j] = dig_board[i][j];
        }
    return out_board;
}

void DigSudoku::copy_board()
/*
複製棋盤函式
copy in_board into dig_board
*/
{
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            dig_board[i][j] = in_board[i][j];
        }
}