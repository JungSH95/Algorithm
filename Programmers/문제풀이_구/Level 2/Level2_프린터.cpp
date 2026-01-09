#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> q;
	priority_queue<int> pq;

	for (int i = 0; i< priorities.size(); i++)
	{
		q.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}

	while (!q.empty())
	{
		int lo = q.front().first;
		int num = q.front().second;
		q.pop();

		if (pq.top() == num)
		{
			if (lo == location)
				break;
			pq.pop();
			answer++;
		}
		else
			q.push(make_pair(lo, num));
	}

	return answer + 1;
}