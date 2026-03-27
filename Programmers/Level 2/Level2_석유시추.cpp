#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs(int areanumber, int x, int y, vector<vector<int>> &land, vector<vector<bool>>& visited, map<int, int> &area) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[y][x] = true;

    land[y][x] = areanumber;

    int oilCount = 1;
    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= visited[0].size() || next_y >= visited.size())
                continue;

            if (visited[next_y][next_x] == false && land[next_y][next_x] != 0) {
                oilCount += 1;
                visited[next_y][next_x] = true;
                q.push(make_pair(next_x, next_y));

                land[next_y][next_x] = areanumber;
            }                
        }        
    }

    area[areanumber] = oilCount;
    return oilCount;
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));

    map<int, int> area;
    
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            if (visited[i][j] == false && land[i][j] != 0)
                bfs(area.size() + 1, j, i, land, visited, area);
        }
    }

    vector<bool> areaVisted(area.size() + 1, false);

    // 수직으로
    for (int i = 0; i < land[0].size(); i++) {
        int totalOil = 0;
        for (int j = 0; j < land.size(); j++) {
            if (land[j][i] != 0 && areaVisted[land[j][i]] == false) {
                totalOil += area[land[j][i]];
                areaVisted[land[j][i]] = true;
            }
        }

        answer = max(answer, totalOil);

        for (int j = 0; j < areaVisted.size(); j++)
            areaVisted[j] = false;
    }

    return answer;
}

// 1차 시도 : 성공, 살짝 머리를 써야했던 문제. 각 구역에 번호를 매기는 방식을 사용
