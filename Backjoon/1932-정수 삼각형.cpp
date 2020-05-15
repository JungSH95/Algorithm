#include <iostream>
#include <algorithm>
using namespace std;

int N;
int tri_arr[500][500];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> tri_arr[i][j];

	for (int i = 1; i < N; i++)
	{
		tri_arr[i][0] += tri_arr[i - 1][0];
		for (int j = 1; j <= i; j++)
			tri_arr[i][j] += max(tri_arr[i - 1][j - 1], tri_arr[i - 1][j]);
	}

	int max_value = 0;
	for (int i = 0; i < N; i++)
		if (max_value <= tri_arr[N - 1][i])
			max_value = tri_arr[N - 1][i];

	cout << max_value;

	return 0;
}

/*
���� ���� �ڱ� �ڽŰ� ���� �ѹ��� ����ĭ�� ���� ū ���� ���Ͽ� �����Ѵ�.
- [0] �� �׻� [0]���� �������Ƿ� ���� ó����;

�迭���� �Ʒ������� �������鼭 �׻� ū ����� ���� �ȴ�.
*/