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
�� �� A, B�� �־����� �� ���� ������ ����� ū ���� ����ϴ� ������ ����
���� int�� ���ڸ� �о� �ش� ������ ������ ReverseNumber() �Լ��� ����Ͽ� ���߽��ϴ�.

�ٸ� ������� Ǯ�̸� ������ ��� ����� string���� �о� �ں��� ������ Ȯ���� �ϴ� ����� ������,
���� ����� ����� ����Ͽ� �˰����� �ۼ��� ����� ���ҽ��ϴ�.
*/