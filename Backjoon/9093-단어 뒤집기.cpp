#include <iostream>
#include <string>
using namespace std;

int T;

int main()
{
	cin >> T;

	string s;
	getline(cin, s);
	for (int i = 0; i < T; i++)
	{
		getline(cin, s);

		int start_cursor = 0;
		for (int j = 0; j <= s.length(); j++)
		{
			// ������ �����ٸ� �� �ܾ�
			if (s[j] == ' ' || j == s.length())
			{
				// �������� ���
				for (int k = j - 1; k >= start_cursor; k--)
					cout << s[k];
				cout << " ";

				// ���� �ܾ ���� ��ġ��
				start_cursor = j + 1;
			}
		}
		cout << endl;
	}

	return 0;
}


/*
�� ó�� �õ��� �ߴٰ� �����ߴ� ������ ���ۿ� �����ִ� ���๮��.
�������� ���ڿ� ���õ� ó���� �Ϸ��� ����� ������ �ʾҴ�.

https://makedotworld.tistory.com/29

cin�� ���๮�� ������ �д´� -> �� ���ۿ� ���๮�ڰ� �����ִ�.
���ڿ��� �Է¹ޱ� ���� getline(cin, s);�� ���� ��������μ� ���๮�ڸ� �����ϰ�
���ڿ��� �Է¹޾� �� ���ڿ��鿡 ���ؼ� �Ųٷ� ����� ���־���.
*/