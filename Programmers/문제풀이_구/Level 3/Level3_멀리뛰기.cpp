#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	long long answer = 0;

	long long arr[2000];
	arr[0] = 1;
	arr[1] = 2;

	for (int i = 2; i < n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1234567;
	answer = arr[n - 1];

	return answer;
}

/*
이것도 3레벨인 이유 모르겠음
1 -> 1
2 -> 2
3 -> 3
4 -> 5
5 -> 8
=> 피보나치
*/