#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>
using namespace std;

// �۾� �ð� ��
struct compare{
	bool operator()(vector<int> job1, vector<int> job2)
	{
		return job1.at(1) > job2.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0, count = 0, time = 0;
	// �켱���� ť
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;

	// ���� ������� ����
	sort(jobs.begin(), jobs.end());

	while (1)
	{
		// �ð����� ���� �� ���� �ֱ�
		while (count != jobs.size())
		{
			if (time >= jobs[count][0])
				pq.push(jobs[count++]);
			else
				break;
		}

		// �۾��� ������ ����(���� ���� �۾��ð�) ó��
		if (!pq.empty())
		{
			// �ҿ�ð� + ���ð�
			answer += (pq.top()[1] + (time - pq.top()[0]));
			time += pq.top()[1];       // �۾��ð���ŭ �ð� ����
			pq.pop();
		}
		else
			time++;

		if (pq.empty() && count == jobs.size())
			break;
	}

	answer = answer / jobs.size();
	return answer;
}