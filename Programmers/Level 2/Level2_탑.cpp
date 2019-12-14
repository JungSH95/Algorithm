#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<int> tops;

	int cursor = heights.size() - 1;
	int temp = heights[cursor];

	while (!heights.empty())
	{
		if (temp < heights[cursor - 1] || cursor == 0)
		{
			tops.push(cursor--);
			heights.pop_back();

			cursor = heights.size() - 1;
			temp = heights[cursor];
		}
		else
			cursor--;
	}

	while (!tops.empty())
	{
		answer.push_back(tops.top());
		tops.pop();
	}

	return answer;
}