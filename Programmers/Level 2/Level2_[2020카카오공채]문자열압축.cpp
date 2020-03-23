#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
	int answer = 10000;

	if (s.size() <= 1)
		return s.size();

	for (int i = 1; i <= (s.size() / 2); i++)
	{
		string sResult = "";
		int count = 0;

		for (int j = 0; j < s.size(); j += i)
		{
			// ���� ���ڿ� �ٿ��ְ�
			if (j + i >= s.size())
			{
				if (count == 0)
					sResult += s.substr(j, i);
				else
					sResult += (to_string(count + 1) + s.substr(j, i));
				break;
			}

			// ������ ī��Ʈ ����
			if (s.compare(j, i, s, j + i, i) == 0)
				count++;
			// �ٸ��� ī��Ʈ�� 0�̸� �׳� ���̰� 1�̻��̸� ���ڷ�(+1)
			else
			{
				if (count == 0)
					sResult += s.substr(j, i);
				else
					sResult += (to_string(count + 1) + s.substr(j, i));
				count = 0;
			}
		}

		if (answer >= sResult.size())
			answer = sResult.size();
	}

	return answer;
}

void main()
{
	solution("aabbaccc");
	return;
}