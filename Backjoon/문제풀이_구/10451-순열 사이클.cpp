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

	// 다음이 이미 방문한 곳이면 종료
	if (visit[arr[next]])
		return;

	dfs(start, arr[next]);
}

int main()
{
	// 테스트 케이스 수 : T
	cin >> T;

	// 테스트 시작
	for (int i = 0; i < T; i++)
	{
		// 순열 입력
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
dfs 를 사용하여 순열 사이클을 이루는 것을 찾아내는 간단한 문제.

visit 으로 체크하여 이미 방문한 곳은 넘어간다.
*/