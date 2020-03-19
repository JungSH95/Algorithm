#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	// 내림차순 정렬
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] <= i)
			break;
		answer++;
	}
	return answer;
}

/*
문제 이해가 어려웠던 문제, 인용한 수는 중요하지 않음
[1, 18, 19, 20] -> 3

내림 차순으로 정렬 시 : 20, 19, 18, 1

0번 이상 인용된 논문이 4개
1번 이상 인용된 논문이 4개
2번 이상 인용된 논문이 3개
3번 이상 인용된 논문이 2개 -> X

return 3;

*/