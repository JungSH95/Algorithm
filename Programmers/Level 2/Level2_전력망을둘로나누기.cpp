#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

/*
* n : 송전탑의 개수
* wires : 송전탑을 연결하는 전선의 정보
*/
int solution(int n, vector<vector<int>> wires) {
    int answer = -1;

    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> tempWires = wires;
		tempWires.erase(tempWires.begin() + i);

        vector<vector<int>> graph(n + 1);
        for (const auto& wire : tempWires) {
            graph[wire[0]].push_back(wire[1]);
            graph[wire[1]].push_back(wire[0]);
        }

        // 연결된 송전탑의 개수 세기
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int count = 0;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            count++;

            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // 전체 송전탑 개수에서 연결된 송전탑 차이 계산
        int difference = abs(count - (n - count));
        if (answer == -1 || difference < answer) 
            answer = difference;
    }

    return answer;
}

// 1차 시도 : 성공