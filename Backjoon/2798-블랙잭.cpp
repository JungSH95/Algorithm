#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	// 카드 수, 총 합 입력
	int card_count, card_sum;
	cin >> card_count >> card_sum;

	// 카드 수 입력
	vector<int> v;
	for (int i = 0; i < card_count; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	int sum = 0;

	for (int i = 0; i < v.size() - 2; i++)
		for (int j = i + 1; j < v.size() - 1; j++)
			for (int k = j + 1; k < v.size(); k++)
				if (v[i] + v[j] + v[k] <= card_sum)
					sum = max(v[i] + v[j] + v[k], sum);
				else if (v[i] + v[j] + v[k] == card_sum)
				{
					cout << v[i] + v[j] + v[k];
					return 0;
				}


	cout << sum;
	return 0;
}

/*
총 합에 가장 가까운 3개의 숫자를 찾는
반복문을 사용하는 간단한 문제
*/