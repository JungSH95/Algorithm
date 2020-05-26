#include <iostream>
#include <cstring>
using namespace std;

/*
T : �׽�Ʈ ���̽� ��
M : ���߹��� ���α���
N : ���α���
K : ���߰� �ɾ��� �ִ� ��ġ�� ����
*/
int T, M, N, K;
int arr[50][50];
bool visit[50][50];

// �����¿�
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

// �� �ȿ� ��ġ�ϴ��� üũ
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

	// �׽�Ʈ ���̽� �� ��ŭ �ݺ�
	for (int i = 0; i < T; i++)
	{
		// �ʱ�ȭ
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));

		// ����, ����, ���� ��
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
dfs �� ����ϴ� �⺻�����ε� �ʹ�.
���߰� �ɾ��� �ִ� ����Ǿ� �ִ� ���� ã�� �����̴�.

dfs�� ����ϴ� ���� ���� �ͼ�������. ������ ���� ���̵� �ְų� Ȱ���� �ʿ��� dfs ������ Ǯ�ų�
������ DP�κ� ������ Ǯ��� �ڴ�.
*/