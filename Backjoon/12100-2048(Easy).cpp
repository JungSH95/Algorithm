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
	// ���� �ӽ� ����
	for (int i = 0; i < board_size; i++)
		for (int j = 0; j < board_size; j++)
			save[i][j] = arr[i][j];

	// �����¿� �̵�
	for (int i = 0; i < 4; i++)
	{
		queue<int> q;

		switch (i)
		{
			// ��
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

					// ���� ���Ұ� �ִٸ�
					if (!q.empty())
					{
						// ������
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
		// ��
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

					// ���� ���Ұ� �ִٸ�
					if (!q.empty())
					{
						// ������
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
		// ��
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

					// ���� ���Ұ� �ִٸ�
					if (!q.empty())
					{
						// ������
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
		// ��
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

					// ���� ���Ұ� �ִٸ�
					if (!q.empty())
					{
						// ������
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

		// ���� ����
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
������ �ؔf�� ���� 2048�� ���ӿ����ε��ϴ�.

1. �̵��ϴ� ���� ���� �����ϰ�
2. DFS(���� �켱 Ž��)�� ����Ͽ� �����¿츦 Ž���Ѵ�.
	-> ���� ū ���� ����

Ȯ������ �ʰ� Ǯ�ٰ� �ϳ��� �ɷ��� ó�� �õ��� ���и� �ߴµ�.
�������迭�� �Ѱ��ٰ�� �Ű��������� [][20]���� ���� ���� �������̴�.
main���� �Լ��� �Ű������� �Ѱ��ٶ� 2���� �迭�� �ּҸ� �ѱ�� ������
������ �������� ������ �ʿ䰡 �ִ�.

�Ű����� ���ڷ�
int [20][20] or int [][20] or int (*arr)[20] �� ������� �����ؾ��Ѵ�.

�ð��� �� �ɸ��� ������ ���� �ذ�
*/