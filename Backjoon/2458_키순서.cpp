// 백준 키 순서 (https://www.acmicpc.net/problem/2458)

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

int N, M, order;
//map<int, vector<int>> taller, shorter;

vector<int> taller[501];
vector<int> shorter[501];

bool visited[501];

void dfs(int node, map<int, vector<int>> graph) {
	visited[node] = true;

    for (auto next : graph[node]) {
        if (!visited[next]) {
            visited[next] = true;
            order++;
            dfs(next, graph);
        }
    }
}

void dfs(int node, vector<int> graph[]) {
    visited[node] = true;
    for (auto next : graph[node]) {
        if (!visited[next]) {
            visited[next] = true;
            order++;
            dfs(next, graph);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

		taller[a].push_back(b);
        shorter[b].push_back(a);
	}

    int answer = 0;
	for (int i = 1; i <= N; i++) {
        order = 0;
		memset(visited, 0, sizeof(visited));
		dfs(i, taller);
        memset(visited, 0, sizeof(visited));
		dfs(i, shorter);

		if (order == N - 1)
            answer++;
    }

	cout << answer << "\n";
    return 0;
}

// 1차 시도 : 실패, 시간 초과 발생

// 2차 시도 : 성공, map 대신 vector 배열로 사용
