#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string wheel_arr[4];				// ��Ϲ��� N/S�� ����
int wheel_rotation[4];
int pos_12[4] = { 0, };				// 12���� ��ġ ����

// �ش� ��Ϲ����� ����(6) ��ġ ��ȯ
int getLeftNumber(int wheel_num)
{
	int temp = pos_12[wheel_num] - 2;
	if (temp < 0)
		temp += 8;

	return temp;
}

// �ش� ��Ϲ����� ������(2) ��ġ ��ȯ
int getRightNumber(int wheel_num)
{
	int temp = pos_12[wheel_num] + 2;
	if (temp > 7)
		temp -= 8;

	return temp;
}

int main()
{
	// ��Ϲ��� N/S�� �Է�
	for (int i = 0; i < 4; i++)
		cin >> wheel_arr[i];

	// ��Ϲ��� ȸ�� ��
	int rotation_count;
	cin >> rotation_count;

	for (int i = 0; i < rotation_count; i++)
	{
		int whell_number, rotation_dir;
		cin >> whell_number >> rotation_dir;
		wheel_rotation[whell_number - 1] = rotation_dir;

		// ���� ����
		for (int j = whell_number - 1; j > 0; j--)
		{
			// ȸ���� ���ϸ� �������� ȸ�� ����
			if (wheel_rotation[j] == 0)
			{
				wheel_rotation[j - 1] = 0;
				continue;
			}

			// ���� ������ ȸ��
			if (wheel_arr[j - 1][getRightNumber(j - 1)] != wheel_arr[j][getLeftNumber(j)])
				wheel_rotation[j - 1] = wheel_rotation[j] * -1;
			// ������ ȸ�� ����
			else
				wheel_rotation[j - 1] = 0;
		}

		// ������ ����
		for (int j = whell_number - 1; j < 3; j++)
		{
			// ȸ���� ���ϸ� �������� ȸ�� ����
			if (wheel_rotation[j] == 0)
			{
				wheel_rotation[j + 1] = 0;
				continue;
			}

			// ���� ������ ȸ��
			if (wheel_arr[j][getRightNumber(j)] != wheel_arr[j + 1][getLeftNumber(j + 1)])
				wheel_rotation[j + 1] = wheel_rotation[j] * -1;
			// ������ ȸ�� ����
			else
				wheel_rotation[j + 1] = 0;
		}

		// ȸ�� ����
		for (int j = 0; j < 4; j++)
		{
			if (wheel_rotation[j] == 1)
			{
				pos_12[j] -= 1;
				if (pos_12[j] < 0)
					pos_12[j] = 7;
			}
			else if (wheel_rotation[j] == -1)
			{
				pos_12[j] += 1;
				if (pos_12[j] > 7)
					pos_12[j] = 0;
			}
		}
	}

	int total_score = 0;
	for (int i = 0; i < 4; i++)
	{
		if (wheel_arr[i][pos_12[i]] == '1')
			total_score += pow(2, i);
	}
	cout << total_score;
	return 0;
}

/*
���� Ǫ�� ��̰� �־��� ����
ȸ����Ű�� ��Ϲ����� �������� ���ʰ� �������� ������� �� ��Ϲ����� ȸ�� ������ �˾Ƴ� ��
12�ø� ����Ű�� pos_12�� ����Ͽ� 12���� ��ġ�� �����Ͽ���.
��Ϲ����� �� ���ʰ� �������� ���� �� �ִ� �Լ��� ����Ͽ� �ٷ� ���Ͽ� ����ϵ��� �ߴ�.
*/