#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int len = number.size() - k;

	for (int i = 0; i < len; i++)
	{
		char max = '0';
		int max_pos = -1;

		// 가능한 answer의 범위
		for (int j = 0; j < k + 1; j++)
		{
			if (max < number[j])
			{
				max = number[j];
				max_pos = j;
			}
		}

		// 앞에서 제거된 수 만큼 차감
		k -= max_pos;
		answer += max;
		number = number.substr(max_pos + 1);
	}

	return answer;
}

// 어려웠다...