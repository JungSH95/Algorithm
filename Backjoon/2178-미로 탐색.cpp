#include <iostream>
#include <queue>
#include <string>
using namespace std;

int Map[101][101];
int DP[101][101];

bool visit[101][101];

int N, M;	// 세로 가로

// 상하좌우
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int min_dist = 999;

void Map_Search(int x, int y, int depth)
{
	if (x == N && y == M)
	{
		if (min_dist >= depth)
			min_dist = depth;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		// 올바른 미로일 경우
		if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M)
		{
			// 방문을 안했다면
			if (!visit[next_x][next_y] && Map[next_x][next_y] == 1)
			{
				visit[next_x][next_y] = true;
				Map_Search(next_x, next_y, depth + 1);
				visit[next_x][next_y] = false;
			}
		}
	}
}

void Map_Search2()
{
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 올바른 미로일 경우
			if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M)
			{
				// 벽이 아닐 경우
				if (Map[next_x][next_y] == 1)
				{
					q.push(make_pair(next_x, next_y));
					Map[next_x][next_y] = Map[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string num;
		cin >> num;

		for (int j = 1; j <= M; j++)
		{
			Map[i][j] = (int)(num[j - 1] - '0');
			DP[i][j] = -1;
		}
	}
	Map_Search2();
	cout << Map[N][M];
	return 0;
}


/*
최단 경로로 가기위해서는 이미 갔던 길을 또 간다면 최단경로보다 길어진다.

1차 문제 숫자가 붙어있기때문에 가로가 길어지면 일반 정수형에 담을 수가 없다.
string으로 입력받은 후 넣어주는 것으로 변경

DFS로 풀 경우
모든 배열이 1로 초기화되어있을때 엄청난 양의 재귀호출을 하므로 시간초과 발생함

DFS보다 시간이 절약되는 BFS로 사용하기로 변경
*/