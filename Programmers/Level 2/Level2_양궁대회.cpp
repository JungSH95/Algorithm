#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int maxDiff = -1;
vector<int> lionResult(11, 0);

void dfs(int n, vector<int> info, vector<int> temp, int index)
{
    // 남은 화살 처리
    if (index >= 11)
    {
		temp[10] += n;
        n = 0;
    }

    if (n == 0)
    {
        int lionScore = 0;
        int apeachScore = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (info[i] < temp[i])
                lionScore += (10 - i);
            else if (info[i] > 0)
                apeachScore += (10 - i);
        }

        int diff = lionScore - apeachScore;
        if (diff > maxDiff)
        {
            maxDiff = diff;
            lionResult = temp;
        }
        else if (diff == maxDiff)
        {
            for (int i = 10; i >= 0; i--)
            {
                if (temp[i] > lionResult[i])
                {
                    lionResult = temp;
                    break;
                }
                else if (temp[i] < lionResult[i])
                    break;
            }
        }
		
        return;
    }
	else if (n < 0)
        return;

    // 선택하는 경우
    if (n > info[index])
    {
        temp[index] = info[index] + 1;
        dfs(n - (info[index] + 1), info, temp, index + 1);
        temp[index] = 0;
    }

    // 선택하지 않는 경우
    dfs(n, info, temp, index + 1);
}

vector<int> solution(int n, vector<int> info) {
	vector<int> temp(11, 0);
	dfs(n, info, temp, 0);

    if (maxDiff <= 0)
		return { -1 };

    return lionResult;
}

// 1차 시도 : 성공, 문제 풀이 시간이 좀 오래 걸림, 재미있었던 문제