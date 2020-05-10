#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool visit[20];
int arr[20][20];
int answer = 9999;

void dfs(int count, int cursor)
{
	// �� �̱� �Ϸ�
	if (count == N / 2)
	{
		int start = 0, link = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// ��ŸƮ�� �ɷ�ġ ��
				if (visit[i] && visit[j])
					start += arr[i][j];
				// ��ũ�� �ɷ�ġ ��
				if (!visit[i] && !visit[j])
					link += arr[i][j];
			}
		}

		answer = min(answer, abs(start - link));
		return;
	}

	// ���� �켱 Ž������ ��� ����Ǽ� üũ
	for (int i = cursor; i < N; i++)
	{
		// �湮 ���� ���̶��
		if (!visit[i])
		{
			visit[i] = true;
			dfs(count + 1, i + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	dfs(0, 0);
	cout << answer;

	return 0;
}


/*
dfs�� ����Ͽ� �ذ��� �� �־���.

1. ������ ��ŸƮ ���� �����
2. �湮�� ��ŸƮ ���� �̿��Ͽ� �ɷ�ġ�� ������ ���Ѵ�
3. ���� ���� ����
4. ���� ������ �ݺ�
*/