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
			// 오른쪽 범위 넘어섰으면 그만
			if (i + j >= s.length())
				break;

			// 같은가?
			if (s[i - j] == s[i + j])
			{
				int len = (j * 2) + 1;
				if (answer <= len)
					answer = len;
			}
			// 같지않으면 끝
			else
				break;
		}
	}

	return answer;
}

/*
1차 시도 
테스트 4,6,7,12,17,18 / 효율성 1 실패
-> 멍청했다 짝수일 경우 생각안함
*/


#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
	int answer = 1;

	// 홀수
	for (int i = 1; i < s.length() - 1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// 오른쪽 범위 넘어섰으면 그만
			if (i + j >= s.length())
				break;

			// 같은가?
			if (s[i - j] == s[i + j])
			{
				int len = (j * 2) + 1;
				if (answer <= len)
					answer = len;
			}
			// 같지않으면 끝
			else
				break;
		}
	}

	// 짝수
	for (int i = 1; i < s.length() - 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << i + j << " " << i - j - 1 << endl;

			// 같은가?
			if (s[i - j - 1] == s[i + j])
			{
				int len = ((j + 1) * 2);
				if (answer <= len)
					answer = len;
				cout << " Len : " << len << endl;
			}
			// 같지않으면 끝
			else
				break;
		}
	}

	return answer;
}

/*
2차 시도
짝수의 경우 추가
테스트 17, 18번 실패
-> 길이 1인 경우를 체크 안함;
-> answer = 1로 초기화 해서 해결
*/