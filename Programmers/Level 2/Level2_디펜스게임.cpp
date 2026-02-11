#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

/*
* 병사 수 : n
* 무적권 수 : k
* 적군 배열 : enemy
*/
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    // 무적권의 수가 더 많은 경우
	if (k >= enemy.size())
        return enemy.size();

	// 최소 힙 사용해서 무적권 사용할 애들 고르기
	priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < enemy.size(); i++)
    {
        pq.push(enemy[i]);

        if (pq.size() > k)
        {
			int tmp = pq.top();
			pq.pop();
			n -= tmp;
			if (n < 0)
				return i;
        }

		answer++;
    }

    return answer;
}

// 1차 시도 : 실패, 테스트 7 ~ 9번

// 2차 시도 : 성공, total_enemy를 확인하여 병사 수 보다 적다면 바로 리턴하도록 했는데
// 찾아보니 판정 오류라고들 한다. 이부분을 제거하니까 통과 된다.