#define SIZE 9
#include<vector>
using namespace std;

class DigSudoku
{
public:
    DigSudoku(vector < int >, int); //�غc�l
    void board_dig(int); //���}�禡
    vector < int > get_board(); //��X�ѽL��vector�ܼ�
    void copy_board(); //�ƻs�ѽL�禡
private:
    int i, j; //�j����ܼ�
    int in_board[SIZE][SIZE]; //��J�ѽL
    int dig_board[SIZE][SIZE]; //��X�ѽL(�����})
    int number_seres[SIZE * SIZE]; //�Ʀr�ǦC
};