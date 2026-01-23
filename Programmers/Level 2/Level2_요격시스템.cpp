#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int solution(vector<vector<int>> targets)
{
    int answer = 0;
    int endRange = 0;

    sort(targets.begin(), targets.end(), cmp);
    for (int i = 0; i < targets.size(); i++)
    {
        if (targets[i][0] >= endRange)
        {
            answer += 1;
            endRange = targets[i][1];
        }
    }

    return answer;
}

// 1차 시도 : 성공, 끝나는 범위를 기준으로 발사하면 최소 미사일 수가 나오는 간단한 문제