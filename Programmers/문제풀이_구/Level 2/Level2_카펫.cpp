#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	int sum = brown + red;
	int height = 3;

	while (true)
	{
		int width = sum / height;

		if (width * height == sum)
		{
			if ((width - 2) * (height - 2) == red)
			{
				answer.push_back(width);
				answer.push_back(height);
				break;
			}
			else
				height++;
		}
		else
			height++;
	}

	return answer;
}