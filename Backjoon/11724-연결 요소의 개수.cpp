#include <iostream>
#include <vector>
using namespace std;

bool visit[1001];
vector<int> nodes[1001];

void dfs(int node)
{
	visit[node] = true;

	// 현재 노드와 연결된 곳 탐색
	for (int i = 0; i < nodes[node].size(); i++)
	{
		int next_node = nodes[node][i];

		// 다른 노드를 방문 안했으면 방문
		if (!visit[next_node])
			dfs(next_node);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int point1, point2;
		cin >> point1 >> point2;

		nodes[point1].push_back(point2);
		nodes[point2].push_back(point1);
	}

	int count = 0;
	// 방문 안한 노드 탐색
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			dfs(i);
			count++;
		}
	}

	cout << count;

	return 0;
}


/*
연결된 요소의 개수를 구하는 문제
dfs를 사용하여 해당 노드에 연결되있는 모든 노드를 탐색한다.
*/