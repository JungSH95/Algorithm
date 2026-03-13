#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int maxInfection = 0;

void dfs(int cur, int k, int pipeType, map<int, vector<pair<int, int>>> pipeList, set<int>& infectionList) {
    if (cur == k) {
        maxInfection = max(maxInfection, (int)infectionList.size());
        return;
    }

    // 파이프 동작(1:A, 2:B, 3:C)
    for (int i = 1; i <= 3; i++) {
        if (i == pipeType)
            continue;

        vector<int> backList;
        queue<int> q;

        // 감염 수행
        for (auto infection : infectionList)
            q.push(infection);

        while (!q.empty()) {
            int infection = q.front();
            q.pop();

            // 감염된 배양체를 기준으로 확인 (first : 노드 번호, second : 파이프 타입)
            for (auto next : pipeList[infection]) {
                // 동작을 수행할 파이프가 아니거나 이미 감염된 것이라면 패스
                if (next.second != i || infectionList.find(next.first) != infectionList.end())
                    continue;

                q.push(next.first);
                infectionList.insert(next.first);
                backList.push_back(next.first);
            }
        }

        dfs(cur + 1, k, i, pipeList, infectionList);

        for (auto back : backList)
            infectionList.erase(back);
    }
}

/*
    int n                       : 배양체의 개수
    int infection               : 감염된 배양체의 노드 번호
    vector<vector<int>> edges   : 파이프 {x배양체, y배양체, type} (TYPE => 1 : A, 2 : B, 3 : C)
    int k = 2;                  : 최대 행동 수
 */
int solution(int n, int infection, vector<vector<int>> edges, int k) {
    map<int, vector<pair<int, int>>> pipeList;
    for (auto edge : edges) {
        pipeList[edge[0]].push_back(make_pair(edge[1], edge[2]));
        pipeList[edge[1]].push_back(make_pair(edge[0], edge[2]));
    }

    set<int> infectionList;
    infectionList.insert(infection);
    dfs(0, k, 0, pipeList, infectionList);

    return maxInfection;
}

// 1차 시도 : 성공, 생각이 많이 필요했던 문제, 재미있었음