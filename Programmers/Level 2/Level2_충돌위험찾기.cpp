#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

void movePoint(vector<vector<int>> points, vector<int> route, int weight, map<vector<int>, int>& positionTimes) {
    int now_y = points[route[0] - 1][0];
    int now_x = points[route[0] - 1][1];
    int time = 0;

    positionTimes[{time++, now_y, now_x}] += weight;

    for (int i = 1; i < route.size(); i++) {
        int target_y = points[route[i] - 1][0];
        int target_x = points[route[i] - 1][1];

        // y 이동
        while (abs(now_y - target_y) != 0) {
            if (now_y > target_y)
                now_y--;
            else
                now_y++;

            positionTimes[{time++, now_y, now_x}] += weight;
        }

        // x 이동
        while (abs(now_x - target_x) != 0) {
            if (now_x > target_x)
                now_x--;
            else
                now_x++;

            positionTimes[{time++, now_y, now_x}] += weight;
        }
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    // routes의 중복 제거 및 카운팅
    map<vector<int>, int> map_Routes;
    for (auto route : routes)
        map_Routes[route] += 1;

    // map<{초, y, x}, 카운팅>
    map<vector<int>, int> positionTimes;
    for (auto map_Route : map_Routes) {
        movePoint(points, map_Route.first, map_Route.second, positionTimes);
    }

    for (auto positionTime : positionTimes) {
        if (positionTime.second >= 2)
            answer++;
    }

    return answer;
}

// 1차 시도 : 성공
