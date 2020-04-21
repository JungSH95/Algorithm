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

		// 각 문자가 다른 문자로 변경할 때 최소값
		answer += min(26 - (ch - 'A'), ch - 'A');
		answer += min(left, right);
		s[cursor] = name[cursor];

		// 다음 변경 위치 찾기
		for (int i = 0; i < name.size(); i++)
		{
			// 변경해야할 것
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
그리드 알고리즘을 적용하여 풀었지만 실패 (4, 7, 8, 11)

원인 :
	나의 경우는 한 방향(오른쪽)으로만 찾았음 때문에 문제 발생
	현재 위치에서 왼쪽으로 갔을때와 오른쪽으로 갔을때의 가장 먼저 다른 문자를 찾은 후
	해당 문자를 변경하면 해결됌

Level 2 라고 하기에는 뭔가 어렵게 느껴진 문제
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
		// 각 문자가 다른 문자로 변경할 때 최소값
		answer += min(26 - (name[cursor] - 'A'), name[cursor] - 'A');
		temp[cursor] = name[cursor];

		for (int move = 1; move < name.length(); move++) {
			//오른쪽 이동이 빠르다면 오른쪽으로 이동하고 이동횟수 반영
			if (name[(cursor + move) % name.length()] != temp[(cursor + move) % name.length()]) {
				cursor = (cursor + move) % name.length();
				answer += move;
				break;
			}
			//왼쪽으로 이동이 빠르다면 왼쪽으로 이동하고 이동횟수 반영
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