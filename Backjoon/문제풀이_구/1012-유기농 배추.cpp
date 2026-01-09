#include <iostream>
#include <cstring>
using namespace std;

/*
T : 테스트 케이스 수
M : 배추밭의 가로길이
N : 세로길이
K : 배추가 심어져 있는 위치의 개수
*/
int T, M, N, K;
int arr[50][50];
bool visit[50][50];

// 상하좌우
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

// 밭 안에 위치하는지 체크
bool SafeCheck(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < M)
		return true;
	return false;
}

void dfs(int x, int y)
{
	visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (SafeCheck(next_x, next_y))
			if (!visit[next_x][next_y] && arr[next_x][next_y] == 1)
				dfs(next_x, next_y);
	}
}

int main()
{
	cin >> T;

	// 테스트 케이스 수 만큼 반복
	for (int i = 0; i < T; i++)
	{
		// 초기화
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));

		// 가로, 세로, 배추 수
		cin >> M >> N >> K;

		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> y >> x;
			arr[x][y] = 1;
		}

		int count = 0;
		for (int x = 0; x < N; x++)
			for (int y = 0; y < M; y++)
				if (!visit[x][y] && arr[x][y] == 1)
				{
					count++;
					dfs(x, y);
				}

		cout << count << endl;
	}

	return 0;
}

/*
dfs 를 사용하는 기본문제인듯 싶다.
배추가 심어져 있는 연결되어 있는 땅을 찾는 문제이다.

dfs는 사용하는 것이 많이 익숙해졌다. 앞으로 좀더 난이도 있거나 활용이 필요한 dfs 문제를 풀거나
부족한 DP부분 문제를 풀어야 겠다.
*/