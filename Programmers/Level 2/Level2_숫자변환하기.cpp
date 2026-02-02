#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int solution(int x, int y, int n) 
{
    int answer = 987654321;

    // 중복확인 방지
    vector<int> checkNumber(1000001, -1);

    queue<pair<int, int>> q;
    q.push(make_pair(x, 0));

    while (!q.empty())
    {
        int number = q.front().first;
        int count = q.front().second;
        //cout << "NUM : " << number << ", COUNT : " << count << ", ::" << q.size() << endl;
        q.pop();

        if (number + n == y || number * 2 == y || number * 3 == y)
            answer = min(count + 1, answer);

        if (number + n < y && checkNumber[number + n] == -1 && count + 1 < answer)
        {
            q.push(make_pair(number + n, count + 1));
            checkNumber[number + n] = 0;
        }
        if (number * 2 < y && checkNumber[number * 2] == -1 && count + 1 < answer)
        {
            q.push(make_pair(number * 2, count + 1));
            checkNumber[number * 2] = 0;
        }
        if (number * 3 < y && checkNumber[number * 3] == -1 && count + 1 < answer)
        {
            q.push(make_pair(number * 3, count + 1));
            checkNumber[number * 3] = 0;
        }
    }

    if (x == y)
        return 0;
    if (answer == 987654321)
        return -1;

    return answer;
}

// 다른사람풀이 DP 사용, 속도 자체는 bfs가 아주 조금 더 빠름
int solution1(int x, int y, int n)
{
    vector<int> dp(1000001, 987654321);

    dp[y] = 0;
    for (int i = y; i > x; i--)
    {
        if (dp[i] != 987654321)
        {
            if (i % 3 == 0)
                dp[i / 3] = min(dp[i / 3], dp[i] + 1);
            if (i % 2 == 0)
                dp[i / 2] = min(dp[i / 2], dp[i] + 1);
            if (i - n > 0)
                dp[i - n] = min(dp[i - n], dp[i] + 1);
        }
    }

    if (dp[x] == 987654321)
        return -1;

    return dp[x];
}

// 1차 시도 : 실패, 테스트 케이스 6번
// 2차 시도 : 성공, 시간을 많이 썼는데, 허무한 테스트 케이스 x가 y랑 같을 때 0
