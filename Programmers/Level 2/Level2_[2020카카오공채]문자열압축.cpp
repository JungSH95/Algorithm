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
			// 남은 문자열 붙여주고
			if (j + i >= s.size())
			{
				if (count == 0)
					sResult += s.substr(j, i);
				else
					sResult += (to_string(count + 1) + s.substr(j, i));
				break;
			}

			// 같으면 카운트 증가
			if (s.compare(j, i, s, j + i, i) == 0)
				count++;
			// 다르면 카운트가 0이면 그냥 붙이고 1이상이면 숫자로(+1)
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