#include <string>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;

	long long max = 0, min = M / budgets.size(), mid;
	long long max_value = 0;
	for (int i = 0; i < budgets.size(); i++)
	{
		max += budgets[i];
		if (max_value <= budgets[i])
			max_value = budgets[i];
	}

	// �� ���� ������ �ѱ��� ���� ��� ��
	if (max <= M)
		return max_value;

	max = max_value;

	while (min <= max)
	{
		mid = (max + min) / 2;

		// ���� Ȯ�� ���ϴ��� �����ϸ� �н�
		if (mid * budgets.size() <= M)
		{
			min = mid + 1;
			answer = mid;
			continue;
		}
		// ���� ��û Ȯ��
		else
		{
			long long sum = 0;
			// ���� ���
			for (int i = 0; i < budgets.size(); i++)
			{
				if (budgets[i] < mid)
					sum += budgets[i];
				else
					sum += mid;
			}

			// ������ ���� ��û
			if (sum <= M)
			{
				min = mid + 1;
				answer = mid;
			}
			// �Ұ����� ���� ��û
			else
				max = mid - 1;
		}
	}

	return answer;
}


/*
19�� �ܿ� ���� īī�� -> 20�� īī�����Ͻ� �ڵ� �׽�Ʈ ���� ���ǰ�縦 �ϰ� �ͼ� �׷���
Level 3 ġ��� �� ���� ��������.

�̺�Ž���̶�� ī�װ��� ������ �־ �׷� �� ���⵵ �ϴ�.
*/