#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
	int answer = 0;

	string s = "";
	for (int i = 0; i < name.size(); i++)
		s += "A";

	int left = 0, right = 0;
	int cursor = 0;
	while (s.compare(name) != 0)
	{
		char ch = name[cursor];

		// �� ���ڰ� �ٸ� ���ڷ� ������ �� �ּҰ�
		answer += min(26 - (ch - 'A'), ch - 'A');
		answer += min(left, right);
		s[cursor] = name[cursor];

		// ���� ���� ��ġ ã��
		for (int i = 0; i < name.size(); i++)
		{
			// �����ؾ��� ��
			if (s[i] != name[i])
			{
				right = i - cursor;
				left = name.size() - i + cursor;
				cursor = i;
				break;
			}
		}

		cout << s << " cursor : " << cursor << " right : " << right << " left : " << left << endl;
	}

	return answer;
}

/*
�׸��� �˰����� �����Ͽ� Ǯ������ ���� (4, 7, 8, 11)

���� :
	���� ���� �� ����(������)���θ� ã���� ������ ���� �߻�
	���� ��ġ���� �������� �������� ���������� �������� ���� ���� �ٸ� ���ڸ� ã�� ��
	�ش� ���ڸ� �����ϸ� �ذ��

Level 2 ��� �ϱ⿡�� ���� ��ư� ������ ����
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
	int answer = 0;

	string temp = "";
	for (int i = 0; i < name.size(); i++)
		temp += "A";

	int left = 0, right = 0;
	int cursor = 0;
	while (temp.compare(name) != 0)
	{
		// �� ���ڰ� �ٸ� ���ڷ� ������ �� �ּҰ�
		answer += min(26 - (name[cursor] - 'A'), name[cursor] - 'A');
		temp[cursor] = name[cursor];

		for (int move = 1; move < name.length(); move++) {
			//������ �̵��� �����ٸ� ���������� �̵��ϰ� �̵�Ƚ�� �ݿ�
			if (name[(cursor + move) % name.length()] != temp[(cursor + move) % name.length()]) {
				cursor = (cursor + move) % name.length();
				answer += move;
				break;
			}
			//�������� �̵��� �����ٸ� �������� �̵��ϰ� �̵�Ƚ�� �ݿ�
			else if (name[(cursor + name.length() - move) % name.length()]
				!= temp[(cursor + name.length() - move) % name.length()]) {
				cursor = (cursor + name.length() - move) % name.length();
				answer += move;
				break;
			}
		}
	}

	return answer;
}