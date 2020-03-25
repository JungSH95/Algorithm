#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>
using namespace std;

// 작업 시간 비교
struct compare{
	bool operator()(vector<int> job1, vector<int> job2)
	{
		return job1.at(1) > job2.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0, count = 0, time = 0;
	// 우선순위 큐
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;

	// 들어온 순서대로 정렬
	sort(jobs.begin(), jobs.end());

	while (1)
	{
		// 시간보다 작은 것 전부 넣기
		while (count != jobs.size())
		{
			if (time >= jobs[count][0])
				pq.push(jobs[count++]);
			else
				break;
		}

		// 작업이 있으면 맨위(가장 작은 작업시간) 처리
		if (!pq.empty())
		{
			// 소요시간 + 대기시간
			answer += (pq.top()[1] + (time - pq.top()[0]));
			time += pq.top()[1];       // 작업시간만큼 시간 증가
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