#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int N) {
	long long answer = 0;

	long long arr[80] = { 1, 1, };

	for (int i = 2; i < N; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	if (N != 1)
		answer = ((arr[N - 2] + arr[N - 1]) * 2) + (arr[N - 1] * 2);
	else
		answer = 4;

	return answer;
}

// 이게 대체 왜 3레벨?