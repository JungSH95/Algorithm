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
������ ��ư� ����ϴٰ� �� Ǯ���� ����� �ִ� ����.

���� �ٽ� Ǯ��� �ʹ� ���� Ǯ�ȴ�.;

1�� �����ڴ� �翬�� �����Ƿ� 1���� �����ؼ� �����ѹ��� �����.
���� ���ڸ� �迭�� üũ�� �� üũ�� ���� ���� ���
*/