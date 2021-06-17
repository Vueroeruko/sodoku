#include "SolveSudoku.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int SolveSudoku::Ans = 0; //�ƿW�ѭӼƭp�ƾ� (Global�ܼ�)
SolveSudoku::SolveSudoku(vector<int> board, int A)
{
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            in_board[i * SIZE + j] = board[i * SIZE + j];
        }
    //��l�� count, tag, Found�ܼ�
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            count[i * SIZE + j] = 0;
        }
    for (i = 0; i < SIZE * SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            tag[i][j] = 0;
        }
    Found = 0;
    setAns(A);
    sol();
}

void SolveSudoku::sol()
{
    int check, Max, iMax;
    /* �@��Ѫk
    Found: �p��w���Ʀr���Ӽ�
    count, tag: ���y���B��ƤS�E�c���X�Ů�̱ư����Ʀr
    */
    for (i = 0; i < SIZE * SIZE; i++)
    {
        if (in_board[i])
        {
            Found++;
        }
        else
        {
            for (j = 0; j < SIZE; j++)
            {
                if (in_board[(i / SIZE) * SIZE + j] && !tag[i][in_board[(i / SIZE) * SIZE + j] - 1])
                {
                    count[i]++;
                    tag[i][in_board[(i / SIZE) * SIZE + j] - 1] = true;
                }
                if (in_board[j * SIZE + i % SIZE] && !tag[i][in_board[j * SIZE + i % SIZE] - 1])
                {
                    count[i]++;
                    tag[i][in_board[j * SIZE + i % SIZE] - 1] = true;
                }
                check = in_board[((i / (SIZE * 3)) * 3 + j / 3) * SIZE + ((i % SIZE) / 3) * 3 + j % 3] - 1;
                if (in_board[((i / (SIZE * 3)) * 3 + j / 3) * SIZE + ((i % SIZE) / 3) * 3 + j % 3] && !tag[i][check])
                {
                    count[i]++;
                    tag[i][check] = true;

                }
            }
        }
    }
    /* �N�ư��Ʀr��8�Ӫ��Ů��J���T���Ʀr&�W�[Found�Ӽ�
    �ç�s�䪽�B��ơB�E�c�椺���Ů檺count, tag
    */
    for (i = 0; i < SIZE * SIZE; i++)
    {
        if (!in_board[i] && count[i] == 8)
        {
            count[i] = 0;
            Found++;
            for (j = 0; j < SIZE; j++)
            {
                if (!tag[i][j])
                {
                    in_board[i] = j + 1;
                    for (k = 0; k < SIZE; k++)
                    {
                        if (!in_board[(i / SIZE) * SIZE + k] && !tag[(i / SIZE) * SIZE + k][j])
                        {
                            count[(i / SIZE) * SIZE + k]++;
                            tag[(i / SIZE) * SIZE + k][j] = true;
                        }
                        if (!in_board[k * SIZE + i % SIZE] && !tag[k * SIZE + i % SIZE][j])
                        {
                            count[k * SIZE + i % SIZE]++;
                            tag[k * SIZE + i % SIZE][j] = true;
                        }
                        check = ((i / (SIZE * 3)) * 3 + k / 3) * SIZE + ((i % SIZE) / 3) * 3 + k % 3;
                        if (!in_board[check] && !tag[check][j])
                        {
                            count[check]++;
                            tag[check][j] = true;
                        }

                    }
                }
            }
            i = -1; //�s��J�Ů�Ʀr�N���s�}�l�j��
        }

    }
    if (Found == 81) //�����Ů�Ʀr�����
    {
        setAns(Ans + 1); //�ƿW�ѭӼƥ[1
    }
    else //�@��Ѫk����A�u�n�μɤO�ѤFXD
    {
        //��X�ư��Ʀr�̦h���Ů�
        Max = 0;
        iMax = -1;
        for (i = 0; i < SIZE * SIZE; i++)
        {
            if (count[i] > Max)
            {
                Max = count[i];
                iMax = i;
            }
        }
        //�ɤO�Ѷ}�l!!
        //�q�ư��Ʀr�̦h���Ů�}�l�q���סA��C�Ӧ��i�઺�Ѫk���]�@��
        for (j = 0; j < SIZE; j++)
        {
            if (!tag[iMax][j])
            {
                in_board[iMax] = j + 1;
                /*
                �إߤ@�ӷs�����D����A�ç�ثe�ƿW�ѭӼƥN�J
                �Y���s���ѡA�N�|��s�ƿW��(Ans)���ӼơAin_board�h�����
                �Y�D�ئ��h����(Ans>1)�Ain_board�u�|�����U�̫�@�ժ��ƿW��
                */
                SolveSudoku* tmp = new SolveSudoku(get_board(), getAns());
                //�R��������A�ö}�l�U�@�ӥi���(�`�ٰO���骺�ζq)
                delete tmp;
            }
        }
    }
}

vector < int > SolveSudoku::get_board() //���o�ƿW�ѵ�
{
    vector <int> out_board(SIZE * SIZE);
    for (i = 0; i < SIZE * SIZE; i++)
    {
        out_board[i] = in_board[i];
    }
    return out_board;
}

int SolveSudoku::getAns() //���o�ƿW�ѵ����Ӽ�
{
    return Ans;
}

void SolveSudoku::setAns(int A)//�]�w�ƿW�ѵ����Ӽ�
{
    Ans = A;
}