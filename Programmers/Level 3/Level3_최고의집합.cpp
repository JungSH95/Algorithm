#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	

	// ���� n���� �պ��� s�� ���� ���
	if (n > s)
		answer.push_back(-1);
	else
	{
		int num = s / n;            // ��
		int remainder = s % n;      // ������

		for (int i = 0; i < n; i++)
		{
			if (remainder != 0)
			{
				remainder--;
				answer.push_back(num + 1);
			}
			else
				answer.push_back(num);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}


/*
1�� �õ�
- ȿ���� �׽�Ʈ 6���� ����, 1~5�� ���� ���� �Ф�
*/



#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;

	// ���� n���� �պ��� s�� ���� ���
	if (n > s)
		answer.push_back(-1);
	else
	{
		int num = s / n;            // ��
		int remainder = s % n;      // ������

		for (int i = 0; i < n; i++)
			answer.push_back(num);
		for (int i = answer.size() - 1; i > 0 && remainder != 0; i--)
		{
			answer[i]++;
			remainder--;
		}
	}

	return answer;
}

/*
2���õ� ����
: ������ ���� ������ �°Բ� �ڿ����� ���� ������Ŵ
: �������� sort�� �Ҹ��� ū ������ Ȯ��
*/