#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < scoville.size(); i++)
		q.push(scoville[i]);

	while (q.size() > 1)
	{
		answer++;

		int num = q.top();
		q.pop();
		int num2 = q.top();
		q.pop();

		q.push(num + (num2 * 2));

		if (q.top() >= K)
			break;
	}

	if (q.top() < K)
		return -1;

	return answer;
}