#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> number;

	// 각 자리수 합 더하기
	while (N)
	{
		number.push_back(N % 10);
		N /= 10;
	}

	sort(number.begin(), number.end(), greater<>());
	for (int i = 0; i < number.size(); i++)
		cout << number[i];

	return 0;
}


/*
오늘은 컨디션이 좋지않아 직관적으로 간단하게 바로 풀 수 있는 문제로 머리를 풀었다.
숫자를 입력 받으면 그 숫자를 내림 차순으로 다시 출력하는 문제다.

나는 각 자리 수로 분해 시켜 벡터에 값을 넣어 저장해두고 정렬 함수인 sort() 사용하여
내림차순으로 정렬하였다.
*/
