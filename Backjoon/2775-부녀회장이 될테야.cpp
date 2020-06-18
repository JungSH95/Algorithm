#include <iostream>
#include <cstring>
using namespace std;

int T;
int dp[15][15];
int main()
{
	cin >> T;

	int k, n;		// k�� nȣ
	for (int i = 0; i < T; i++)
	{
		memset(dp, 0, sizeof(dp));
		cin >> k >> n;

		// 0�� ����
		for (int i = 1; i <= n; i++)
			dp[0][i] = i;

		// ���� ���� �� �����ֱ�
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				for (int l = 1; l <= j; l++)
					dp[i][j] += dp[i - 1][l];

		cout << dp[k][n] << endl;
	}
	return 0;
}

/*
a��bȣ = (a-1)�� 1ȣ ~ bȣ�� �����

����Ʈ�� 0������ �ְ� 1ȣ���� �ִ�.

0�� 1-1, 2-2, 3-3, 4-4 : �� ȣ�� ��� ��
1�� 1-(0�� 1ȣ), 2-(0�� 1ȣ+2ȣ) 3-(0�� 1ȣ+2ȣ+3ȣ)
2�� 1-(1�� 1ȣ), 2-(1�� 1ȣ+2ȣ)

dp�� ����ϸ� �� �� ����.

�ѹ��� ���~
*/