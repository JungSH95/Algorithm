#include <iostream>
using namespace std;

int N, M;
int arr[50][50];

// ����(��), ��(��), ������(��) �Ʒ�(��) -> ���� ������ ����
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int clean_count;

void clean_start(int pos_r, int pos_c, int dir)
{
	while (true)
	{
		// 1. ���� ĭ û��
		if (arr[pos_r][pos_c] == 0)
		{
			arr[pos_r][pos_c] = 2;
			clean_count++;
		}

		// 2. Ž�� ���� (���� ������� ���ʴ��)
		bool check = false;
		for (int i = 0; i < 4; i++)
		{
			// ���ʿ� û�� ���Ѱ� �߰�
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
			// �������� ȸ��
			else
			{
				if (dir == 0)
					dir = 3;
				else
					dir -= 1;
			}
		}

		// 3. �� ������ ��� û�Ұ� �Ǿ��ִٸ� �ڰ� ���� �ƴϸ� �ڷ� ����
		if (!check)
		{
			// �� ����
			int temp = dir - 1;
			if (temp < 0)
				temp += 4;

			// �ڰ� ���� ���
			if (arr[pos_r + dy[temp]][pos_c + dx[temp]] == 1)
				break;

			// �ڷ� ���� ����
			pos_r += dy[temp];
			pos_c += dx[temp];
		}
	}
}

int main()
{
	// �� ũ��
	//int N, M;
	cin >> N >> M;

	// (r,c) : û�ұ� ��ǥ, d : ����(0 : ��, 1 : ��, 2 : ��, 3 : ��)
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
�˰����� ���õǾ� �־ �����ϰ� Ǯ �� �ִ� ����
*/