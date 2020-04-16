#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int wine[10001] = { 0, };
	int total[10001] = { 0, };

	// 포도주 잔의 수
	int count;
	cin >> count;

	// 와인 양 입력
	for (int i = 1; i <= count; i++)
		cin >> wine[i];

	total[1] = wine[0] + wine[1];
	total[2] = wine[1] + wine[2];

	// 와인의 총량구하기 메모이제이션 기법
	for (int i = 3; i <= count; i++)
		total[i] = max(total[i - 1], max(total[i - 2] + wine[i], total[i - 3] + wine[i - 1] + wine[i]));

	cout << total[count];

	return 0;
}

/*
다이나믹 프로그래밍 = 동적 계획법 알고리즘 문제
-> 내가 동적 계획법에 좀 약한거 같다. 푸는데 너무 오래걸림;

패턴을 찾아서 점화식을 세우는게 문제를 해결하는 빠른 지름길인것 같다.

 : 6 10 13 9 8 1

[0] = 0;
[1] = 6;
[2] = 10;

[3] = ([0] + [1] + [3]), ([0] + [2] + [3]), ([1] + [2]) : 이중에 가장 큰 값이 [3]의 값이다.
([1] + [2]) : 는 연속해서 3잔 불가능하므로 [3] 못더함
*/