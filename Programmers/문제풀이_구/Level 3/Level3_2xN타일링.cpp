#include <string>
#include <vector>
using namespace std;

int solution(int n) {
	int answer = 0;
	int arr[60000] = { 1, 2, };

	if (n <= 2)
		return arr[n - 1];

	for (int i = 2; i < n; i++)
		arr[i] = (arr[i - 2] + arr[i - 1]) % 1000000007;

	answer = arr[n - 1];
	return answer;
}

// 패턴 찾으니 단순한 문제 피보나치