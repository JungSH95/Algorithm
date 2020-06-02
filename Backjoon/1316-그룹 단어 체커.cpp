#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// N : �ܾ��� ����
int N, group_count = 0;
int alphabet_count[26];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		memset(alphabet_count, 0, sizeof(alphabet_count));
		string s;
		cin >> s;

		char now_c = s[0];
		alphabet_count[(int)(now_c - 'a')] += 1;
		bool check = true;

		for (int j = 1; j < s.length(); j++)
		{
			// ���� ���ڿ� ����
			if (now_c == s[j])
				continue;
			else
			{
				// ���ڰ� �ٸ��� �ش� ���ڰ� �̹� ����� ���� �ִ��� üũ
				if (alphabet_count[(int)(s[j] - 'a')] != 0)
				{
					// ����ߴٴ� ���̹Ƿ� �׷� �ܾ �ƴ�.
					check = false;
					break;
				}
				else
				{
					// ����� ���� ����, ���� ������� ���ڷ� ����, ����ߴٴ� ǥ��
					now_c = s[j];
					alphabet_count[(int)(now_c - 'a')] += 1;
				}
			}
		}

		if (check)
			group_count++;
	}

	cout << group_count;

	return 0;
}

/*
�� ó���� ���͸� ����ؼ� ����� ���ڿ� ���ؼ� �ִ��� ã�Ƽ� üũ�� �ұ� �ߴµ�
3�� �ݺ����� �Ǳ⶧���� �ٸ� ������� �迭�� ����ؼ� Ǯ����.

���ĺ��� �� 26���̹Ƿ� 26 ũ���� �迭�� ������ְ�, 'a' ���ڸ� ���� �ش� ���ڸ�
�迭�μ� �����Ͽ� ī��Ʈ�� ���Ѽ� ��� ������ üũ���־���.
*/
