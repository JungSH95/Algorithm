#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool visit[20];
int arr[20][20];
int answer = 9999;

void dfs(int count, int cursor)
{
	// 팀 뽑기 완료
	if (count == N / 2)
	{
		int start = 0, link = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// 스타트팀 능력치 합
				if (visit[i] && visit[j])
					start += arr[i][j];
				// 링크팀 능력치 합
				if (!visit[i] && !visit[j])
					link += arr[i][j];
			}
		}

		answer = min(answer, abs(start - link));
		return;
	}

	// 깊이 우선 탐색으로 모든 경우의수 체크
	for (int i = cursor; i < N; i++)
	{
		// 방문 안한 것이라면
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
dfs를 사용하여 해결할 수 있었다.

1. 가능한 스타트 팀을 만들고
2. 방문한 스타트 팀을 이용하여 능력치의 총합을 구한다
3. 작은 값을 저장
4. 위의 과정을 반복
*/