#include <iostream>
using namespace std;

int arr[21] = { 0, };

int main()
{
	int N;
	cin >> N;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= N; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[N];

	return 0;
}

/*
DP를 사용하여 문제 해결~
*/