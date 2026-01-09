#include <iostream>
#include <vector>
using namespace std;

int N, M;

int arr[201][201];
bool visit_city[201];
int city_route[1000];

void dfs(int next_city)
{
	visit_city[next_city] = true;

	for (int i = 1; i <= N; i++)
		// 길이 있고, 방문 안한 지역
		if (arr[next_city][i] == 1 && !visit_city[i])
		{
			visit_city[i] = true;
			dfs(i);
		}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	vector<int> route;
	for (int i = 0; i < M; i++)
	{
		cin >> city_route[i];
		route.push_back(city_route[i]);
	}

	// 경로 탐색
	dfs(city_route[0]);

	// 경로를 모두 방문 했는지 체크
	bool clear = true;
	for (int i = 0; i < route.size(); i++)
		if (visit_city[route[i]] == false)
		{
			clear = false;
			break;
		}

	if (clear)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
/*
문제를 잘못 이해해서 첫 시도는 실패했다.
여행 계획이 1, 2, 3일경우 순서대로 1 -> 2 -> 3이 아니더라도 다른 도시를 들렸다가 해당
도시에 들어갈 수 있다면 가능한 것인데 그 생각을 빼먹고 했다.

여행 계획에 속한 도시들을 모두 돌 수 있다면 여행을 할 수 있으므로 나는 dfs로 수정했다.

결국에는 여행계획에 있는 어느 도시에서 출발하든 모든 방문을 마쳐야 가능하므로
여행 경로를 따로 저장하고 해당 경로를 방문 했는지 체크해서 YES or NO 를 출력했다.


다른 사람들은 어떻게 풀었나 찾아봤는데 거의 모든 사람들이 Disjoint-set Union-find 알고리즘을
사용하여 풀었다.

// Union-find 알고리즘 설명
https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html

처음본 알고리즘이라 신기했다.
Union - Find는 트리구조를 이용하여 구현하는 방법으로 Disjoint-set을 표현할 때 사용하는
알고리즘이라고 한다.

Disjoint-set은 서로 중복되지 않는 부분 집합들로 나눠진 원소들에 대한 정보를 저장하고 조작하는
자료구조 즉, 공통 원소가 없는 부분 집합들로 나눠진 원소들에 대한 자료구조이다.

이 자료구조를 보면서 어떻게 이 문제를 보고 이 자료구조를 떠올렸는지가 참 대단한거 같다.
*/