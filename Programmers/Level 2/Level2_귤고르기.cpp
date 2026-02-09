#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;

    // k개의 귤을 선택
    // 서로 다른 종류의 수의 최솟값
	map<int, int> type_count;
    for (int t : tangerine)
        type_count[t]++;

	vector<int> counts;
    for (auto& pair : type_count) 
		counts.push_back(pair.second);
	sort(counts.rbegin(), counts.rend());

	int total = 0;
	for (int count : counts) 
    {
		total += count;
		answer++;
		if (total >= k) 
            break;
	}

    return answer;
}

// 1차 시도 : 성공
