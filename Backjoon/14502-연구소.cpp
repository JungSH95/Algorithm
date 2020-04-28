#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

int map[8][8];
int copy_map[8][8];

int maxZero = 0;
int N, M;

// ��, ��, ��, ��
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void BFS()
{
	int initwallMap[8][8];
	memcpy(initwallMap, copy_map, sizeof(copy_map));

	// ���̷��� ��ġ ����
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (initwallMap[i][j] == 2)
				q.push(make_pair(i, j));

	// ���̷��� Ȯ�� ����
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 4���� Ȯ�� 
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			// �ùٸ� ���� üũ
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
				// �� ���� (Ȯ�� ����)
				if (initwallMap[nextX][nextY] == 0)
				{
					initwallMap[nextX][nextY] = 2;
					q.push(make_pair(nextX, nextY));
				}
		}
	}

	// �������� ���� üũ
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
			// ��ĭ�� ��� ������� ���
			if (copy_map[i][j] == 0)
			{
				copy_map[i][j] = 1;
				InitialWall(count + 1);
				// �ش� ����� ���� ������ ���� �����Ƿ� �ʱ�ȭ
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

	// 0 ã�� ����
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			// ��ĭ�� ��� ���� ������ ���� ���纻 �̿�
			if (map[i][j] == 0)
			{
				memcpy(copy_map, map, sizeof(map));

				// �� �ϳ� ����鼭 ����
				copy_map[i][j] = 1;
				InitialWall(1);
				// �ش� ����� ���� ������ ���� �����Ƿ� �ʱ�ȭ
				copy_map[i][j] = 0;
			}
		}

	cout << maxZero;

	return 0;
}


/*

������ Ǯ���� 7576�� �丶�� ������ ����ؼ� �����ϰ� Ǯ �� �־���.
�ð� �ʰ��� �����Ͽ��µ� ���� �����̾����� ����.

*/