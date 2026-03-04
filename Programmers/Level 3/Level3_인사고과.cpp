#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

// 근무태도 : 내림차순, 동료평가 : 오름차순
bool workSort(vector<int> a, vector<int>b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;

    map<int, int> m;
    int minScore = scores[0][0] + scores[0][1];
    m[minScore]++;

    vector<vector<int>> tmp_scores;
    for (auto score : scores) {
        // 원호보다 작은 경우
        int totalScore = score[0] + score[1];
        if (minScore > totalScore || (scores[0][0] > score[0] && scores[0][1] > score[1]))
            continue;

        tmp_scores.push_back({score[0], score[1]});
    }

    sort(tmp_scores.begin(), tmp_scores.end(), workSort);

    int max_r = 0;
    for (int i = 0; i < tmp_scores.size(); i++) {
        // 원호가 인센티브를 못받는 경우
        if (scores[0][0] < tmp_scores[i][0] && scores[0][1] < tmp_scores[i][1])
            return -1;

        int totalScore = tmp_scores[i][0] + tmp_scores[i][1];

        // 다른 임의의 사원보다 두 점수가 모두 낮은 경우
        //bool Incentive = true;
        //for (auto score : tmp_scores) {
        //    if (score[0] > tmp_scores[i][0] && score[1] > tmp_scores[i][1]) {
        //        Incentive = false;
        //        break;
        //    }
        //}
        //if (Incentive)
        //    m[totalScore]++;

        if (tmp_scores[i][1] >= max_r) {
            max_r = max(max_r, tmp_scores[i][1]);
            m[totalScore]++;
        }
    }

    // 석차 계산
    for (auto iter = m.rbegin(); iter != m.rend(); iter++) {
        if (scores[0][0] + scores[0][1] == iter->first)
            return answer;

        answer += iter->second;
    }

    return answer;
}

// 1차 시도 : 실패, 테스트 21, 24, 25번 시간 초과

// 2차 시도 : 실패, 원호보다 큰 항목들 중에서 비교하도록 수정했으나 테스트 21, 24번 시간 초과

// 3차 시도 : 성공, 결국 다른 사람의 인센티브 확인하는 방식을 내 코드에 적용함.
/*
        7   1           m = 1
        7   2           m = 2
        5   1           X
        5   2           m = 2
        5   3           m = 3
        4   1           X
        4   3           m = 3
        4   4           m = 4
*/

// 위처럼 "근무태도 : 내림차순, 동료평가 : 오름차순" 정렬 시
// 동료평가만을 확인함으로서 인센티브 받는 유무를 확인할 수 있음