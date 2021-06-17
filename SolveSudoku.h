#define SIZE 9
#include <vector>
using namespace std;

class SolveSudoku
{
public:
    static int Ans; //�ƿW�ѭӼƭp�ƾ� (�o�O��Global���ܼ�)
    SolveSudoku(vector<int>, int); //�غc�l
    void sol(); //���D�禡
    vector < int > get_board(); //���o�ƿW��
    int getAns(); //���o�ƿW�Ѫ��Ӽ�

private:
    int i, j, k; //�j����ܼ�
    int in_board[SIZE * SIZE]; //�ƿW�D��
    int count[SIZE * SIZE]; //�C�ӪŮ�ư��Ʀr�Ӽ�
    int Found; //�w���Ů�Ʀr���Ӽ�
    bool tag[SIZE * SIZE][SIZE]; //�C�ӪŮ�ư����Ʀr
    void setAns(int A); //�]�wAns�ܼ�
};