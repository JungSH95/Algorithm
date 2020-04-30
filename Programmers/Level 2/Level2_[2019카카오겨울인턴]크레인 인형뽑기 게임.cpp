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

		// 크래인 커서에 위치하는 인형으로 내리기
		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][moves[i] - 1] != 0)
			{
				doll = board[j][moves[i] - 1];
				board[j][moves[i] - 1] = 0;
				break;
			}
		}

		// 인형을 집었는가?
		if (doll != 0)
		{
			// 비어있으면 넣고
			if (basket.empty() && doll != 0)
				basket.push(doll);
			// 위에 있으면 확인
			else
			{
				// 맨 위가 같은 인형이라면
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
스택을 사용하여 해결할 수 있는 간단한문제.
top을 확인하여 같으면 삭제하고 다음 인형을 뽑는것을 반복
*/