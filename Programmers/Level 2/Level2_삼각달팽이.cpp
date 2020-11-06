#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int Arr[1001][1001];

vector<int> solution(int n) {
	vector<int> answer;

	memset(Arr, 0, sizeof(Arr));

	int count = 1, pos_x = 1, pos_y = 1, dir = 0;

	for (int i = n; i > 0; i--)
	{
		// �Ʒ���
		if (dir == 0)
		{
			for (int j = i; j > 0; j--)
				if (Arr[pos_x][pos_y] == 0)
					Arr[pos_x++][pos_y] = count++;

			dir++;
			pos_y++;
			pos_x--;
		}
		// ����������
		else if (dir == 1)
		{
			for (int j = i; j > 0; j--)
				if (Arr[pos_x][pos_y] == 0)
					Arr[pos_x][pos_y++] = count++;

			dir++;
			pos_x--;
			pos_y -= 2;
		}
		// ����
		else if (dir == 2)
		{
			for (int j = i; j > 0; j--)
				if (Arr[pos_x][pos_y] == 0)
					Arr[pos_x--][pos_y--] = count++;

			dir = 0;
			pos_x += 2;
			pos_y++;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (Arr[i][j] != 0)
				answer.push_back(Arr[i][j]);

	return answer;
}

/*
���� ��ü�� �ܼ��ߴµ�. 
�������� �˰��� ������ Ǯ� �׷��� ���� ��ư� �����ߴ�.

�ܼ��ϰ� �ݺ����� ������ �ذ��ߴ�.

�ѹ��� �־����� ���� n�� 1��ŭ �����ϸ� ���� ä������
n�� 6�̶�� 6�� ä�� �� 5�� ä��� 4�� ä��� ----- 1�� ä��� ���̳���.
*/