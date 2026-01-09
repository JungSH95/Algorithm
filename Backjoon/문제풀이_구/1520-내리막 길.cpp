/*
#include <iostream>
using namespace std;

int M, N;

int map[501][501];
bool visit[501][501];

int way_count = 0;

// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y)
{
if (x == M && y == N)
{
way_count++;
return;
}

for (int i = 0; i < 4; i++)
{
int next_x = x + dx[i];
int next_y = y + dy[i];

// 올바른 범위
if (next_x > 0 && next_x <= M && next_y > 0 && next_y <= N)
// 다음 지역이 현재 지점보다 높이가 낮아야함, 방문 안했을경우
if (map[next_x][next_y] < map[x][y] && !visit[next_x][next_y])
{
visit[next_x][next_y] = true;
dfs(next_x, next_y);
visit[next_x][next_y] = false;
}
}
}

int main()
{
// 세로 : M, 가로 : N
cin >> M >> N;

for (int i = 1; i <= M; i++)
for (int j = 1; j <= N; j++)
cin >> map[i][j];

visit[1][1] = true;
dfs(1, 1);

cout << way_count;
return 0;
}
*/

/*
첫 번째 시도 : dfs 로 모든 경로를 탐색하여 가능한 경로 발견시 카운트 증가.
-> 시간초과 실패.
*/

#include <iostream>
using namespace std;

int M, N;

int map[501][501];
int dp[501][501];

// 상, 하, 좌, 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y)
{
	if (x == M && y == N)
		return 1;

	if (dp[x][y] == -1)
	{
		dp[x][y] = 0;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// 올바른 범위
			if (next_x > 0 && next_x <= M && next_y > 0 && next_y <= N)
				// 다음 지역이 현재 지점보다 높이가 낮아야함, 방문 안했을경우
				if (map[next_x][next_y] < map[x][y])
					dp[x][y] += dfs(next_x, next_y);
		}
	}

	return dp[x][y];
}

int main()
{
	// 세로 : M, 가로 : N
	cin >> M >> N;

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	int answer = dfs(1, 1);
	cout << answer;
	return 0;
}

/*
해당 문제의 카테고리가 DP에 있던 것이 생각나서 DP를 적용시켰더니 시간 초과가 해결 됐다.

-1 로 초기화하여 방문 안한 곳으로 설정하고, 0 이상의 경우는 이미 방문한 곳이 된다.

현재위치에서 가능한 경우의 수가 dp[][]에 저장돼서 해당 위치로 다른 경로에서 왔을때
dfs를 더 돌아서 경로를 찾는 것이 아닌 바로 dp[][] 값을 반환하기 때문에 시간 단축이 된다.

처음에는 dp를 어떻게 적용시켜야 할지 감이 잡히지 않았는데 적용 시켜놓고 보니 간단하면서도
신기하다.
*/