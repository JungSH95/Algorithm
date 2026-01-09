#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());
	long long max_time = (long long)times.back() * n, min_time = 1, mid_time;
	long long answer = max_time;
	long long count;

	while (min_time <= max_time)
	{
		mid_time = (max_time + min_time) / 2;
		count = 0;

		for (int i = 0; i < times.size(); i++)
			count += mid_time / times[i];

		// 인원 수 부족 (시간 최소 값 이동)
		if (count < n)
			min_time = mid_time + 1;
		// 가능 (시간 최소 값 찾기)
		else
		{
			if (answer >= mid_time)
				answer = mid_time;
			max_time = mid_time - 1;
		}
	}

	return answer;
}


/*
프로그래머스에서 이분탐색으로 분류돼 있는 Level 3 문제이다.
이 문제를 이분탐색으로 접근하기가 생각보다 어려웠다.

for (int i = 0; i < times.size(); i++)
	count += mid_time / times[i];

이 간단한 식으로 해결됐다.

최소로 걸리는 시간 1분
최대로 걸리는 시간은 심사원중 가장 오래 걸리는 사람을 기준

ex ) 대기자 수 6명 , 심사원 2명 ( 7분, 10분 )

최소 = 1분, 최대 10분*6명 = 60분
중앙 = (60 + 1) / 2 => 30분
-30분이 소요될 경우 총 통과 가능한 인원 7명 (충분)

가능하므로 최대 값을 중앙값으로 변경하면서 더 적은 시간으로 가능한지 찾기
최소 = 1분, 최대 29분
중앙 = (29 + 1) / 2 => 15분
-15분이 소요될 경우 총 통과 가능한 인원 3명 (부족)

부족하므로 최소값을 중앙값으로 변경하여 그 이상의 시간으로 찾는다.

위의 과정을 반복하면서 가능한 시간들 중에 현재 answer의 값보다 작은 시간을 찾아 대입한다.

*/