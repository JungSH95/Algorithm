#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int arr_size;			// ü���� ũ��
int arr[300][300];		// ü����
bool visit[300][300];

// ����Ʈ �ִ� ��ġ, ����Ʈ ���� ��ġ
int start_x, start_y, end_x, end_y;

// ����Ʈ�� ������ �� �ִ� ��ġ
int move_knight_dx[] = { -2, -2, -1, 1, -1, 1, 2, 2 };
int move_knight_dy[] = { -1, 1, -2, -2, 2, 2, -1, 1 };

// �� �ȿ� �ִ� ������ Ȯ��
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

	// �� ���� �������� �� (�ʺ� Ž�� ����)
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		// ����
		if (x == end_x && y == end_y)
			return arr[x][y];

		// ����Ʈ�� ������ �� �ִ� �����
		for (int i = 0; i < 8; i++)
		{
			int next_x = x + move_knight_dx[i];
			int next_y = y + move_knight_dy[i];

			// �� �ȿ� �ִ��� üũ
			if (SafeRoute(next_x, next_y))
			{
				// �湮�� ���ߴٸ�
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
		// �ʱ�ȭ
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));

		// ü���� ũ��
		cin >> arr_size;

		// ������ ������
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;

		int answer = bfs();
		cout << answer << endl;
	}

	return 0;
}

/*
���� dfs ������ Ǯ�ٰ� bfs ������ Ǯ� �� �򰥷ȴ��� ����.

�ʺ� �켱 Ž������ �̵��ϸ� �湮�Ѱ��� �ٽ� �湮 ���ϵ��� visit�� ����Ͽ� üũ�ϰ�
���� ��δ� ���� ����� �� + 1 �� �ϸ� �̵��� �ߴ�.
*/