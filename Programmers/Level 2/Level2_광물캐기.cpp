#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int min_fatigue = 987654321;

int dfs(vector<int> picks, vector<string> minerals, int pickLevel, int fatigue)
{
    // 5번 캐기(남은 광물)
    if (pickLevel != 0)
    {
        int count = 0;
        for (int i = 0; i < 5 && i < minerals.size(); i++)
        {
            if (pickLevel == 1)
                fatigue += 1;
            else if (pickLevel == 2)
            {
                if (minerals[i] == "diamond")
                    fatigue += 5;
                else
                    fatigue += 1;
            }
            else if (pickLevel == 3)
            {
                if (minerals[i] == "diamond")
                    fatigue += 25;
                else if (minerals[i] == "iron")
                    fatigue += 5;
                else
                    fatigue += 1;
            }
            count += 1;
        }

        picks[pickLevel - 1] -= 1;
        minerals.erase(minerals.begin(), minerals.begin() + count);
    }

    int pickCount = 0;
    for (int i = 0; i < picks.size(); i++)
        pickCount += picks[i];

    // 곡갱이 전부 소진
    if (pickCount == 0 && fatigue < min_fatigue)
    {
        min_fatigue = min(fatigue, min_fatigue);
        return min_fatigue;
    }

    // 이미 얻은 최솟값보다 크다면 종료
    if (fatigue >= min_fatigue)
        return fatigue;

    for (int i = 0; i < picks.size(); i++)
    {
        if (picks[i] > 0 && fatigue < min_fatigue)
            dfs(picks, minerals, i + 1, fatigue);
    }

    return min_fatigue;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = dfs(picks, minerals, 0, 0);
    return answer;
}


// 1차 시도 : 성공, 시간 초과를 걱정했으나 기본적으로 가장 효율이 좋은 다이아부터 시작해서 min 값을 얻으려는 과정이다보니
// DFS이지만 많이 돌아가지 않아 시간 초과가 발생안함

// 추가로 빼먹은 부분이 있는데 곡갱이 소진뿐만 아니라 광물을 전부 캤을 때의 종료 조건이 빠진것을 이 글을 작성하면서 확인함.
