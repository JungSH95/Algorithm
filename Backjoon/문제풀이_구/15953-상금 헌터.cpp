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
			// 첫 대회의 상금 계산
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
			// 두 번째 대회의 상금 계산
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
간단한 문제
각 등수에 따른 상금을 배열로 저장.

각 대회의 등수를 입력하면 각 대회에 맞는 배열을 통해 상금 계산 후
벡터에 값을 넣어서 저장

마지막에 출력해주면서 끝~
*/