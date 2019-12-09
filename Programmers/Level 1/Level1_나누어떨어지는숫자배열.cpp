#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;

	for (int i = 0; i < arr.size(); i++)
		if (arr[i] % divisor == 0)
			answer.push_back(arr[i]);

	if (answer.size() == 0)
		answer.push_back(-1);
	else
	{
		bool isSwapCheck;

		for (int i = 0; i < answer.size(); i++)
		{
			if (isSwapCheck == false)
				break;

			for (int j = 0; j < answer.size() - 1 - i; j++)
				if (answer[j] > answer[j + 1])
				{
					int temp = answer[j];
					answer[j] = answer[j + 1];
					answer[j + 1] = temp;
					isSwapCheck = true;
				}
		}
	}

	return answer;
}