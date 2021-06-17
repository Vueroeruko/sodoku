#include "DigSudoku.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

DigSudoku::DigSudoku(vector < int > board, int n_hole)
{
    srand(time(NULL));//�H�����l�Ʈɶ��]�w���üƺؤl
    for (i = 0; i < SIZE * SIZE; i++) //�إ�0��80���Ʀr�ǦC
    {
        number_seres[i] = i;
    }
    for (i = 0; i < SIZE; i++)//�N��J���ƿW�D�ؼg�J��in_board�ܼ�
        for (j = 0; j < SIZE; j++)
        {
            in_board[i][j] = board[i * SIZE + j];

        }
    board_dig(n_hole);//�I�s���}�禡
}

void DigSudoku::board_dig(int n_hole)
{
    int temp; //�m���μȦs�ܼ�
    copy_board(); //�I�s�ƻs���
    for (i = 0; i < 81; i++) //�N�Ʀr�ǦC����
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
/*��X�����}���D�ئ�vector�ܼ�*/
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
�ƻs�ѽL�禡
copy in_board into dig_board
*/
{
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            dig_board[i][j] = in_board[i][j];
        }
}