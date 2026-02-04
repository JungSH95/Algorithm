#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

/*
    int cap;                    // 가지고 있을 수 있는 택배 상자 수
    int n;                      // 집 수
    vector<int> deliveries;     // 배달할 택배 상자
    vector<int> pickups;        // 수거할 택배 상자
*/
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{
    long long answer = 0;

    int trunk_deliveries = 0, trunk_pickups =0;
    int total_deliveries = 0, total_pickups = 0;

    int last_house_deliveries = deliveries.size() - 1, last_house_pickups = pickups.size() - 1;

    for (int i = 0; i < deliveries.size(); i++)
    {
        total_deliveries += deliveries[i];
        total_pickups += pickups[i];
    }

    trunk_deliveries = min(total_deliveries, cap);
    trunk_pickups = cap;

    while (total_deliveries > 0 || total_pickups > 0)
    {
        int max_dist = 0;

        // 1. 배달하고
        for (int i = last_house_deliveries; i >= 0 && total_deliveries > 0; i--)
        {
            if (deliveries[i] != 0 && i + 1 > max_dist)
            {
                max_dist = i + 1;
                last_house_deliveries = i;
            }

            if (deliveries[i] - trunk_deliveries < 0)
            {
                trunk_deliveries -= deliveries[i];
                total_deliveries -= deliveries[i];
                deliveries[i] = 0;
            }
            else
            {
                deliveries[i] -= trunk_deliveries;
                total_deliveries -= trunk_deliveries;
                trunk_deliveries = 0;
                break;
            }
        }

        // 2. 수거하고 반납 + 다시 택배채우고
        for (int i = last_house_pickups; i >= 0 && total_pickups > 0; i--)
        {
            if (pickups[i] != 0 && i + 1 > max_dist)
            {
                max_dist = i + 1;
                last_house_pickups = i;
            }

            if (pickups[i] - trunk_pickups < 0)
            {
                trunk_pickups -= pickups[i];
                total_pickups -= pickups[i];
                pickups[i] = 0;
            }
            else
            {
                pickups[i] -= trunk_pickups;
                total_pickups -= trunk_pickups;
                trunk_pickups = 0;
            }
        }

        answer += max_dist * 2;
        trunk_deliveries = min(total_deliveries, cap);
        trunk_pickups = cap;
    }

    return answer;
}

// 다른 사람들의 풀이중 가장 마음에 들었던 탐욕법을 사용한 풀이, 속도도 압도적으로 빠르다
long long solution1(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;

    int start = -1;
    int idx = -1;
    int give = 0;
    int get = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (deliveries[i] != 0 || pickups[i] != 0)
        {
            // 필요한 방문 수 체크
            int cnt = 0;
            while (give < deliveries[i] || get < pickups[i])
            {
                ++cnt;
                give += cap;
                get += cap;
            }
            give -= deliveries[i];
            get -= pickups[i];
            answer = answer + (long long)((i + 1) * cnt * 2);
        }
    }
    return answer;
}

// 1차 시도 : 실패, 테스트 케이스 16 ~ 18 실패

// 2차 시도 : 성공, 마지막 위치를 기록(last_house_deliveries, last_house_pickups)하도록 수정
