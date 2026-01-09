#include<iostream>
using namespace std;

#define MAX 10001

int InitialSelfNumber(int number)
{
	int num = number;

	while (number / 10 != 0)
	{
		num += (number % 10);
		number /= 10;
	}
	num += (number % 10);

	return num;
}

int main()
{
	int selfnumber_Arr[MAX] = { 0, };

	for (int i = 1; i < MAX; i++)
	{
		int num = InitialSelfNumber(i);
		if (num < MAX)
			selfnumber_Arr[num] = 1;
	}

	for (int i = 1; i < MAX; i++)
		if (selfnumber_Arr[i] != 1)
			cout << i << endl;

	return 0;
}

/*
옛날에 어렵게 고민하다가 못 풀었던 기억이 있는 문제.

지금 다시 풀어보니 너무 쉽게 풀렸다.;

1의 생성자는 당연히 없으므로 1부터 시작해서 셀프넘버를 만든다.
만든 숫자를 배열에 체크한 뒤 체크가 없는 숫자 출력
*/