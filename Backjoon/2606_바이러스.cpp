#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;

// 백준 바이러스 (https://www.acmicpc.net/problem/2606)
int main() {

	int computerCount;
	cin >> computerCount;

	int networkConnectCount;
	cin >> networkConnectCount;

	map<int, vector<int>> networkLine;
	for (int i = 0; i < networkConnectCount; i++) {
		int a, b;
		cin >> a >> b;

		networkLine[a].push_back(b);
		networkLine[b].push_back(a);
	}

	int virusCount = 0;
	vector<bool> visited(computerCount + 1, false);
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int now_computer = q.front();
		q.pop();

		for (auto next_computer : networkLine[now_computer]) {
			if (!visited[next_computer]) {
				q.push(next_computer);
				visited[next_computer] = true;
				virusCount += 1;
			}
		}
	}

	cout << virusCount << endl;

	return virusCount;
}