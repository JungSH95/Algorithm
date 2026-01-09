#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0, weight[101][101] = { 0, };

	// 집
	weight[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1)
				continue;

			bool check = false;

			// 침수 지역 체크
			for (int k = 0; k < puddles.size(); k++)
				if (i == puddles[k].at(1) && j == puddles[k].at(0))
				{
					weight[i][j] = 0;
					check = true;
					break;
				}

			// 침수지역 아니면 위와 왼쪽의 가중치 더하기
			if (!check)
				weight[i][j] = (weight[i - 1][j] + weight[i][j - 1]) % 1000000007;
		}
	}

	answer = weight[n][m];
	return answer;
}

/*
처음 풀었던 방법인 DFS를 사용했을경우 효율성에서 전부 실패했다.
결국 문제 카테고리대로 동적계획법을 사용하여 다시 코드 짰다.
근데 동적계획법을 했는데도 불구하고 효율성 테스트 몇개 실패.

왜일까 계속 보다가 설마하고 침수 지역 체크하는 부분을 수정한 결과 통과했다....
이런 사소한 것도 앞으로 더 생각해봐야겠다.

// 실패했을 때의 원인 코드 ----------------------------
for (int k = 0; k < puddles.size(); k++)
{
	vector<int> temp = puddles[k];
	if (i == temp.at(1) && j == temp.at(0))
	{
		weight[i][j] = 0;
	check = true;
	break;
	}
}
// --------------------------------------------------


*/