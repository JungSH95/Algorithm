#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> order) 
{
    int answer = 0;

    // 보조 컨테이너
	stack<int> station;
    
    for (int i = 1; i <= order.size(); i++) 
    {
		// 현재 상자가 트럭에 실어야 하는 순서
        if (i == order[answer])
			answer++;
		else
			station.push(i);

		// 보조 컨테이너에 있는 상자들 중에서 트럭에 실어야 하는 순서가 있다면
        while (!station.empty() && station.top() == order[answer]) 
        {
            station.pop();
            answer++;
		}

        if (order[answer] < i)
            break;
	}

    return answer;
}

// 다른 사람의 깔끔한 풀이
int other_solution(vector<int> order) 
{
    int answer = 0;
    stack<int> s;

    for (int i = 1; i <= order.size(); i++) 
    {
        s.push(i);

        while (!s.empty() && s.top() == order[answer]) 
        {
            s.pop();
            answer++;
        }
    }

    return answer;
}

// 1차 시도 : 성공, 문제 자체에 대놓고 스택 사용하라고 적혀 있었지만
// 너무 쓸데 없이 설명이 들어가 있어서 이해가 오히려 안됐던 문제