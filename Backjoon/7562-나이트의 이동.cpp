#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int arr_size;			// 체스판 크기
int arr[300][300];		// 체스판
bool visit[300][300];

// 나이트 있는 위치, 나이트 목적 위치
int start_x, start_y, end_x, end_y;

// 나이트가 움직일 수 있는 위치
int move_knight_dx[] = { -2, -2, -1, 1, -1, 1, 2, 2 };
int move_knight_dy[] = { -1, 1, -2, -2, 2, 2, -1, 1 };

// 판 안에 있는 곳인지 확인
bool SafeRoute(int x, int y)
{
	if (x >= 0 && x < arr_size && y >= 0 && y < arr_size)
		return true;
	return false;
}

int bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));

	visit[start_x][start_y] = true;

	// 갈 곳이 없어지면 끝 (너비 탐색 시작)
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		// 도착
		if (x == end_x && y == end_y)
			return arr[x][y];

		// 나이트가 움직일 수 있는 방향들
		for (int i = 0; i < 8; i++)
		{
			int next_x = x + move_knight_dx[i];
			int next_y = y + move_knight_dy[i];

			// 판 안에 있는지 체크
			if (SafeRoute(next_x, next_y))
			{
				// 방문을 안했다면
				if (!visit[next_x][next_y])
				{
					visit[next_x][next_y] = true;
					q.push(make_pair(next_x, next_y));
					arr[next_x][next_y] = arr[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		// 초기화
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));

		// 체스판 크기
		cin >> arr_size;

		// 시작점 도착점
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;

		int answer = bfs();
		cout << answer << endl;
	}

	return 0;
}

/*
매일 dfs 문제만 풀다가 bfs 문제를 풀어서 좀 헷갈렸던거 같다.

너비 우선 탐색으로 이동하며 방문한곳은 다시 방문 안하도록 visit을 사용하여 체크하고
다음 경로는 이전 경로의 값 + 1 을 하며 이동을 했다.
*/