#include <iostream>
#include <vector>
#include "SudokuGen.h"
#include "DigSudoku.h"
#include "SolveSudoku.h"

using namespace std;

void print_board(vector <int >);

int main()
{

    int Ans = 0; // �ƿW�Ѫ��Ӽ�
    vector <int > digboard;
    SudokuGen NewBoard; // ���ʹѽL����
    vector <int > board = NewBoard.get_board(); //���o�ѽL
    
	cout << "�Q�n�ۤv���п�J 1 :" << endl;
	cout << "�Q�n�q�����A���D�п�J 0 :" << endl;
	cout << "�A����ܬO?";
	int playerchose;
	cin >> playerchose;
	if (playerchose == 1)
	{
		cout << "�n �ǳƶ}�l�C��OwO!" << endl;
	}
	else if (playerchose == 0)
	{
		cout << "�q�������|���A���D��OuO!" << endl;
	}
	else if (playerchose != 1 && playerchose != 0)
	{
		cout << "��J 1 �� 0 ��!!" << endl;
		cout << "�A����ܬO?";
		cin >> playerchose;

		if (playerchose == 1)
		{
			cout << "�n �ǳƶ}�l�C��OwO!" << endl;
		}
		else if (playerchose == 0)
		{
			cout << "�q�������|���A���D��OuO!" << endl;
		}
		else if (playerchose != 1 && playerchose != 0)
		{
			cout << "��J 1 �� 0 ��!!!!!!!!!!!!!!!!!ť�����f?" << endl;
			cout << "�A����ܬO?";
			cin >> playerchose;

			if (playerchose == 1)
			{
				cout << "�n �ǳƶ}�l�C��OwO!" << endl;
			}
			else if (playerchose == 0)
			{
				cout << "�q�������|���A���D��OuO!" << endl;
			}
			else if (playerchose != 1 && playerchose != 0) {
				cout << "�n�a�ݨӧA���Q��QAQ �T�T" << endl;
				return 0;
			}
		}
	}
	int hole;
	cout << "�п�J�Q�n���X�Ӭ}(�̤�10��,�̦h40��):";
	cin >> hole;
	if (hole >= 40 || hole <= 10)
	{
		cout <<endl<< "�п�J10~40:";
		cin >> hole ;
		if (hole >= 40 || hole <= 10)
		{
			cout << endl << "�п�J10~40!!!!!!!!!!!!!!ť�����f?:";
			cin >> hole;
			if (hole >= 40 || hole <= 10)
			{
				cout << endl << "�n�a�ݨӧA���Q��QAQ �T�T";
				return 0;
			}

		}

	}

	cout << endl<<"���X���}�O" << hole << "�ӡA�U���O�o�����D��" << endl<<endl;

    while (Ans != 1) // �ˬd�D�جO�_���ߤ@�ѡA�B�ѵ��P�D�ؤ@�P
    {
        DigSudoku Board_Dig(board, hole); // ���}�X�D
        digboard = Board_Dig.get_board(); // ���o���}�᪺�ѽL
        SolveSudoku Board_Solve(digboard, 0); // ���D
        Ans = Board_Solve.getAns(); // ���o�D���`�@���h�֭Ӹ�
        if (Ans == 1 && board != Board_Solve.get_board())
        {
            Ans = 0;
        }
    }
   print_board(digboard); // �L�X�D��
   if (playerchose == 0) {
	   cout << "�q���ѥX�����׬O:" << endl;
	   print_board(board); // �N�ѽL�L�X
	   cout << "�O���O�ܧ֩OAwA?" << endl;
	   return 0;
   }

   cout  << "���W��(1,1)  �k�W��(9,1)  ���U�O(1,9)  �k�U�O(9,9) �̦�����"<<endl;
   cout << "�п�J�Q�n��J����m�� �A��J�Q�n��J���Ʀr�A��: 6 7 8 �N�O(6,7)���a���J{8}" << endl;
   int x, y,pa;
   cin >> x >> y>>pa;
   
   cout <<"�������|�����u�A�ХI�O�����h���e"<< endl;




    return 0;
}

void print_board(vector <int > board) //�N�ѽL�L�X
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



	

	

