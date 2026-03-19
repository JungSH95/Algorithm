#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

bool limitCheck(int level, vector<int> diffs, vector<int> times, long long limit) {
    long long time = 0;
    for (int i = 0; i < diffs.size(); i++) {
        if (level >= diffs[i])
            time += times[i];
        else
            time += (times[i] + times[i - 1]) * (diffs[i] - level) + times[i];

        if (time > limit)
            return false;
    }

    return true;
}

/*
* diffs : 퍼즐의 난이도
* times : 퍼즐의 소요 시간
* limit : 전체 제한 시간
*/
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    int low = 1;
    int high = 0;
    for (auto diff : diffs)
        high = max(high, diff);

    while (low <= high) {
        answer = (low + high) / 2;

        if (limitCheck(answer, diffs, times, limit))
            high = answer - 1;
        else
            low = answer + 1;
    }

    if (limitCheck(answer, diffs, times, limit))
        return answer;
    else if(limitCheck(answer + 1, diffs, times, limit))
        return answer + 1;
}

// 1차 시도 : 테스트 케이스 16, 18 실패, 예상대로 시간 초과 발생

// 2차 시도 : 다 더한거의 절반? 부터 해볼까 싶었는데 그래도 오래 걸릴것 같아서 절반씩 찾도록 이진탐색 사용
