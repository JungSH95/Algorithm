#include <iostream>
#include <cstring>
#include <memory.h>
using namespace std;

int T, N;
int arr[1001];
bool visit[1001];

void dfs(int start, int next)
{
	visit[next] = true;

	// ������ �̹� �湮�� ���̸� ����
	if (visit[arr[next]])
		return;

	dfs(start, arr[next]);
}

int main()
{
	// �׽�Ʈ ���̽� �� : T
	cin >> T;

	// �׽�Ʈ ����
	for (int i = 0; i < T; i++)
	{
		// ���� �Է�
		cin >> N;
		for (int j = 1; j <= N; j++)
			cin >> arr[j];

		int cycle_count = 0;
		memset(visit, 0, sizeof(visit));

		for (int j = 1; j <= N; j++)
		{
			if (visit[j])
				continue;

			visit[j] = true;
			cycle_count++;
			dfs(j, arr[j]);
		}

		cout << cycle_count << endl;
	}

	return 0;
}

/*
dfs �� ����Ͽ� ���� ����Ŭ�� �̷�� ���� ã�Ƴ��� ������ ����.

visit ���� üũ�Ͽ� �̹� �湮�� ���� �Ѿ��.
*/