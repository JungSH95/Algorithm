#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

	map<int, int> leftTopping;
	map<int, int> rightTopping;

	// 초기에는 모든 토핑이 오른쪽에 있다고 가정
	for (int t : topping)
		rightTopping[t]++;

	// 왼쪽과 오른쪽의 토핑 종류 수를 비교하면서 이동
	for (int t : topping) 
	{
		// 현재 토핑을 왼쪽으로 이동
		leftTopping[t]++;
		rightTopping[t]--;

		// 오른쪽에서 해당 토핑이 더 이상 없으면 제거
		if (rightTopping[t] == 0)
			rightTopping.erase(t);

		// 왼쪽과 오른쪽의 토핑 종류 수가 같으면 공평하게 나누어진 것
		if (leftTopping.size() == rightTopping.size())
			answer++;
	}

    return answer;
}

// 1차 시도 : 성공
