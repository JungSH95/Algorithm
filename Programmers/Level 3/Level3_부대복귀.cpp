#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

/*
    int n;                          강철부대가 위치한 지역을 포함한 총 지역의 수
    vector<vector<int>> roads;      두 지역을 왕복할 수 있는 길 정보
	vector<int> sources;            각 부대원이 위치한 서로 다른 지역들을 나타내는 정수 배열
    int destination;                강철부대의 지역
*/
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
	queue<pair<int, int>> q;

	// 각 지역의 최단 거리
	vector<int> dist(n + 1, -1); 

	q.push({ destination, 0 });
	dist[destination] = 0;

	while (!q.empty()) {
		int current = q.front().first;
		int currentDist = q.front().second;
		q.pop();
        
		for (auto road : roads) {
			int next = -1;
			if (road[0] == current)
				next = road[1];
			else if (road[1] == current)
				next = road[0];

			if (next != -1 && dist[next] == -1) {
				dist[next] = currentDist + 1;
				q.push({ next, dist[next] });
			}
		}
	}

	for (int source : sources)
		answer.push_back(dist[source]);

    return answer;
}

vector<int> solution1(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
	vector<int> answer;	
	queue<pair<int, int>> q;
	vector<int> dist(n + 1, -1);

	// roads를 양방향 그래프로 변환
	vector<vector<int>> graph(n + 1);
	for (const auto& road : roads) {
		graph[road[0]].push_back(road[1]);
		graph[road[1]].push_back(road[0]);
	}

	q.push({ destination, 0 });
	dist[destination] = 0;

	while (!q.empty()) {
		int current = q.front().first;
		int currentDist = q.front().second;
		q.pop();

		for (int next : graph[current]) {
			if (dist[next] == -1) {
				dist[next] = currentDist + 1;
				q.push({ next, dist[next] });
			}
		}
	}

	for (int source : sources)
		answer.push_back(dist[source]);

	return answer;
}


// 1차 시도 : 실패, 테스트 케이스 11 ~ 16 시간 초과로 실패

// 2차 시도 : 성공, BFS를 이용하여 최단 거리 계산, 양방향 그래프로 변환하여
// 반복해야하는 부분을 줄여 시간 초과 문제 해결.