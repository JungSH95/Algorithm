#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
	int answer = 0;

	for (int i = 1; i < s.length() - 1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// ������ ���� �Ѿ���� �׸�
			if (i + j >= s.length())
				break;

			// ������?
			if (s[i - j] == s[i + j])
			{
				int len = (j * 2) + 1;
				if (answer <= len)
					answer = len;
			}
			// ���������� ��
			else
				break;
		}
	}

	return answer;
}

/*
1�� �õ� 
�׽�Ʈ 4,6,7,12,17,18 / ȿ���� 1 ����
-> ��û�ߴ� ¦���� ��� ��������
*/


#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
	int answer = 1;

	// Ȧ��
	for (int i = 1; i < s.length() - 1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// ������ ���� �Ѿ���� �׸�
			if (i + j >= s.length())
				break;

			// ������?
			if (s[i - j] == s[i + j])
			{
				int len = (j * 2) + 1;
				if (answer <= len)
					answer = len;
			}
			// ���������� ��
			else
				break;
		}
	}

	// ¦��
	for (int i = 1; i < s.length() - 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << i + j << " " << i - j - 1 << endl;

			// ������?
			if (s[i - j - 1] == s[i + j])
			{
				int len = ((j + 1) * 2);
				if (answer <= len)
					answer = len;
				cout << " Len : " << len << endl;
			}
			// ���������� ��
			else
				break;
		}
	}

	return answer;
}

/*
2�� �õ�
¦���� ��� �߰�
�׽�Ʈ 17, 18�� ����
-> ���� 1�� ��츦 üũ ����;
-> answer = 1�� �ʱ�ȭ �ؼ� �ذ�
*/