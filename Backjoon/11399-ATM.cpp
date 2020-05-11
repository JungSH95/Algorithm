#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;

	// �켱���� ť�� ����� MinHeap 
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
�ټ��� ��� ������ ���� �ʿ�ð��� �ּҽð��� ���ϴ� ����

���ð��� ���� �ּ�ȭ ��Ű�� ���ؼ��� ���� ����� ���� ó���ϴ� ����̴�.

�켱����ť�� ����Ͽ� minHeap�� ���� ���� �ͺ��� ó���ϸ� �ذ��ߴ�.
*/