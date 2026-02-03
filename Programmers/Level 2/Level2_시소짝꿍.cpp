#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    // map을 사용하여 중복 제거 및 카운팅
    map<long long, long long> weightMap;
    for (int i = 0; i < weights.size(); i++)
        weightMap[weights[i]] += 1;

    // a == a, 2a == 3b  2a == 4b  3a == 4b
    for (auto iter = weightMap.begin(); iter != weightMap.end(); iter++)
    {
        // 같은 n개중 2개 선택 조합
        if (iter->second > 1)
            answer += (iter->second * (iter->second - 1)) / 2;

        for (auto iter2 = next(iter, 1); iter2 != weightMap.end(); iter2++)
        {
            if (2 * iter->first == 3 * iter2->first || 3 * iter->first == 2 * iter2->first)
                answer += iter->second * iter2->second;
            if (2 * iter->first == 4 * iter2->first || 4 * iter->first == 2 * iter2->first)
                answer += iter->second * iter2->second;
            if (3 * iter->first == 4 * iter2->first || 4 * iter->first == 3 * iter2->first)
                answer += iter->second * iter2->second;
        }
    }

    return answer;
}

// 1차 시도 : 실패, 테스트케이스 12~15

// ㅈㅈ.. 아무리 생각해도 모르겠어서 질문목록 중 나와 동일하게 실패한 사람을 확인해본 결과
// int의 범위값을 벗어나는 문제였다. map<int, int>에서 map<long long, long long> 변경 후 성공
