#include <iostream>
using namespace std;

int N, M;
int arr[50][50];

// 왼쪽(서), 위(북), 오른쪽(동) 아래(남) -> 현재 방향의 왼쪽
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int clean_count;

void clean_start(int pos_r, int pos_c, int dir)
{
	while (true)
	{
		// 1. 현재 칸 청소
		if (arr[pos_r][pos_c] == 0)
		{
			arr[pos_r][pos_c] = 2;
			clean_count++;
		}

		// 2. 탐색 시작 (왼쪽 방향부터 차례대로)
		bool check = false;
		for (int i = 0; i < 4; i++)
		{
			// 왼쪽에 청소 안한곳 발견
			if (arr[pos_r + dy[dir]][pos_c + dx[dir]] == 0)
			{
				pos_r += dy[dir];
				pos_c += dx[dir];

				if (dir == 0)
					dir = 3;
				else
					dir -= 1;

				check = true;
				break;
			}
			// 왼쪽으로 회전
			else
			{
				if (dir == 0)
					dir = 3;
				else
					dir -= 1;
			}
		}

		// 3. 네 방향이 모두 청소가 되어있다면 뒤가 벽이 아니면 뒤로 후진
		if (!check)
		{
			// 뒷 방향
			int temp = dir - 1;
			if (temp < 0)
				temp += 4;

			// 뒤가 벽일 경우
			if (arr[pos_r + dy[temp]][pos_c + dx[temp]] == 1)
				break;

			// 뒤로 후진 가능
			pos_r += dy[temp];
			pos_c += dx[temp];
		}
	}
}

int main()
{
	// 방 크기
	//int N, M;
	cin >> N >> M;

	// (r,c) : 청소기 좌표, d : 방향(0 : 북, 1 : 동, 2 : 남, 3 : 서)
	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	clean_start(r, c, d);
	cout << clean_count;
	return 0;
}

/*
알고리즘이 제시되어 있어서 간단하게 풀 수 있는 문제
*/