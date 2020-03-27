#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());
	long long max_time = (long long)times.back() * n, min_time = 1, mid_time;
	long long answer = max_time;
	long long count;

	while (min_time <= max_time)
	{
		mid_time = (max_time + min_time) / 2;
		count = 0;

		for (int i = 0; i < times.size(); i++)
			count += mid_time / times[i];

		// �ο� �� ���� (�ð� �ּ� �� �̵�)
		if (count < n)
			min_time = mid_time + 1;
		// ���� (�ð� �ּ� �� ã��)
		else
		{
			if (answer >= mid_time)
				answer = mid_time;
			max_time = mid_time - 1;
		}
	}

	return answer;
}


/*
���α׷��ӽ����� �̺�Ž������ �з��� �ִ� Level 3 �����̴�.
�� ������ �̺�Ž������ �����ϱⰡ �������� �������.

for (int i = 0; i < times.size(); i++)
	count += mid_time / times[i];

�� ������ ������ �ذ�ƴ�.

�ּҷ� �ɸ��� �ð� 1��
�ִ�� �ɸ��� �ð��� �ɻ���� ���� ���� �ɸ��� ����� ����

ex ) ����� �� 6�� , �ɻ�� 2�� ( 7��, 10�� )

�ּ� = 1��, �ִ� 10��*6�� = 60��
�߾� = (60 + 1) / 2 => 30��
-30���� �ҿ�� ��� �� ��� ������ �ο� 7�� (���)

�����ϹǷ� �ִ� ���� �߾Ӱ����� �����ϸ鼭 �� ���� �ð����� �������� ã��
�ּ� = 1��, �ִ� 29��
�߾� = (29 + 1) / 2 => 15��
-15���� �ҿ�� ��� �� ��� ������ �ο� 3�� (����)

�����ϹǷ� �ּҰ��� �߾Ӱ����� �����Ͽ� �� �̻��� �ð����� ã�´�.

���� ������ �ݺ��ϸ鼭 ������ �ð��� �߿� ���� answer�� ������ ���� �ð��� ã�� �����Ѵ�.

*/