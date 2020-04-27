#include<iostream>
#include<memory.h>
using namespace std;

int R, C, T;
int air_top = 0, air_bottom = 0;

int arr[50][50];
int spread_value[50][50] = { 0, };

// 상, 하, 좌, 우
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int cw[] = { 3, 1, 2, 0 };			// 시계방향
int ccw[] = { 3, 0, 2, 1 };			// 반시계방향

// 입력
void input()
{
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];

			// 공기청정기 위치
			if (arr[i][j] == -1)
			{
				if (air_top == 0)
					air_top = i;
				else
					air_bottom = i;
			}
		}
}
// 확산 시작
void spread()
{
	// 확산 수치 배열 초기화
	for (int i = 0; i < 50; i++)
		memset(spread_value[i], 0, sizeof(int) * 50);

	// 확산 수치 계산
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			// 미세먼지 on
			if (arr[i][j] != -1)
			{
				// 몇개 확산하는지 체크
				int count = 0;

				// 확산 값
				int value = arr[i][j] / 5;

				// 해당 좌표에서 4방향으로 확산
				for (int k = 0; k < 4; k++)
				{
					int nextY = i + dy[k];
					int nextX = j + dx[k];

					// 올바른 범위
					if (nextY >= 0 && nextY < R && nextX >= 0 && nextX < C)
						// 공기 청정기가 아니면 확산
						if (arr[nextY][nextX] != -1)
						{
							count++;
							spread_value[nextY][nextX] += value;
						}
				}
				// 빠지는 미세먼지
				spread_value[i][j] -= value * count;
			}

	// 확산 적용
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			arr[i][j] += spread_value[i][j];
}

// 시계 방향 순환
void circulation_cw()
{
	int copyarr[50][50];
	memcpy(copyarr, arr, sizeof(arr));

	int y = air_bottom;
	int x = 1;

	arr[y][x] = 0;


	// 4방향 진행
	for (int i = 0; i < 4; i++)
	{
		// 한 방향 끝까지 진행
		while (true)
		{
			int nextY = y + dy[cw[i]];
			int nextX = x + dx[cw[i]];

			// 올바른 범위가 아니면 스톱
			if (!(nextY >= 0 && nextY < R && nextX >= 0 && nextX < C))
				break;
			// 공기청정기 만나면 스톱
			if (nextX == 0 && nextY == air_bottom)
				break;

			arr[nextY][nextX] = copyarr[y][x];

			y = nextY;
			x = nextX;
		}
	}
}

// 반시계 방향 순환
void circulation_ccw()
{
	int copyarr[50][50];
	memcpy(copyarr, arr, sizeof(arr));

	int y = air_top;
	int x = 1;

	arr[y][x] = 0;

	// 4방향 진행
	for (int i = 0; i < 4; i++)
	{
		// 한 방향 끝까지 진행
		while (true)
		{
			int nextY = y + dy[ccw[i]];
			int nextX = x + dx[ccw[i]];

			// 올바른 범위가 아니면 스톱
			if (!(nextY >= 0 && nextY < R && nextX >= 0 && nextX < C))
				break;
			// 공기청정기 만나면 스톱
			if (nextX == 0 && nextY == air_top)
				break;

			arr[nextY][nextX] = copyarr[y][x];

			y = nextY;
			x = nextX;
		}
	}
}

int main()
{
	input();

	// T초 만큼 확산 및 순환
	for (int i = 0; i < T; i++)
	{
		spread();				// 동시에 확산
		circulation_cw();		// 아래쪽 : 시계방향 순환
		circulation_ccw();		// 위쪽 : 반시계방향 순환
	}

	int total = 0;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (arr[i][j] >= 0)
				total += arr[i][j];

	cout << total;
	return 0;
}



/*
알고리즘을 문제에서 제시해주었기 때문에 그대로 진행하면 간단하게 풀리는 문제이다.

나는 이상한 곳에서 시간을 잡아먹었다.

분명히 미세먼지의 확산 및 순환은 잘하는데 여러번 했을 경우에 값이 달라지는 문제가 발생하였다.
알고리즘을 계속 살펴보다가 설마하고 확인한 확산 수치 저장하는 배열..

한번 사용할때마다 해당 수치들이 남아있기때문에 값이 이상하게 변하는것이었다.

초기화 빼먹지말자..ㅠ
*/