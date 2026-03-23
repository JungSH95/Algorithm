#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>
using namespace std;

/*
* bandage = {시전 시간, 초당 회복량, 추가 회복량}
* health = 최대 체력
* attacks = {공격 시간, 피해량}
*/
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int now_time = 0;
    int max_health = health;

    for (auto attack : attacks) {
        int none_time = (attack[0] - now_time) - 1;
        now_time = attack[0];

        // 회복 처리
        if (none_time >= 1) {
            health += bandage[1] * none_time + (none_time / bandage[0]) * bandage[2];
            health = min(health, max_health);
        }

        // 공격 처리
        if (health - attack[1] <= 0)
            return -1;

        health -= attack[1];
    }

    return health;
}

// 1차 시도 : 성공, 알고리즘 보단 수학에 가까운 문제
