#include <iostream>
#include <cstring>
using namespace std;

int T;
int dp[15][15];
int main()
{
	cin >> T;

	int k, n;		// k층 n호
	for (int i = 0; i < T; i++)
	{
		memset(dp, 0, sizeof(dp));
		cin >> k >> n;

		// 0층 셋팅
		for (int i = 1; i <= n; i++)
			dp[0][i] = i;

		// 이전 층수 값 더해주기
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				for (int l = 1; l <= j; l++)
					dp[i][j] += dp[i - 1][l];

		cout << dp[k][n] << endl;
	}
	return 0;
}

/*
a층b호 = (a-1)층 1호 ~ b호의 사람들

아파트는 0층부터 있고 1호부터 있다.

0층 1-1, 2-2, 3-3, 4-4 : 각 호에 사람 수
1층 1-(0층 1호), 2-(0층 1호+2호) 3-(0층 1호+2호+3호)
2층 1-(1층 1호), 2-(1층 1호+2호)

dp를 사용하면 될 것 같다.

한번에 통과~
*/