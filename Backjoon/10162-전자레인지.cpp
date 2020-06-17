#include <iostream>
using namespace std;

int T;

int main()
{
	cin >> T;

	int A = T / 300;
	T %= 300;
	int B = T / 60;
	T %= 60;
	int C = T / 10;
	T %= 10;

	if (T != 0)
		cout << -1;
	else
		cout << A << " " << B << " " << C;

	return 0;
}

/*
머리 휴식 - 이론공부하자 오늘은
*/