#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int len = number.size() - k;

	for (int i = 0; i < len; i++)
	{
		char max = '0';
		int max_pos = -1;

		// ������ answer�� ����
		for (int j = 0; j < k + 1; j++)
		{
			if (max < number[j])
			{
				max = number[j];
				max_pos = j;
			}
		}

		// �տ��� ���ŵ� �� ��ŭ ����
		k -= max_pos;
		answer += max;
		number = number.substr(max_pos + 1);
	}

	return answer;
}

// �������...