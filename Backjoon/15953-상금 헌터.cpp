#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int input;
	cin >> input;

	int cord_festival1[6][2] = { { 500, 1 }, { 300, 2 }, { 200, 3 }, { 50, 4 }, { 30, 5 }, { 10, 6 } };
	int cord_festival2[5][2] = { { 512, 1 }, { 256, 2 }, { 128, 4 }, { 64, 8 }, { 32, 16 } };

	vector<int> total_money;

	for (int i = 0; i < input; i++)
	{
		int rank1, rank2;
		cin >> rank1 >> rank2;

		int money = 0;

		if (rank1 != 0)
		{
			// ù ��ȸ�� ��� ���
			for (int j = 0; j < 6; j++)
			{
				rank1 -= cord_festival1[j][1];
				if (rank1 <= 0)
				{
					money += cord_festival1[j][0];
					break;
				}
			}
		}

		if (rank2 != 0)
		{
			// �� ��° ��ȸ�� ��� ���
			for (int j = 0; j < 5; j++)
			{
				rank2 -= cord_festival2[j][1];
				if (rank2 <= 0)
				{
					money += cord_festival2[j][0];
					break;
				}
			}
		}
		total_money.push_back(money);

	}

	for (int i = 0; i < total_money.size(); i++)
		cout << total_money[i] * 10000 << endl;

	return 0;
}

/*
������ ����
�� ����� ���� ����� �迭�� ����.

�� ��ȸ�� ����� �Է��ϸ� �� ��ȸ�� �´� �迭�� ���� ��� ��� ��
���Ϳ� ���� �־ ����

�������� ������ָ鼭 ��~
*/