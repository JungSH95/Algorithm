#include <iostream>
#include <vector>
using namespace std;

bool visit[1001];
vector<int> nodes[1001];

void dfs(int node)
{
	visit[node] = true;

	// ���� ���� ����� �� Ž��
	for (int i = 0; i < nodes[node].size(); i++)
	{
		int next_node = nodes[node][i];

		// �ٸ� ��带 �湮 �������� �湮
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
	// �湮 ���� ��� Ž��
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
����� ����� ������ ���ϴ� ����
dfs�� ����Ͽ� �ش� ��忡 ������ִ� ��� ��带 Ž���Ѵ�.
*/