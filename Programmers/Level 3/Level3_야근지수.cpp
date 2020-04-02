#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;

	// ū���ڵ�����
	priority_queue<int> pq;
	for (int i = 0; i < works.size(); i++)
		pq.push(works[i]);

	// ���� ū ���� 1�� ����.
	while (n != 0)
	{
		n--;
		int num = pq.top() - 1;
		pq.pop();
		pq.push(num);
	}

	while (!pq.empty())
	{
		int num = pq.top();
		pq.pop();

		if (num > 0)
			answer += (num * num);
	}

	return answer;
}

/*
�� 3������ �ִ��� �𸣰ڴ� ����

��!! �켱���� ť !!
*/