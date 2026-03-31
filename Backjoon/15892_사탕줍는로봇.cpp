// 백준 사탕 줍는 로봇 (https://www.acmicpc.net/problem/15892)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int total_flow = 0;
int c[301][301];
int f[301][301];
vector<int> graph[301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
		cin >> a >> b >> cost;

		c[a][b] += cost;
		c[b][a] += cost;

		graph[a].push_back(b);
		graph[b].push_back(a);
    }

	while (true) {
		int parent[301];
		memset(parent, -1, sizeof(parent));

		queue<int> q;
		q.push(1);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (auto next : graph[cur]) {
				// 아직 방문하지 않았고, 용량이 남아있는 경우
				if (parent[next] == -1 && c[cur][next] - f[cur][next] > 0) {
					parent[next] = cur;
					q.push(next);

					// 도착점에 도달한 경우
					if (next == n)
						break;
				}
			}
		}

		// 도착점까지의 경로를 못 찾은 경우, 더 이상 경로가 없음
		if (parent[n] == -1) {
			break;
		}

		// 증가 경로로 새로 흘려줄 유량 = 경로 중 최소 잔여 용량
		int flow = 987654321;
		for (int i = n; i != 1; i = parent[i])
			flow = min(flow, c[parent[i]][i] - f[parent[i]][i]);

		// 증가 경로로 유량 흘려주기, 역 방향 경로는 유량 빼주기
		for (int i = n; i != 1; i = parent[i]) {
			f[parent[i]][i] += flow;
			f[i][parent[i]] -= flow;
		}

		total_flow += flow;
	}

	cout << total_flow << endl;
    return 0;
}

// 1차 시도 : 성공, 처음 접한 최대 유량 문제
/*
* 최대 유량 문제는 네트워크에서 흐를 수 있는 최대의 유량을 구하는 문제입니다. 
* 이 문제에서는 각 간선에 용량이 주어지고, 시작점에서 끝점까지 흐를 수 있는 최대 유량을 계산해야 합니다. 
* 일반적으로 Ford-Fulkerson 알고리즘이나 Edmonds-Karp 알고리즘을 사용하여 해결할 수 있습니다. 
* 이 문제에서는 BFS를 사용하여 경로를 찾고, 그 경로에 따라 유량을 업데이트하는 방식으로 구현할 수 있습니다.
*/
