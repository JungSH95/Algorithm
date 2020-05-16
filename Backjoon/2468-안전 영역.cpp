#include<iostream>
using namespace std;

int N;
int height_Arr[100][100];
bool area_visit[100][100];
int max_height = 0, max_count = 0;

// 상, 하, 좌, 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void Area_Initialization()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			area_visit[i][j] = false;
}

void dfs(int x, int y)
{
	// 방문 한거 패스
	if (area_visit[x][y])
		return;

	area_visit[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int temp_x = x + dx[i];
		int temp_y = y + dy[i];

		if (temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < N)
			if (height_Arr[temp_x][temp_y] > max_height)
				dfs(temp_x, temp_y);
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> height_Arr[i][j];
			if (height_Arr[i][j] >= max_height)
				max_height = height_Arr[i][j];
		}


	while (max_height >= 0)
	{
		int count = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// 방문 안한 지역
				if (!area_visit[i][j] && height_Arr[i][j] > max_height)
				{
					count++;
					dfs(i, j);
				}
			}
		}

		// 방문 확인 배열 초기화
		Area_Initialization();
		// 잠기는 높이 감소
		max_height -= 1;

		if (max_count <= count)
			max_count = count;
	}

	cout << max_count;

	return 0;
}

/*
안전한 지역을 탐색하여 가장 많은 안전영역의 개수를 출력하는 문제

지정된 물높이가 없어서 가장 큰 높이를 기준으로 하나씩 감소하며 가장 많은 안전영역이 나오는 것을 찾는다.

높이가 최대 100까지이므로 시간 초과걱정을 하였으나 통과함
*/