#define SIZE 9
#include <vector>
using namespace std;

class SudokuGen
{
public:
    SudokuGen();
    void generator(); //�üƪk���ͷs�ѽL (��l�Ʈɫغc�l�N�|�I�s�@��)
    vector<int > get_board(); //��X�ѽL��vector�ܼ�
    bool check_rep(vector<int>, int, int); //������J�Ʀr�O�_���ơB�ŦX�W�h�A���ŦX�|�^��false��
    bool board_put(vector<int>&); //��J�Ʀr�禡�A���ե��ѶW�L1000���|�^��false��
private:
    int new_board[SIZE][SIZE]; //�ѽL
    int i, j, k, l; //�j����ܼ�
};