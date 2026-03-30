#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;

	vector<bool> visited(cards.size(), false);
	vector<int> groupSizes;

	for (int i = 0; i < cards.size(); i++) {
        if (visited[i])
            continue;

		int count = 0;
        int current = i;
        while (!visited[current])
        {
            visited[current] = true;
            current = cards[current] - 1;
            count++;
        }

        if (count >= 1)
            groupSizes.push_back(count);
    }

    if (groupSizes.size() < 2)
		return 0;

	sort(groupSizes.begin(), groupSizes.end(), greater<int>());
	answer = groupSizes[0] * groupSizes[1];
    return answer;
}

// 1차 시도 : 성공
