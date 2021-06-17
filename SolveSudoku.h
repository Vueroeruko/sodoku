#define SIZE 9
#include <vector>
using namespace std;

class SolveSudoku
{
public:
    static int Ans; //计縒秆计璸计竟 (硂琌Global跑计)
    SolveSudoku(vector<int>, int); //篶
    void sol(); //秆肈ㄧΑ
    vector < int > get_board(); //眔计縒秆
    int getAns(); //眔计縒秆计

private:
    int i, j, k; //癹伴ノ跑计
    int in_board[SIZE * SIZE]; //计縒肈ヘ
    int count[SIZE * SIZE]; //–逼埃计计
    int Found; //计计
    bool tag[SIZE * SIZE][SIZE]; //–逼埃计
    void setAns(int A); //砞﹚Ans跑计
};