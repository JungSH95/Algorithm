#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int maxCount = 0;

void dfs(int k, vector<vector<int>> dungeons, int count) 
{
	maxCount = max(maxCount, count);

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (k >= dungeons[i][0])
        {
            int nextK = k - dungeons[i][1];
            vector<vector<int>> nextDungeons = dungeons;
            nextDungeons.erase(nextDungeons.begin() + i);
			dfs(nextK, nextDungeons, count + 1);
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
	dfs(k, dungeons, 0);
    return maxCount;
}

// 1차 시도 : 성공, 문제 항목이 완전탐색으로 분류된 문제라 생각하기 쉬웠던 문제