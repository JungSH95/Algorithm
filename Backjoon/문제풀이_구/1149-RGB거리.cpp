#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000][3];
int rgb_dp[1001][3];			// 색상 어떤것 사용?

int main()
{
	cin >> N;

	// 각 칠하는 비용 입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++)
	{
		rgb_dp[i + 1][0] = min(rgb_dp[i][1], rgb_dp[i][2]) + arr[i][0];
		rgb_dp[i + 1][1] = min(rgb_dp[i][0], rgb_dp[i][2]) + arr[i][1];
		rgb_dp[i + 1][2] = min(rgb_dp[i][0], rgb_dp[i][1]) + arr[i][2];
	}

	cout << min(min(rgb_dp[N][0], rgb_dp[N][1]), rgb_dp[N][2]);

	return 0;
}

/*
집의 색을 색칠할때 최소의 비용으로 선택할 때 의 총 비용을 출력하는 문제이다

점화식을 만들어서 dp를 사용해 풀었다.

2번 집이 빨강을 선택할 경우에 1번집은 초록이나 파랑을 선택할 수 있고,
2번 집이 초록을 선택할 경우에 1번집은 빨강이나 파랑을 선택할 수 있고,
2번 집이 파랑을 선택할 경우에 1번집은 빨강이나 초록을 선택할 수 있다

이 방법으로 선택할 수 있는 경우 2가지중에 작은 값을 저장하며 집들을 색칠 했다.

RGB거리 문제는 기존에 DP를 풀었던 것이 도움이 많이됐다.
기본적인 dp를 사용하는 문제이기 때문에 큰 어려움 없이 풀었다.
*/