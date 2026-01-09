#include <iostream>
#include <string>
using namespace std;

int N;
string RGB_Map[100];
bool visit_RGB[100][100];
bool visit_B[100][100];

// 상, 하, 좌, 우
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
어제 풀었던 2468 안전영역과 거의 동일한 문제 dfs를 사용하여 각 구역의 수를 파악

나는 dfs를 적록색약인 사람과 일반사람의 dfs로 나누어서 해결함

다른 사람들의 풀이를 보니 입력을 받을때 배열 두개로 나누어서 저장한다.

예를 들면 빨 : 1 초 : 2 파 : 3 으로 한 배열에 사용
다른 배열은 빨and초 : 1 , 파 : 2 로 한 배열에 사용

숫자로 구역을 구분하여 파악하였다.
*/