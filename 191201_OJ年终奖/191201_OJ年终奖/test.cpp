#include <vector>
using namespace std;
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		vector<vector<int>> weightBoard(board.size(), vector<int>(board[0].size()));
		for (size_t i = 0; i < board.size(); i++)
		{
			for (size_t j = 0; j < board[0].size(); j++) 
			{
				if (i == 0 && j == 0)
				{
					weightBoard[i][j] += board[i][j];
				}
				// �����б߽�, ֻ��������
				else if (i == 0)
				{
					weightBoard[i][j] = weightBoard[i][j - 1] + board[i][j];
				}
				// �����б߽�, ֻ��������
				else if (j == 0)
				{
					weightBoard[i][j] = weightBoard[i - 1][j] + board[i][j];
				}
				// �����»�������, ��Ҫ�ж�������ʹȨ�����
				else
				{
					weightBoard[i][j] = max(weightBoard[i][j - 1], weightBoard[i - 1][j]) + board[i][j];
				}
			}
		}

		return weightBoard[board.size() - 1][board[0].size() - 1];
	}
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{


	return 0;
}