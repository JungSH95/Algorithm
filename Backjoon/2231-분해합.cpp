#include <iostream>
#include <cstring>
using namespace std;

int main() {

	int N, answer = 0;
	cin >> N;

	// 1부터 분해합 만들기
	for (int i = 1; i < N; i++)
	{
		int sum = i, temp = i;

		// 각 자리수 합 더하기
		while (temp)
		{
			sum += temp % 10;
			temp /= 10;
		}

		// 찾았다면
		if (N == sum)
		{
			answer = i;
			break;
		}
	}

	cout << answer;
	return 0;
}


/*
조금만 생각하면 바로 풀 수 있는 간단한 문제.

테스트 결과 8ms가 나왔다. 시간을 더 줄일 방법이 무엇이 있을까 고민해봤는데
시간을 줄이기 위해서 탐색하는 범위를 줄여야한다. 여기까지의 생각은 좋았으나
범위를 어떻게 줄여야할지에서 막혔다.

나와 비슷한 생각을 한 분이 있어서 보았는데 대단한 것 같다.
https://itadventure.tistory.com/158

예를들어 주어지는 숫자가 123,456이라면 각 자리수는 가장 커봐야 9 + 9 + 9 + 9 + 9 + 9 이다.
그렇다면 생성자는 123,456 - 9*6(자리수) 보다 항상 크거나 같다는 사실을 알 수가 있다.

이 사실을 바탕으로 각 자리수의 최대값을 곱하여 시작점을 조정해준다면 시간을 크게 줄일 수 있다.

for (int i = N - (자리수 * 9); i < N; i++)

*/
