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
			// 공백을 만난다면 한 단어
			if (s[j] == ' ' || j == s.length())
			{
				// 역순으로 출력
				for (int k = j - 1; k >= start_cursor; k--)
					cout << s[k];
				cout << " ";

				// 다음 단어를 시작 위치로
				start_cursor = j + 1;
			}
		}
		cout << endl;
	}

	return 0;
}


/*
맨 처음 시도를 했다가 실패했다 원인은 버퍼에 남아있는 개행문자.
오랜만에 문자열 관련된 처리를 하려니 기억이 나지가 않았다.

https://makedotworld.tistory.com/29

cin은 개행문자 전까지 읽는다 -> 즉 버퍼에 개행문자가 남아있다.
문자열을 입력받기 전에 getline(cin, s);를 먼저 사용함으로서 개행문자를 제거하고
문자열을 입력받아 그 문자열들에 대해서 거꾸로 출력을 해주었다.
*/