#include "SudokuGen.h"
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

SudokuGen::SudokuGen() // �غc�l(Constructor)
{
    srand(time(NULL)); //�H�����l�Ʈɶ��]�w���üƺؤl
    generator(); //�H�üƤ�k���ͼƿW�ѽL
}

void SudokuGen::generator() //�üƪk���ͷs�ѽL
{
    int tmp; //�m���μȦs�ܼ�
    int numtmp[9] = { 1,2,3,4,5,6,7,8,9 }; //9�c�椺���Ʀr
    vector <int> board(81); //�ѽL
    bool check = false; //��ܴѽL�O�_���\����

    for (i = 0; i < 81; i++) { board[i] = 0; } //��l�ƴѽL(��J0)

    for (i = 0; i < 9; i++) //����J���W��9�c��
//    1 2 3
//    4 5 6
//    7 8 9
    {
        board[i / 3 * 9 + i % 3] = numtmp[i];
    }

    while (!check) //���_���ժ���ŦX�W�h���ѽL����
    {
        //        ��J�Ʀr�禡�A���ե��ѶW�L1000���|�^��false��
        check = board_put(board);
    }

    for (i = 0; i < 9; i++) //�N1-9���Ʀr���ǥ���
    {
        j = rand() % 9;
        tmp = numtmp[i];
        numtmp[i] = numtmp[j];
        numtmp[j] = tmp;
    }

    for (i = 0; i < 81; i++) //�N�ѽL���Ʀr�Ǹm�����s���ͪ��Ʀr��
    {
        board[i] = numtmp[board[i] - 1];
    }

    for (i = 0; i < SIZE; i++) //�N���G�g�Jnew_board�ܼ�
        for (j = 0; j < SIZE; j++)
        {
            new_board[i][j] = board[i * SIZE + j];
        }

}

vector <int > SudokuGen::get_board() //��X�ѽL��vector�ܼ�
{
    vector < int > out_board(SIZE * SIZE);
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            out_board[i * SIZE + j] = new_board[i][j];
        }
    return out_board;
}

bool SudokuGen::check_rep(vector<int> board, int pos, int n)
{
    int i;
    for (i = 0; i < 9; i++)
    {
        if (board[pos / 9 * 9 + i] == n) //check��ƤW�Ʀr�O�_������
        {
            return true; //�����ơA�^��true
        }
        if (board[i * 9 + pos % 9] == n) //check���ƤW�Ʀr�O�_������
        {
            return true; //�����ơA�^��true
        }
    }
    return false;  //�L���ơA�^��false
}

bool SudokuGen::board_put(vector<int >& board) //��J�Ʀr�禡
{
    int pos;
    int count1, count2; //�p�ƾ�
    bool check = true; //check�Ʀr�O�_����

    for (j = 0; j < 9; j++) //��J���Ʀr1-9 (j+1�����G)
    {
        count2 = 0; //�p���@�Ʀr��J�`�@?�տ��~����
        for (i = 1; i < 9; i++) //�̧ǱN�Ʀr��J��l�K�Ӥp�E�c��(���W���w�g����)
        {
            pos = i / 3 * 27 + i % 3 * 3; //�C�Ӥp�E�c�檺�_�lindex
            count1 = 0; //�p���@�Ʀr��J?�տ��~����
            while (check == true)
            {
                k = rand() % 9;
                check = check_rep(board, pos + k / 3 * 9 + k % 3, j + 1);
                ++count1;
                ++count2;
                if (board[pos + k / 3 * 9 + k % 3] == 0 && check == false) //�Ʀr�S�����ơA���\��J����while loop
                {
                    board[pos + k / 3 * 9 + k % 3] = j + 1;
                    check = true;
                    break;
                }
                else
                {
                    check = true;
                }
                if (count1 > 100) // ���~�W�L100���A�Ʀr����
                {
                    for (l = 0; l < 81; l++)
                    {
                        if (board[l] == j + 1)
                        {
                            board[l] = 0;
                        }
                    }
                    board[j / 3 * 9 + j % 3] = j + 1;
                    i = 0;
                    break;
                }
                if (count2 > 1000) // ���~�W�L1000���A�^��false�õ����禡
                {
                    return false;
                }
            }
        }
    }
    return true; //���\�񺡴ѽL�A�^��true
}