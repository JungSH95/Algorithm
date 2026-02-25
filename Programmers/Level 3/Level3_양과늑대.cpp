#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
	vector<vector<int>> graph(info.size());
	for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        //graph[edges[i][1]].push_back(edges[i][0]);
    }

	vector<bool> visited(info.size(), false);
	queue<int> savedNodes;
	queue<int> q;
	q.push(0);
	visited[0] = true;
	int sheepCount = 1;
	int wolfCount = 0;

	while (!q.empty()) {

		int currentNode = q.front();

		cout << "현재 노드 : " << currentNode << ", 양 수 : " << sheepCount << ", 늑대 수 : " << wolfCount << endl;

		q.pop();

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int nextNode = graph[currentNode][i];

			if (!visited[nextNode]) {

				cout << "다음 노드 : " << nextNode << ", 양 수 : " << sheepCount << ", 늑대 수 : " << wolfCount << endl;

				// 양 노드
				if (info[nextNode] == 0) {
					visited[nextNode] = true;
					q.push(nextNode);
					sheepCount++;

				}

				// 늑대 노드, 자식이 없으면 방문처리만
				else if (info[nextNode] == 1 && graph[nextNode].size() == 0)
					visited[nextNode] = true;

				// 늑대 노드
				else if (info[nextNode] == 1 && wolfCount + 1 < sheepCount/* && graph[nextNode].size() != 0*/) {
					visited[nextNode] = true;
					q.push(nextNode);
					wolfCount++;
				}

				// 늑대 노드, 자식이 있고 양보다 늑대가 많아지는 경우 보류
				else if (info[nextNode] == 1 && wolfCount + 1 >= sheepCount && graph[nextNode].size() != 0)
					savedNodes.push(nextNode);
			}
		}

		if (q.empty() && savedNodes.size() > 0) {
			int savedNode = savedNodes.front();
			savedNodes.pop();
			cout << "보류된 노드 : " << savedNode << ", 양 수 : " << sheepCount << ", 늑대 수 : " << wolfCount << endl;
			if (wolfCount + 1 < sheepCount) {
				visited[savedNode] = true;
				q.push(savedNode);
				wolfCount++;
			}
		}
    }

	for (int i = 0; i < visited.size(); i++)
		cout << "노드 " << i << " 방문 여부 : " << visited[i] << endl;


    return sheepCount;
}

int maxSheepCount = 0;

void dfs(int currentNode, vector<int> info, vector<vector<int>> graph, int sheepCount, int wolfCount, queue<int> q) {
	if (info[currentNode] == 0)
		sheepCount++;
	else
		wolfCount++;

	if (wolfCount >= sheepCount)
		return;

	maxSheepCount = max(maxSheepCount, sheepCount);

	for (int i = 0; i < graph[currentNode].size(); i++) {
		int nextNode = graph[currentNode][i];
		q.push(nextNode);
	}

	for (int i = 0; i < q.size(); i++) {
		int nextNode = q.front();
		q.pop();
		dfs(nextNode, info, graph, sheepCount, wolfCount, q);
		q.push(nextNode);
	}
}

int solution1(vector<int> info, vector<vector<int>> edges) {
	vector<vector<int>> graph(info.size());
	for (int i = 0; i < edges.size(); i++)
		graph[edges[i][0]].push_back(edges[i][1]);

	queue<int> q;
	dfs(0, info, graph, 0, 0, q);

	return maxSheepCount;
}

// 1차 시도 : 실패, bfs를 사용하여 시도했으나 늑대 노드에 대한 조건 처리에서 문제 발생

// 2차 시도 : 성공, 노드의 수가 최대 17개로 작기 때문에 dfs를 사용하는 방법으로 시도
// 문제를 생각하는 방법이 까다로웠음