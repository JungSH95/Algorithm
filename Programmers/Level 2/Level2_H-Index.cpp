#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	// �������� ����
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] <= i)
			break;
		answer++;
	}
	return answer;
}

/*
���� ���ذ� ������� ����, �ο��� ���� �߿����� ����
[1, 18, 19, 20] -> 3

���� �������� ���� �� : 20, 19, 18, 1

0�� �̻� �ο�� ���� 4��
1�� �̻� �ο�� ���� 4��
2�� �̻� �ο�� ���� 3��
3�� �̻� �ο�� ���� 2�� -> X

return 3;

*/