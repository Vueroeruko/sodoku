#include <iostream>
#include <vector>
#include "SudokuGen.h"
#include "DigSudoku.h"
#include "SolveSudoku.h"

using namespace std;

void print_board(vector <int >);

int main()
{

    int Ans = 0; // 數獨解的個數
    vector <int > digboard;
    SudokuGen NewBoard; // 產生棋盤物件
    vector <int > board = NewBoard.get_board(); //取得棋盤
    
	cout << "想要自己玩請輸入 1 :" << endl;
	cout << "想要電腦幫你解題請輸入 0 :" << endl;
	cout << "你的選擇是?";
	int playerchose;
	cin >> playerchose;
	if (playerchose == 1)
	{
		cout << "好 準備開始遊戲OwO!" << endl;
	}
	else if (playerchose == 0)
	{
		cout << "電腦等等會幫你解題唷OuO!" << endl;
	}
	else if (playerchose != 1 && playerchose != 0)
	{
		cout << "輸入 1 或 0 啦!!" << endl;
		cout << "你的選擇是?";
		cin >> playerchose;

		if (playerchose == 1)
		{
			cout << "好 準備開始遊戲OwO!" << endl;
		}
		else if (playerchose == 0)
		{
			cout << "電腦等等會幫你解題唷OuO!" << endl;
		}
		else if (playerchose != 1 && playerchose != 0)
		{
			cout << "輸入 1 或 0 啦!!!!!!!!!!!!!!!!!聽不懂逆?" << endl;
			cout << "你的選擇是?";
			cin >> playerchose;

			if (playerchose == 1)
			{
				cout << "好 準備開始遊戲OwO!" << endl;
			}
			else if (playerchose == 0)
			{
				cout << "電腦等等會幫你解題唷OuO!" << endl;
			}
			else if (playerchose != 1 && playerchose != 0) {
				cout << "好吧看來你不想玩QAQ 掰掰" << endl;
				return 0;
			}
		}
	}
	int hole;
	cout << "請輸入想要挖幾個洞(最少10個,最多40個):";
	cin >> hole;
	if (hole > 40 || hole < 10)
	{
		cout <<endl<< "請輸入10~40:";
		cin >> hole ;
		if (hole > 40 || hole < 10)
		{
			cout << endl << "請輸入10~40!!!!!!!!!!!!!!聽不懂逆?:";
			cin >> hole;
			if (hole > 40 || hole < 10)
			{
				cout << endl << "好吧看來你不想玩QAQ 掰掰";
				return 0;
			}

		}

	}

	cout << endl<<"挖出的洞是" << hole << "個，下面是這次的題目" << endl<<endl;

    while (Ans != 1) // 檢查題目是否有唯一解，且解答與題目一致
    {
        DigSudoku Board_Dig(board, hole); // 挖洞出題
        digboard = Board_Dig.get_board(); // 取得挖洞後的棋盤
        SolveSudoku Board_Solve(digboard, 0); // 解題
        Ans = Board_Solve.getAns(); // 取得題目總共有多少個解
        if (Ans == 1 && board != Board_Solve.get_board())
        {
            Ans = 0;
        }
    }
   print_board(digboard); // 印出題目

   if (playerchose == 0) {
	   cout << "電腦解出的答案是:" << endl;
	   print_board(board); 
	   cout << "是不是很快呢AwA?" << endl;
	   return 0;
   }

   cout  << "左上為(1,1)  右上為(9,1)  左下是(1,9)  右下是(9,9) 依此類推"<<endl;
   cout << "請輸入想要輸入的位置後 再輸入想要輸入的數字，例: 6 7 8 就是(6,7)的地方輸入{8}" << endl;
   int x, y,pa;
   cin >> x >> y>>pa;
   
   cout <<"此部分尚未完工，很抱歉"<< endl;




    return 0;
}

void print_board(vector <int > board) //將棋盤印出
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == 0) { cout << "{ }"; }
        else { cout << '{'<< board[i] << '}'; }
        if ((i + 1) % 9 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
