#include <iostream>
using namespace std;

int main()
{
	int A, B, C, N;
	cin >> A >> B >> C >> N;

	for (int i = 0; i <= (N / A); i++)
		for (int j = 0; j <= (N / B); j++)
			for (int k = 0; k <= (N / C); k++)
				if (A * i + B * j + C * k == N)
				{
					cout << 1;
					return 0;
				}
	cout << 0;
	return 0;
}

/*
세 자연수의 범위가 작기때문에 전부 체크해도 충분히 가능할 것 같아서
방정식을 만들어서 체크했다.

예제 입력인 5 9 12 113으로 방정식을 만들면
5a + 9b + 12c = 113 이다.

b와 c가 0일경우 a의 가능 범위는 0 ~ 22(113 / 5)
a와 c가 0일경우 b의 가능 범위는 0 ~ 12(113 / 9)
a와 b가 0일경우 c의 가능 범위는 0 ~ 9 (113 / 12)

도중에 가능한 것이 발견되면 종료하는 것으로 끝~
*/
