#include "SolveSudoku.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int SolveSudoku::Ans = 0; //數獨解個數計數器 (Global變數)
SolveSudoku::SolveSudoku(vector<int> board, int A)
{
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            in_board[i * SIZE + j] = board[i * SIZE + j];
        }
    //初始化 count, tag, Found變數
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
    /* 一般解法
    Found: 計算已知數字的個數
    count, tag: 掃描直、橫排又九宮格找出空格裡排除的數字
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
    /* 將排除數字有8個的空格填入正確的數字&增加Found個數
    並更新其直、橫排、九宮格內之空格的count, tag
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
            i = -1; //新填入空格數字就重新開始迴圈
        }

    }
    if (Found == 81) //全部空格數字都找到
    {
        setAns(Ans + 1); //數獨解個數加1
    }
    else //一般解法不行，只好用暴力解了XD
    {
        //找出排除數字最多的空格
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
        //暴力解開始!!
        //從排除數字最多的空格開始猜答案，把每個有可能的解法都跑一次
        for (j = 0; j < SIZE; j++)
        {
            if (!tag[iMax][j])
            {
                in_board[iMax] = j + 1;
                /*
                建立一個新的解題物件，並把目前數獨解個數代入
                若有新的解，將會更新數獨解(Ans)的個數，in_board則為其解
                若題目有多重解(Ans>1)，in_board只會紀錄下最後一組的數獨解
                */
                SolveSudoku* tmp = new SolveSudoku(get_board(), getAns());
                //刪除此物件，並開始下一個可能解(節省記憶體的用量)
                delete tmp;
            }
        }
    }
}

vector < int > SolveSudoku::get_board() //取得數獨解答
{
    vector <int> out_board(SIZE * SIZE);
    for (i = 0; i < SIZE * SIZE; i++)
    {
        out_board[i] = in_board[i];
    }
    return out_board;
}

int SolveSudoku::getAns() //取得數獨解答的個數
{
    return Ans;
}

void SolveSudoku::setAns(int A)//設定數獨解答的個數
{
    Ans = A;
}