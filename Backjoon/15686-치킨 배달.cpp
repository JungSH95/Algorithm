#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// N : 도시 크기, M : 치킨 집
int N, M;
int map[50][50];

int min_dis = 9999;

// 집의 위치와 치킨 집 위치 저장
vector<pair<int, int>> house, chicken;
bool visit_chicken[13];

void dfs(int count)
{
	// 선택 치킨 집 완료
	if (count == M)
	{
		int total_dis = 0;

		// 집에서 가장 가까운 치킨 집 찾기
		for (int j = 0; j < house.size(); j++)
		{
			int house_x = house[j].first;
			int house_y = house[j].second;
			int dis = 9999;

			for (int i = 0; i < 13; i++)
			{
				// 선택한 치킨 집이라면 거리 계산
				if (visit_chicken[i])
				{
					int chicken_x = chicken[i].first;
					int chicken_y = chicken[i].second;

					dis = min(dis, abs(house_x - chicken_x) + abs(house_y - chicken_y));
				}
			}

			// 가장 작은걸 총 거리에 더해주고 다음 집
			total_dis += dis;
		}

		// 선택한 치킨 집들의 거리가 보다 작으면 값 변경
		min_dis = min(min_dis, total_dis);
		return;
	}

	for (int i = 0; i < chicken.size(); i++)
	{
		if (visit_chicken[i])
			continue;

		visit_chicken[i] = true;
		dfs(count + 1);
		visit_chicken[i] = false;
	}
}

int main()
{
	cin >> N >> M;

	// 맵 입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}

	dfs(0);
	cout << min_dis;

	return 0;
}

/*
치킨 집 M개를 골랐을 때 도시의 치킨 거리 최솟값을 구하는 문제.
M개를 고르려면 전체 경우의 수를 생각 해야함
DFS를 사용하면 전체 경우의 수에 대하여 치킨 거리를 구할 수 있음.

처음 시도때는 dfs에 카운트만 넣어서 시도를 했는데 시간초과로 실패했다.
시간을 줄일 방법중 저번에 사용했던 방법으로 cursor로 어디까지 했는지를 넘겨주어
반복문을 단축시키는 방법을 사용해서 통과했다.
*/
