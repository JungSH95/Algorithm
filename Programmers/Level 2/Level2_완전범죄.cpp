#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int re = INT_MAX;

int dfs(int index, vector<vector<int>>& info, int n, int m, int a_count, int b_count)
{
	int result = INT_MAX;

	if (a_count >= n || b_count >= m) {
		return INT_MAX; // 잡힘
	}
	if (index == info.size()) {
		re = min(a_count, re);
		return min(a_count, re); // 모든 물건을 훔침
	}

	if(a_count >= re)
		return INT_MAX;

	if (a_count + info[index][0] < n)
		dfs(index + 1, info, n, m, a_count + info[index][0], b_count);

	if (b_count + info[index][1] < m)
		dfs(index + 1, info, n, m, a_count, b_count + info[index][1]);
}

int solution(vector<vector<int>> info, int n, int m) {
    int answer = -1;
	/*
	int result = dfs(0, info, n, m, 0, 0);
	cout << "result: " << re << endl;
	answer = (re == INT_MAX) ? -1 : re;
	*/

	vector<vector<int>> dp(info.size(), vector<int>(m));
	for (int i = 0; i < info.size(); i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0)
			{
				if (info[i][1] <= j)
					dp[i][j] = 0;
				else
					dp[i][j] = info[i][0];
			}
			else if (j - info[i][1] < 0)
				dp[i][j] = dp[i - 1][j] + info[i][0];
			else
				dp[i][j] = min(dp[i - 1][j] + info[i][0], dp[i - 1][j - info[i][1]]);
		}
	}

	if (dp[info.size() - 1][m - 1] < n)
		answer = dp[info.size() - 1][m - 1];
	else
		answer = -1;
    return answer;
}



// 1차 시도 : DFS로 먼저 시도해보았는데 예상대로 시간초과 발생
// 2차 시도 : 우선순위큐를 사용하여 풀어보려 했으나 예외되는 경우가 발생할 경우가 있을거라 추측하고 포기

// 3차 시도 : 결국 다른 사람의 풀이를 참고했는데 DP를 사용함, Level2라고 하기엔 많이 어려움
// dp[i][b] = i번 아이템까지 고려하고 B의 흔적의 최대가 b일 때 A의 흔적의 합의 최솟값
// dp[i][b] = min(dp[i - 1][b] + 이번 아이템의 A의 값, dp[i - 1][b - 현재 B의 흔적])
// 1. 이번 아이템을 A가 가져가는 경우 : dp[i - 1][b] + 이번 아이템의 A의 값
// 2. 이번 아이템 B가 가져가는 경우 : dp[i - 1][b - 현재 B의 흔적]

// dp 숙련도가 부족하여 다시 숙지 및 dp 문제 풀어봐야할듯