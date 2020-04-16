#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int wine[10001] = { 0, };
	int total[10001] = { 0, };

	// ������ ���� ��
	int count;
	cin >> count;

	// ���� �� �Է�
	for (int i = 1; i <= count; i++)
		cin >> wine[i];

	total[1] = wine[0] + wine[1];
	total[2] = wine[1] + wine[2];

	// ������ �ѷ����ϱ� �޸������̼� ���
	for (int i = 3; i <= count; i++)
		total[i] = max(total[i - 1], max(total[i - 2] + wine[i], total[i - 3] + wine[i - 1] + wine[i]));

	cout << total[count];

	return 0;
}

/*
���̳��� ���α׷��� = ���� ��ȹ�� �˰��� ����
-> ���� ���� ��ȹ���� �� ���Ѱ� ����. Ǫ�µ� �ʹ� �����ɸ�;

������ ã�Ƽ� ��ȭ���� ����°� ������ �ذ��ϴ� ���� �������ΰ� ����.

 : 6 10 13 9 8 1

[0] = 0;
[1] = 6;
[2] = 10;

[3] = ([0] + [1] + [3]), ([0] + [2] + [3]), ([1] + [2]) : ���߿� ���� ū ���� [3]�� ���̴�.
([1] + [2]) : �� �����ؼ� 3�� �Ұ����ϹǷ� [3] ������
*/