#include <iostream>
#include <cstring>
using namespace std;

// �ʺ�, ����
int W, H;
int map[50][50];
bool visit[50][50];

// �����¿�, �밢��(������ �������� ���ʾƷ� �����ʾƷ�)
int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

void dfs(int x, int y)
{
	// 8���� ���⿡ ���Ͽ� Ž��
	for (int i = 0; i < 8; i++)
	{
		int next_dx = x + dx[i];
		int next_dy = y + dy[i];

		// �ùٸ� ���� �ΰ�
		if (next_dx >= 0 && next_dx < H && next_dy >= 0 && next_dy < W)
		{
			// �湮�� ���ߴٸ�
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

		// �� ���� �Է�
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
map�� �־����� �װͿ� ���Ͽ� ���ǿ� �´� ������ ã�� ���̴�.
�ٸ� �ٸ� ���� ����,���� �Ӹ� �ƴ϶� �밢���� üũ�ϴ� ��
dfs�� ����Ͽ� �ذ��ߴ�.

�׽�Ʈ ���̽��� ���� ���� �������� �ʰ� 0,0�� �ԷµǸ� ����
while���� ����Ͽ� ���� �ݺ��� ����ϰ�
�� �ʰ� �湮 üũ �迭�� �ʱ�ȭ�� ��� �����ش�.
*/
