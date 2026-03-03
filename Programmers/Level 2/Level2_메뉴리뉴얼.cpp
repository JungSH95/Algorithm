#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

map<string, int> maps;
void DFS(int len, int s, string menus, string order, vector<bool>& visit) {
    if (len == menus.length()) {
        maps[menus]++;
        return;
    }

    if (menus.length() >= 2) {
        maps[menus]++;
    }

    for (int i = s; i < order.length(); i++) {
        if (visit[i])
            continue;

        visit[i] = true;
        DFS(len, i + 1, menus + order[i], order, visit);
        visit[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 1. 조합을 만든다.  +  3. 체크된 것들 중 COURSE와 길이가 같은 것들 확인
    // => 길이가 COURSE에 맞는 조합을 만든다.
    // 2. 해당 조합이 ORDERS에 포함된 경우가 2개 이상인 경우 체크
    // 4. 길이가 같은 것들 중 가장 많이 포함된 것들을 ANSWER에 추가

    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    for (auto order : orders) {
        vector<bool> visit(orders.size(), false);
        DFS(course[course.size() - 1], 0, "", order, visit);
    }

    for (int i = 0; i < course.size(); i++) {
        int maxCount = 0;
        for (auto m : maps) {
            if (m.first.length() == course[i] && m.second >= 2)
                maxCount = max(maxCount, m.second);
        }

        for (auto m : maps) {
            if (maxCount == m.second && m.first.length() == course[i])
                answer.push_back(m.first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

// 1차 시도 : 성공, 시간이 너무 오래걸림. Level2 인것치고 어렵게 느껴짐