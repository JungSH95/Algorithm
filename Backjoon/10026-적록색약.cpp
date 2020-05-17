#include <iostream>
#include <string>
using namespace std;

int N;
string RGB_Map[100];
bool visit_RGB[100][100];
bool visit_B[100][100];

// ��, ��, ��, ��
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs_RGB(int x, int y, char c)
{
	if (visit_RGB[x][y])
		return;

	visit_RGB[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int temp_x = x + dx[i];
		int temp_y = y + dy[i];

		if (temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < N)
		{
			if (RGB_Map[temp_x][temp_y] == c)
				dfs_RGB(temp_x, temp_y, c);
		}
	}
}

void dfs_B(int x, int y, char c)
{
	if (visit_B[x][y])
		return;

	visit_B[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int temp_x = x + dx[i];
		int temp_y = y + dy[i];

		if (temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < N)
		{
			switch (c)
			{
			case 'R':
			case 'G':
				if (RGB_Map[temp_x][temp_y] != 'B')
					dfs_B(temp_x, temp_y, c);
				break;
			case 'B':
				if (RGB_Map[temp_x][temp_y] == 'B')
					dfs_B(temp_x, temp_y, c);
				break;
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> RGB_Map[i];

	int count_RGB = 0;
	int count_B = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (!visit_RGB[i][j])
			{
				dfs_RGB(i, j, RGB_Map[i][j]);
				count_RGB++;
			}

			if (!visit_B[i][j])
			{
				dfs_B(i, j, RGB_Map[i][j]);
				count_B++;
			}
		}
	cout << count_RGB << " " << count_B;

	return 0;
}

/*
���� Ǯ���� 2468 ���������� ���� ������ ���� dfs�� ����Ͽ� �� ������ ���� �ľ�

���� dfs�� ���ϻ����� ����� �Ϲݻ���� dfs�� ����� �ذ���

�ٸ� ������� Ǯ�̸� ���� �Է��� ������ �迭 �ΰ��� ����� �����Ѵ�.

���� ��� �� : 1 �� : 2 �� : 3 ���� �� �迭�� ���
�ٸ� �迭�� ��and�� : 1 , �� : 2 �� �� �迭�� ���

���ڷ� ������ �����Ͽ� �ľ��Ͽ���.
*/