#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> basket;

	for (int i = 0; i < moves.size(); i++)
	{
		int doll = 0;

		// ũ���� Ŀ���� ��ġ�ϴ� �������� ������
		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][moves[i] - 1] != 0)
			{
				doll = board[j][moves[i] - 1];
				board[j][moves[i] - 1] = 0;
				break;
			}
		}

		// ������ �����°�?
		if (doll != 0)
		{
			// ��������� �ְ�
			if (basket.empty() && doll != 0)
				basket.push(doll);
			// ���� ������ Ȯ��
			else
			{
				// �� ���� ���� �����̶��
				if (basket.top() == doll)
				{
					answer += 2;
					basket.pop();
				}
				else
					basket.push(doll);
			}
		}
	}

	return answer;
}

/*
������ ����Ͽ� �ذ��� �� �ִ� �����ѹ���.
top�� Ȯ���Ͽ� ������ �����ϰ� ���� ������ �̴°��� �ݺ�
*/