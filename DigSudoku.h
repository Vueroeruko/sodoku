#define SIZE 9
#include<vector>
using namespace std;

class DigSudoku
{
public:
    DigSudoku(vector < int >, int); //建構子
    void board_dig(int); //挖洞函式
    vector < int > get_board(); //輸出棋盤至vector變數
    void copy_board(); //複製棋盤函式
private:
    int i, j; //迴圈用變數
    int in_board[SIZE][SIZE]; //輸入棋盤
    int dig_board[SIZE][SIZE]; //輸出棋盤(挖完洞)
    int number_seres[SIZE * SIZE]; //數字序列
};