/*
#include <iostream>
using namespace std;

int M, N;

int map[501][501];
bool visit[501][501];

int way_count = 0;

// ��, ��, ��, ��
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

// �ùٸ� ����
if (next_x > 0 && next_x <= M && next_y > 0 && next_y <= N)
// ���� ������ ���� �������� ���̰� ���ƾ���, �湮 ���������
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
// ���� : M, ���� : N
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
ù ��° �õ� : dfs �� ��� ��θ� Ž���Ͽ� ������ ��� �߽߰� ī��Ʈ ����.
-> �ð��ʰ� ����.
*/

#include <iostream>
using namespace std;

int M, N;

int map[501][501];
int dp[501][501];

// ��, ��, ��, ��
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

			// �ùٸ� ����
			if (next_x > 0 && next_x <= M && next_y > 0 && next_y <= N)
				// ���� ������ ���� �������� ���̰� ���ƾ���, �湮 ���������
				if (map[next_x][next_y] < map[x][y])
					dp[x][y] += dfs(next_x, next_y);
		}
	}

	return dp[x][y];
}

int main()
{
	// ���� : M, ���� : N
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
�ش� ������ ī�װ��� DP�� �ִ� ���� �������� DP�� ������״��� �ð� �ʰ��� �ذ� �ƴ�.

-1 �� �ʱ�ȭ�Ͽ� �湮 ���� ������ �����ϰ�, 0 �̻��� ���� �̹� �湮�� ���� �ȴ�.

������ġ���� ������ ����� ���� dp[][]�� ����ż� �ش� ��ġ�� �ٸ� ��ο��� ������
dfs�� �� ���Ƽ� ��θ� ã�� ���� �ƴ� �ٷ� dp[][] ���� ��ȯ�ϱ� ������ �ð� ������ �ȴ�.

ó������ dp�� ��� ������Ѿ� ���� ���� ������ �ʾҴµ� ���� ���ѳ��� ���� �����ϸ鼭��
�ű��ϴ�.
*/