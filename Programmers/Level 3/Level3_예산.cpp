#include <string>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;

	long long max = 0, min = M / budgets.size(), mid;
	long long max_value = 0;
	for (int i = 0; i < budgets.size(); i++)
	{
		max += budgets[i];
		if (max_value <= budgets[i])
			max_value = budgets[i];
	}

	// 총 합이 예산을 넘기지 않을 경우 끝
	if (max <= M)
		return max_value;

	max = max_value;

	while (min <= max)
	{
		mid = (max + min) / 2;

		// 전부 확인 안하더라도 가능하면 패스
		if (mid * budgets.size() <= M)
		{
			min = mid + 1;
			answer = mid;
			continue;
		}
		// 예산 요청 확인
		else
		{
			long long sum = 0;
			// 예산 계산
			for (int i = 0; i < budgets.size(); i++)
			{
				if (budgets[i] < mid)
					sum += budgets[i];
				else
					sum += mid;
			}

			// 가능한 예산 요청
			if (sum <= M)
			{
				min = mid + 1;
				answer = mid;
			}
			// 불가능한 예산 요청
			else
				max = mid - 1;
		}
	}

	return answer;
}


/*
19년 겨울 인턴 카카오 -> 20년 카카오인턴십 코딩 테스트 실전 모의고사를 하고 와서 그런가
Level 3 치고는 좀 쉽게 느껴졌다.

이분탐색이라는 카테고리가 정해져 있어서 그런 것 같기도 하다.
*/