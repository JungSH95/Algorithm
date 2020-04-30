#include <string>
#include <vector>
#include <queue>
using namespace std;

struct compare{
	bool operator()(vector<int> job1, vector<int> job2)
	{
		return job1.size() > job2.size();
	}
};

vector<int> solution(string s) {
	vector<int> answer;
	// ����� ���� ������
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;

	vector<int> temp;
	string num = "";
	bool bIn = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num += s[i];
			bIn = true;
			continue;
		}

		// ���� ��(������ ����)
		if (s[i] == '}' && num.size() != 0)
		{
			temp.push_back(stoi(num));
			pq.push(temp);
			temp.clear();
			num = "";
			bIn = false;
		}

		// ���� ����
		if (s[i] == ',' && bIn == true)
		{
			temp.push_back(stoi(num));
			num = "";
		}
	}

	while (!pq.empty())
	{
		vector<int> tuple = answer;
		temp = pq.top();
		pq.pop();

		int cursor = 0;
		for (int i = 0; i < temp.size(); i++)
			for (int j = 0; j < tuple.size(); j++)
				// ���� �� ó��
				if (temp[i] == tuple[j] && temp[i] != -1)
				{
					temp[i] = -1;
					tuple[j] = -1;
					break;
				}

		// �ٸ� �� ��ġ
		for (int i = 0; i < temp.size(); i++)
			if (temp[i] != -1)
				cursor = i;

		if (temp.size() != tuple.size())
			answer.push_back(temp[cursor]);
	}

	return answer;
}

/*
��ư� �����ϴ� �ٶ��� �����ɷȴ� ����.

�������� �ܰ躰�� Ǯ����� ������ �ϵ�������.

1. ���ڿ� �и��Ͽ� ���� ���Ϳ� �ֱ�
2. size�� ����
3. 1���� �߰��ϸ� �� !
*/