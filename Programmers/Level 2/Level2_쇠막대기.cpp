#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	vector<int> laser_count;

	for (int i = 0; i < arrangement.length() - 1; i++)
	{
		// 여는 괄호일경우 (판 or 레이저)
		if (arrangement[i] == '(')
		{
			// 레이저일경우
			if (arrangement[i + 1] == ')')
				for (int j = 0; j < laser_count.size(); j++)
					laser_count[j]++;
			// 판일경우
			else if (arrangement[i + 1] == '(')
				laser_count.push_back(0);
		}
		else if (arrangement[i] == ')')
		{
			// 판의 끝
			if (arrangement[i + 1] == ')')
			{
				answer += (laser_count.back() + 1);
				laser_count.pop_back();
			}
		}
	}

	return answer;
}