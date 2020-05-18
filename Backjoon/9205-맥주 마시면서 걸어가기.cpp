#include <iostream>
#include <vector>
#include <cstring> // memset()
#include <cstdlib>
using namespace std;

// 테스트 케이스 개수 : T, 맥주를 파는 편의점의 개수 : N
int T, N;
int start_x, start_y, end_x, end_y;

bool state;
bool visit[100];
vector<pair<int, int>> way_point;

void dfs(int pos_x, int pos_y)
{
	// 현재 위치에서 도착지점 갈 수 있나?
	int dis = abs(end_x - pos_x) + abs(end_y - pos_y);
	if (dis <= 1000)
	{
		state = true;
		return;
	}

	// 이동 가능한 경로 탐색
	for (int i = 0; (long unsigned int)i < way_point.size(); i++)
	{
		// 이미 방문한 편의점 패스
		if (visit[i])
			continue;

		int next_dis = abs(way_point[i].first - pos_x) + abs(way_point[i].second - pos_y);

		// 가능하다면 해당 편의점으로 이동
		if (next_dis <= 1000)
		{
			visit[i] = true;
			dfs(way_point[i].first, way_point[i].second);
		}
	}
}

int main()
{
	cin >> T;

	// 테스트 케이스 수
	for (int t = 0; t < T; t++)
	{
		cin >> N;

		// 집
		cin >> start_x >> start_y;

		memset(visit, 0, sizeof(visit));
		way_point.clear();
		// 편의점, 페스티벌 입력
		for (int i = 0; i < N; i++)
		{
			int x, y;
			cin >> x >> y;
			way_point.push_back(make_pair(x, y));
		}
		cin >> end_x >> end_y;

		state = false;
		dfs(start_x, start_y);

		if (state)
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}

/*
dfs 문제를 여러가지 풀어보면서 많이 익숙해졌다.

크게 어려움을 안느끼고 금방 해결하였다.

컴파일 오류 
1. i < way_point.size()
- VS에서는 오류가 안났으나 백준에서는 오류가 났음 => (long unsigned int) 추가하여 해결

2. memset(visit, 0, sizeof(visit));
- #include <cstring> 미추가로 오류 발생
*/