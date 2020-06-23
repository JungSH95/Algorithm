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

		// �Ҽ� ���ϱ�
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
����Ʈ�� ���� : ������ �ڿ��� n�� ���Ͽ� n���� ũ�� 2n ���� �۰ų� ���� �Ҽ��� ����
���Ѵ� ������.

�ð��� ���� 1��

n�� ���� ū ���� 123456�϶� 123457 ~ 246912������ ����

������ Ȯ���ϸ� �ӵ��� ������ ������?

�׷��� ���� �׳� �ƿ� 1���� ���� ū ������ �Ҽ����� �ƴ��� �̸� �Ǻ��� �ϰ�
�Ҽ��� ������ ī��Ʈ�ϵ��� �������.

�Ҽ��� �Ǻ��ϴ� ���� �б����� �Ҽ����ϴ� ������ Ǯ������ ����� ����� ����ߴ�.

2���� �����ؼ� 2�� ����� ���� ����, 3�� ��� ����, 4�� ��� ����
�ؼ� �ᱹ ���� �͵��� �Ҽ��� �ȴ�.
*/