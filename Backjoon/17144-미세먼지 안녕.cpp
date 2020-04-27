#include<iostream>
#include<memory.h>
using namespace std;

int R, C, T;
int air_top = 0, air_bottom = 0;

int arr[50][50];
int spread_value[50][50] = { 0, };

// ��, ��, ��, ��
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int cw[] = { 3, 1, 2, 0 };			// �ð����
int ccw[] = { 3, 0, 2, 1 };			// �ݽð����

// �Է�
void input()
{
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];

			// ����û���� ��ġ
			if (arr[i][j] == -1)
			{
				if (air_top == 0)
					air_top = i;
				else
					air_bottom = i;
			}
		}
}
// Ȯ�� ����
void spread()
{
	// Ȯ�� ��ġ �迭 �ʱ�ȭ
	for (int i = 0; i < 50; i++)
		memset(spread_value[i], 0, sizeof(int) * 50);

	// Ȯ�� ��ġ ���
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			// �̼����� on
			if (arr[i][j] != -1)
			{
				// � Ȯ���ϴ��� üũ
				int count = 0;

				// Ȯ�� ��
				int value = arr[i][j] / 5;

				// �ش� ��ǥ���� 4�������� Ȯ��
				for (int k = 0; k < 4; k++)
				{
					int nextY = i + dy[k];
					int nextX = j + dx[k];

					// �ùٸ� ����
					if (nextY >= 0 && nextY < R && nextX >= 0 && nextX < C)
						// ���� û���Ⱑ �ƴϸ� Ȯ��
						if (arr[nextY][nextX] != -1)
						{
							count++;
							spread_value[nextY][nextX] += value;
						}
				}
				// ������ �̼�����
				spread_value[i][j] -= value * count;
			}

	// Ȯ�� ����
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			arr[i][j] += spread_value[i][j];
}

// �ð� ���� ��ȯ
void circulation_cw()
{
	int copyarr[50][50];
	memcpy(copyarr, arr, sizeof(arr));

	int y = air_bottom;
	int x = 1;

	arr[y][x] = 0;


	// 4���� ����
	for (int i = 0; i < 4; i++)
	{
		// �� ���� ������ ����
		while (true)
		{
			int nextY = y + dy[cw[i]];
			int nextX = x + dx[cw[i]];

			// �ùٸ� ������ �ƴϸ� ����
			if (!(nextY >= 0 && nextY < R && nextX >= 0 && nextX < C))
				break;
			// ����û���� ������ ����
			if (nextX == 0 && nextY == air_bottom)
				break;

			arr[nextY][nextX] = copyarr[y][x];

			y = nextY;
			x = nextX;
		}
	}
}

// �ݽð� ���� ��ȯ
void circulation_ccw()
{
	int copyarr[50][50];
	memcpy(copyarr, arr, sizeof(arr));

	int y = air_top;
	int x = 1;

	arr[y][x] = 0;

	// 4���� ����
	for (int i = 0; i < 4; i++)
	{
		// �� ���� ������ ����
		while (true)
		{
			int nextY = y + dy[ccw[i]];
			int nextX = x + dx[ccw[i]];

			// �ùٸ� ������ �ƴϸ� ����
			if (!(nextY >= 0 && nextY < R && nextX >= 0 && nextX < C))
				break;
			// ����û���� ������ ����
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

	// T�� ��ŭ Ȯ�� �� ��ȯ
	for (int i = 0; i < T; i++)
	{
		spread();				// ���ÿ� Ȯ��
		circulation_cw();		// �Ʒ��� : �ð���� ��ȯ
		circulation_ccw();		// ���� : �ݽð���� ��ȯ
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
�˰����� �������� �������־��� ������ �״�� �����ϸ� �����ϰ� Ǯ���� �����̴�.

���� �̻��� ������ �ð��� ��ƸԾ���.

�и��� �̼������� Ȯ�� �� ��ȯ�� ���ϴµ� ������ ���� ��쿡 ���� �޶����� ������ �߻��Ͽ���.
�˰����� ��� ���캸�ٰ� �����ϰ� Ȯ���� Ȯ�� ��ġ �����ϴ� �迭..

�ѹ� ����Ҷ����� �ش� ��ġ���� �����ֱ⶧���� ���� �̻��ϰ� ���ϴ°��̾���.

�ʱ�ȭ ����������..��
*/