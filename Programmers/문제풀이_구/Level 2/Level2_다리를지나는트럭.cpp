#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int curWeight = weight;
	queue<int> q;

	for (int i = 0; i < truck_weights.size(); i++)
	{
		while (true)
		{
			if (curWeight >= truck_weights[i])
			{
				q.push(truck_weights[i]);
				curWeight -= truck_weights[i];
				answer++;

				if (q.size() >= bridge_length)
				{
					curWeight += q.front();
					q.pop();
				}
				break;
			}
			else
				q.push(0);

			if (q.size() >= bridge_length)
			{
				curWeight += q.front();
				q.pop();
			}
			answer++;
		}
	}
	answer += bridge_length;

	return answer;
}