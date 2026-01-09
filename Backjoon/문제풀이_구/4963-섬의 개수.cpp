#include <iostream>
#include <cstring>
using namespace std;

// 너비, 높이
int W, H;
int map[50][50];
bool visit[50][50];

// 상하좌우, 대각선(왼쪽위 오른쪽위 왼쪽아래 오른쪽아래)
int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

void dfs(int x, int y)
{
	// 8가지 방향에 대하여 탐색
	for (int i = 0; i < 8; i++)
	{
		int next_dx = x + dx[i];
		int next_dy = y + dy[i];

		// 올바른 범위 인가
		if (next_dx >= 0 && next_dx < H && next_dy >= 0 && next_dy < W)
		{
			// 방문을 안했다면
			if (!visit[next_dx][next_dy] && map[next_dx][next_dy] == 1)
			{
				visit[next_dx][next_dy] = true;
				dfs(next_dx, next_dy);
			}
		}
	}
}

int main()
{
	while (true)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;

		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));

		// 섬 정보 입력
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];

		int count = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (!visit[i][j] && map[i][j] == 1)
				{
					count++;
					visit[i][j] = true;
					dfs(i, j);
				}
			}
		cout << count << endl;
	}
	return 0;
}

/*
map이 주어지고 그것에 대하여 조건에 맞는 개수를 찾는 것이다.
다만 다른 점은 가로,세로 뿐만 아니라 대각선도 체크하는 것
dfs를 사용하여 해결했다.

테스트 케이스의 수가 따로 정해지지 않고 0,0이 입력되면 종료
while문을 사용하여 무한 반복을 사용하고
각 맵과 방문 체크 배열은 초기화를 계속 시켜준다.
*/
