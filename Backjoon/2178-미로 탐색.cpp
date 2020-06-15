#include <iostream>
#include <queue>
#include <string>
using namespace std;

int Map[101][101];
int DP[101][101];

bool visit[101][101];

int N, M;	// ���� ����

// �����¿�
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

		// �ùٸ� �̷��� ���
		if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M)
		{
			// �湮�� ���ߴٸ�
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

			// �ùٸ� �̷��� ���
			if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M)
			{
				// ���� �ƴ� ���
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
�ִ� ��η� �������ؼ��� �̹� ���� ���� �� ���ٸ� �ִܰ�κ��� �������.

1�� ���� ���ڰ� �پ��ֱ⶧���� ���ΰ� ������� �Ϲ� �������� ���� ���� ����.
string���� �Է¹��� �� �־��ִ� ������ ����

DFS�� Ǯ ���
��� �迭�� 1�� �ʱ�ȭ�Ǿ������� ��û�� ���� ���ȣ���� �ϹǷ� �ð��ʰ� �߻���

DFS���� �ð��� ����Ǵ� BFS�� ����ϱ�� ����
*/