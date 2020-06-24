#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int ReverseNumber(int num)
{
	int result = 0;
	int count = 2;

	while (num % 10 != 0)
	{
		result += (num % 10) * pow(10, count--);
		num /= 10;
	}

	return result;
}

int main()
{
	int A, B;
	cin >> A >> B;
	cout << max(ReverseNumber(A), ReverseNumber(B));
	return 0;
}

/*
두 수 A, B가 주어지면 두 수를 역으로 뒤집어서 큰 값을 출력하는 간단한 문제
저는 int로 숫자를 읽어 해당 숫자의 역순을 ReverseNumber() 함수를 사용하여 구했습니다.

다른 사람들의 풀이를 봤을때 어떠한 사람은 string으로 읽어 뒤부터 읽으며 확인을 하는 사람도 있으며,
저와 비슷한 방식을 사용하여 알고리즘을 작성한 사람도 많았습니다.
*/