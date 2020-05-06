#include <iostream>
#include <stack>
#include <string>
using namespace std;

void VPS_Check(string s)
{
	stack<char> temp;

	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case '(':
			temp.push(s[i]);
			break;
		case ')':
			if (!temp.empty())
			{
				if (temp.top() == '(')
					temp.pop();
				else
				{
					cout << "NO\n";
					return;
				}
			}
			else
			{
				cout << "NO\n";
				return;
			}
			break;
		}
	}

	if (temp.empty())
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		VPS_Check(s);
	}

	return 0;
}


/*
��ȣ�� �ùٸ��� �Ǵ��ϴ� ������ ����

���� ����Ͽ� �ذ�
*/