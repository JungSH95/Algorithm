#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

int map[8][8];
int copy_map[8][8];

int maxZero = 0;
int N, M;

// 상, 하, 좌, 우
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void BFS()
{
	int initwallMap[8][8];
	memcpy(initwallMap, copy_map, sizeof(copy_map));

	// 바이러스 위치 저장
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (initwallMap[i][j] == 2)
				q.push(make_pair(i, j));

	// 바이러스 확산 시작
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 4방향 확산 
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			// 올바른 범위 체크
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
				// 빈 공간 (확산 가능)
				if (initwallMap[nextX][nextY] == 0)
				{
					initwallMap[nextX][nextY] = 2;
					q.push(make_pair(nextX, nextY));
				}
		}
	}

	// 안전구역 개수 체크
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (initwallMap[i][j] == 0)
				count++;

	if (count >= maxZero)
		maxZero = count;
}

void InitialWall(int count)
{
	if (count == 3)
	{
		BFS();
		return;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			// 빈칸일 경우 벽만들기 재귀
			if (copy_map[i][j] == 0)
			{
				copy_map[i][j] = 1;
				InitialWall(count + 1);
				// 해당 경우의 수로 가능한 것을 했으므로 초기화
				copy_map[i][j] = 0;
			}
		}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	// 0 찾기 시작
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			// 빈칸일 경우 원본 유지를 위해 복사본 이용
			if (map[i][j] == 0)
			{
				memcpy(copy_map, map, sizeof(map));

				// 벽 하나 만들면서 시작
				copy_map[i][j] = 1;
				InitialWall(1);
				// 해당 경우의 수로 가능한 것을 했으므로 초기화
				copy_map[i][j] = 0;
			}
		}

	cout << maxZero;

	return 0;
}


/*

저번에 풀었던 7576번 토마토 문제와 비슷해서 간단하게 풀 수 있었다.
시간 초과를 걱정하였는데 괜한 걱정이었던것 같다.

*/