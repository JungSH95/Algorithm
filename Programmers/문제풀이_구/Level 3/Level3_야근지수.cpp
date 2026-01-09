#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;

	// 큰값자동정렬
	priority_queue<int> pq;
	for (int i = 0; i < works.size(); i++)
		pq.push(works[i]);

	// 가장 큰 값들 1씩 감소.
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
왜 3레벨에 있는지 모르겠는 문제

갓!! 우선순위 큐 !!
*/