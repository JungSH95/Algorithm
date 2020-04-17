#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[301] = { 0, }, total[301] = { 0, };
	int cnt;

	cin >> cnt;
	for (int i = 1; i <= cnt; i++)
		cin >> arr[i];

	total[1] = arr[1]; // 첫 번째 계단일 경우 최대값
	total[2] = arr[1] + arr[2]; // 두 번째 계단일 경우 최대값 : 첫 번째 + 두 번째
	total[3] = max(arr[1] + arr[3], arr[2] + arr[3]);    // 세 번째 계단일 경우 : 연속 3개 불가능

	// 마지막 계단을 밟았을 경우 생각해야한다.
	for (int i = 4; i <= cnt; i++)
		total[i] = max(arr[i] + arr[i - 1] + total[i - 3], arr[i] + total[i - 2]);

	cout << total[cnt];
	return 0;
}


/*
다이나믹 프로그래밍 = 동적 계획법 알고리즘 문제

바로 패턴 찾기 시작 포도주 시식 문제와 비슷함
단지 제한 조건인 마지막 계단을 밟아야 할 것

마지막 계단을 밟았을 경우 2가지 경우의 수
계[n] + 계[n - 1] + 이전계단 n - 3 가능		마지막 계단과 그 전 계단 밟을 경우 한번 건너 뛰어야함
계[n] + 이전계단 n - 2 가능					마지막 계단밟고 그 전 계단 안밟을 경우 상관 없음
*/