#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 246912

int N;
bool primeNumberArr[MAX];

void primenumbercheck()
{
	for (int i = 2; i < MAX; i++)
	{
		if (primeNumberArr[i] == false)
		{
			for (int j = i * 2; j < MAX; j += i)
				primeNumberArr[j] = true;
		}
	}
}

int main()
{
	primenumbercheck();

	while (true)
	{
		cin >> N;
		if (N == 0)
			break;

		int count = 0;

		// 소수 구하기
		for (int i = N + 1; i <= 2 * N; i++)
		{
			if (primeNumberArr[i] == false)
				count += 1;
		}

		cout << count << endl;
	}

	return 0;
}

/*
베르트랑 공준 : 임의의 자연수 n에 대하여 n보다 크고 2n 보다 작거나 같은 소수의 수를
구한느 문제다.

시간초 제한 1초

n의 가장 큰 값은 123456일때 123457 ~ 246912까지의 범위

일일이 확인하면 속도가 느리지 않을까?

그래서 나는 그냥 아예 1부터 가장 큰 값까지 소수인지 아닌지 미리 판별을 하고
소수의 개수만 카운트하도록 만들었다.

소수를 판별하는 법은 학교에서 소수구하는 문제를 풀었을때 배웠던 방법을 사용했다.

2부터 시작해서 2의 배수를 전부 제외, 3의 배수 제외, 4의 배수 제외
해서 결국 남은 것들은 소수가 된다.
*/