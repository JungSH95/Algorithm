#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;

	// 우선순위 큐를 사용한 MinHeap 
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	int total_time = 0, wait_time = 0;
	while (!pq.empty())
	{
		total_time += (pq.top() + wait_time);
		wait_time += pq.top();
		pq.pop();
	}

	cout << total_time;
	return 0;
}


/*
줄서는 사람 순서에 따른 필요시간의 최소시간을 구하는 문제

대기시간을 가장 최소화 시키기 위해서는 빠른 사람을 먼저 처리하는 방법이다.

우선순위큐를 사용하여 minHeap을 만들어서 작은 것부터 처리하며 해결했다.
*/