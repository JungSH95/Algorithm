#include<iostream>
#include<queue>
using namespace std;

int board_size;
int board_arr[20][20];


void DFS(int arr[][20], int count, int& max)
{
	if (count == 5)
	{
		for (int i = 0; i < board_size; i++)
			for (int j = 0; j < board_size; j++)
				if (max < arr[i][j])
					max = arr[i][j];
		return;
	}

	int save[20][20];
	// 보드 임시 저장
	for (int i = 0; i < board_size; i++)
		for (int j = 0; j < board_size; j++)
			save[i][j] = arr[i][j];

	// 상하좌우 이동
	for (int i = 0; i < 4; i++)
	{
		queue<int> q;

		switch (i)
		{
			// 상
		case 0:
		{
			for (int x = 0; x < board_size; x++)
			{
				for (int y = 0; y < board_size; y++)
					if (arr[y][x] != 0)
					{
						q.push(arr[y][x]);
						arr[y][x] = 0;
					}

				int cursor = 0;
				while (!q.empty())
				{
					int temp = q.front();
					q.pop();

					// 다음 원소가 있다면
					if (!q.empty())
					{
						// 같으면
						if (temp == q.front())
						{
							arr[cursor++][x] = temp * 2;
							q.pop();
						}
						else
							arr[cursor++][x] = temp;
					}
					else
						arr[cursor++][x] = temp;
				}
			}

			break;
		}
		// 하
		case 1:
		{
			for (int x = 0; x < board_size; x++)
			{
				for (int y = board_size - 1; y >= 0; y--)
					if (arr[y][x] != 0)
					{
						q.push(arr[y][x]);
						arr[y][x] = 0;
					}

				int cursor = board_size - 1;
				while (!q.empty())
				{
					int temp = q.front();
					q.pop();

					// 다음 원소가 있다면
					if (!q.empty())
					{
						// 같으면
						if (temp == q.front())
						{
							arr[cursor--][x] = temp * 2;
							q.pop();
						}
						else
							arr[cursor--][x] = temp;
					}
					else
						arr[cursor--][x] = temp;
				}
			}

			break;
		}
		// 좌
		case 2:
		{
			for (int x = 0; x < board_size; x++)
			{
				for (int y = 0; y < board_size; y++)
					if (arr[x][y] != 0)
					{
						q.push(arr[x][y]);
						arr[x][y] = 0;
					}

				int cursor = 0;
				while (!q.empty())
				{
					int temp = q.front();
					q.pop();

					// 다음 원소가 있다면
					if (!q.empty())
					{
						// 같으면
						if (temp == q.front())
						{
							arr[x][cursor++] = temp * 2;
							q.pop();
						}
						else
							arr[x][cursor++] = temp;
					}
					else
						arr[x][cursor++] = temp;
				}
			}

			break;
		}
		// 우
		case 3:
		{
			for (int x = 0; x < board_size; x++)
			{
				for (int y = board_size - 1; y >= 0; y--)
					if (arr[x][y] != 0)
					{
						q.push(arr[x][y]);
						arr[x][y] = 0;
					}

				int cursor = board_size - 1;
				while (!q.empty())
				{
					int temp = q.front();
					q.pop();

					// 다음 원소가 있다면
					if (!q.empty())
					{
						// 같으면
						if (temp == q.front())
						{
							arr[x][cursor--] = temp * 2;
							q.pop();
						}
						else
							arr[x][cursor--] = temp;
					}
					else
						arr[x][cursor--] = temp;
				}
			}

			break;
		}
		}

		DFS(arr, count + 1, max);

		// 보드 복구
		for (int i = 0; i < board_size; i++)
			for (int j = 0; j < board_size; j++)
				board_arr[i][j] = save[i][j];
	}

	return;
}

int main()
{
	cin >> board_size;

	for (int i = 0; i < board_size; i++)
		for (int j = 0; j < board_size; j++)
			cin >> board_arr[i][j];

	int max = 0;
	DFS(board_arr, 0, max);
	cout << max;

	return 0;
}


/*
예전에 해봣던 게임 2048의 게임원리인듯하다.

1. 이동하는 것을 먼저 구현하고
2. DFS(깊이 우선 탐색)를 사용하여 상하좌우를 탐색한다.
	-> 가장 큰 값을 저장

확인하지 않고 풀다가 하나가 걸려서 처음 시도에 실패를 했는데.
이차원배열로 넘겨줄경우 매개변수에서 [][20]으로 적는 것은 눈속임이다.
main에서 함수에 매개변수로 넘겨줄때 2차원 배열의 주소를 넘기기 때문에
기존의 보드판을 저장할 필요가 있다.

매개변수 인자로
int [20][20] or int [][20] or int (*arr)[20] 의 모습으로 전달해야한다.

시간이 좀 걸리긴 했지만 쉽게 해결
*/