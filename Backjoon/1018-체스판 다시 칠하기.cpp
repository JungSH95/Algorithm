#include<iostream>
using namespace std;

char pan[50][50];
char copy_pan[8][8];

int changeColor()
{
	int count = 0;

	// ������ ���� ���� (���� B, W �� ���� ��� üũ�ؾ���)
	char new_pan[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			new_pan[i][j] = copy_pan[i][j];


	// ù ��° ���� �������� ��������
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			// ���� �ǰ� ��
			if (new_pan[i][j - 1] == 'B' && new_pan[i][j] == 'B')
			{
				count++;
				new_pan[i][j] = 'W';
			}
			else if (new_pan[i][j - 1] == 'W' && new_pan[i][j] == 'W')
			{
				count++;
				new_pan[i][j] = 'B';
			}
		}

		// ���� �� ù��° ����, ������ ������ �� �ϰ��
		if (i + 1 < 8)
		{
			// ���� ���� ó���� B�̸� ���� ���� ������ W
			if (new_pan[i][0] == 'B' && new_pan[i + 1][0] == 'B')
			{
				new_pan[i + 1][0] = 'W';
				count++;
			}
			else if (new_pan[i][0] == 'W' && new_pan[i + 1][0] == 'W')
			{
				new_pan[i + 1][0] = 'B';
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int N, M;
	cin >> N >> M;

	int min = 999;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> pan[i][j];

	// ������ ü���� ��ȸ
	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++)
		{
			for (int x = 0; x < 8; x++)
				for (int y = 0; y < 8; y++)
					copy_pan[x][y] = pan[i + x][j + y];

			int num1, num2;
			// ������ B�� ���
			if (copy_pan[0][0] == 'B')
			{
				num1 = changeColor();

				// ������ W�� �������� ���
				copy_pan[0][0] = 'W';
				num2 = changeColor() + 1;
			}
			else if (copy_pan[0][0] == 'W')
			{
				num1 = changeColor();

				// ������ B�� �������� ���
				copy_pan[0][0] = 'B';
				num2 = changeColor() + 1;
			}

			if (num1 >= num2)
			{
				if (min >= num2)
					min = num2;
			}
			else
				if (min >= num1)
					min = num1;
		}

	cout << min;
	return 0;
}



/*

ó�� �׽�Ʈ �� ����

���� : ù ���ڸ� �������� Ȯ���Ѵ�. ���� ù��°�� W�� B�θ� ���������� 1������ ������ ����
���� ���� �����ع��� ������ ����

�ذ� : ù���� B���ذ� W�������� ������ ī��Ʈ�ѵ� �� ���� ���� üũ

*/