#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int people[9], total = 0;
	vector<int> answer;

	for (int i = 0; i < 9; i++)
	{
		cin >> people[i];
		total += people[i];
	}

	// �θ� ã��
	bool check = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			// ������ 100�̸�
			if (total - (people[i] + people[j]) == 100)
			{
				people[i] = -1;
				people[j] = -1;
				check = true;
			}
		}
		if (check)
			break;
	}

	for (int i = 0; i < 9; i++)
		if (people[i] != -1)
			answer.push_back(people[i]);

	// ������ Ű ���
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

	return 0;
}

/*
�� ���ٰ� �����ϰ� �ĵ� Ǯ�ٰ� Ʋ���淡 ����? �ߴ� ����..
�ᱹ ã�� ���� ��û�� �Ǽ��� �ߴ�.
�� �� ã���� �� ã���� �ݺ����� �ƿ� �������ϴµ�
�ȿ� �ִ� �ݺ����� break �� �Ǽ��� �ߴ�.

bool�� ����Ͽ� äũ �� �ذ�
*/