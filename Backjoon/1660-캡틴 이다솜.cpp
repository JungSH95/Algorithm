#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main()
{
	cin >> N;

	// �� ���ü�� �ʿ��� �� ���ϱ�
	int temp = 1, total = temp;
	vector<int> tetrahedron;
	tetrahedron.push_back(total);

	// �������� �ִ� ���� 300000
	while (temp++)
	{
		total += temp * (temp + 1) / 2;
		if (total > 300000)
			break;
		tetrahedron.push_back(total);
	}

	// źȯ�� �� ��ŭ ũ�� ����
	vector<int> minSize;
	minSize.resize(300001);
	for (int i = 1; i < 300001; i++)
		minSize[i] = 300001;

	// �ѹ��� ���� �� �ִ� ���ü���� 1�� ����
	for (int i = 0; i < tetrahedron.size(); i++)
		minSize[tetrahedron[i]] = 1;

	// minSize[j - tetrahedron[i]] �ݺ����� ���ؼ� �� źȯ�� ���� ���� �� �ִ�
	// ���ü�� �ּ� ������ �־��ش�.
	for (int i = 0; i < tetrahedron.size(); i++)
		for (int j = tetrahedron[i]; j <= N; j++)
			minSize[j] = min(minSize[j], minSize[j - tetrahedron[i]] + 1);

	cout << minSize[N];

	return 0;
}

/*
15 : 10, 4, 1 => 3��

�� �� �� �ʿ��� ���� 1, 3, 6, 10, 15
=> ���� 2, 3, 4, 5, 6 ~~~~ ==> n*(n+1) / 2
N ���ü : 1, 4, 10, 20

�ּҶ� �ܼ��� ���� ū ������ ������ ������ �Ұ���
50�� ��� ���� ū ������ �Ѵٸ� 35, 10, 4, 1 �� 4��
�ٸ� ������� �Ѵٸ� 20, 20, 10 ���� 3���� �����ش�

��� Ǯ��� �ð� �ʰ��� �ȳ��� Ǯ �� ������ �ᱹ ����
�Ʒ� ��ũ�� Ǯ�̸� ����ߴ�.
https://ksh-code.tistory.com/106

źȯ�� �� ��ŭ�� ���͸� �������־� �ش� �迭�� ������ źȯ�� ����ϴ� ���� ���
1������ ���� �� �ֱ� ������ �ش� ���� 1�� ���� �־��ش�.

minSize�� źȯ�� ���� tetrahedron[i] �� ���ü�� �ʿ��� źȯ�� ���� �� �ֱ� ������
minSize[j - tetrahedron[i]]�� ���ϸ鼭 ���� ������ �־��ָ� �ش� źȯ�� ����
���� �� �ִ� ���ü�� �ּ� ���� ���� �ȴ�.
*/
