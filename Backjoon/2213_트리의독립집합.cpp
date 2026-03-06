// 백준 트리의 독립집합 (https://www.acmicpc.net/problem/2213)

#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> cost(10001, 0);
map<int, vector<int>> graph;
vector<bool> visit(10001, false);
vector<vector<int>> dp(10001, vector<int>(2, 0));

void dfs(int curNode) {

	// 0 : 포함하지 않는 경우, 1 : 포함하는 경우
	dp[curNode][0] = 0;
	dp[curNode][1] = cost[curNode];
	visit[curNode] = true;

	for (auto child : graph[curNode]) {
		if (visit[child])
			continue;

		dfs(child);

		// 포함하지 않으니까 자식의 포함(사용) 유무에 상관이 없음
		dp[curNode][0] += max(dp[child][0], dp[child][1]);

		// 포함했기 때문에 자식은 사용X
		dp[curNode][1] += dp[child][0];
	}
}

void pathFind(int curNode, int prevNode, vector<int> &path) {
	// 큰 경우 경로 추가, 이전 노드 방문X
	if (dp[curNode][1] > dp[curNode][0] && !visit[prevNode]) {
		path.push_back(curNode);
		visit[curNode] = true;
	}

	for (auto child : graph[curNode]) {
		if (child == prevNode)
			continue;

		pathFind(child, curNode, path);
	}
}

int main() {

	int node;
	cin >> node;

	for (int i = 1; i <= node; i++) {
		int tmp;
		cin >> tmp;
		cost[i] = tmp;
	}

	for (int i = 0; i < node - 1; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}


	dfs(1);
	
	fill(visit.begin(), visit.end(), false);
	vector<int> path;
	pathFind(1, 0, path);
	sort(path.begin(), path.end());

	cout << max(dp[1][0], dp[1][1]) << endl;
	for (auto node : path)
		cout << node << " ";

	return 0;
}

// 아직 DP를 적용하는 부분에 있어서 어렵다.

// 1차 시도 : 시간 초과
// 2차 시도 : 실패, 혹시나해서 cost, graph, visit, dp의 변수를 전역 변수로 변경 후 시간 초과는 발생 X
// 3차 시도 : 성공, 경로를 재추적하는 과정에서 인접한 노드인 경우 추가하지 못하도록 수정

