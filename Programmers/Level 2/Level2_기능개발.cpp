#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> needDay;

	for (int i = 0; i < progresses.size(); i++)
	{
		int mod = (100 - progresses[i]) % speeds[i];

		if (mod == 0)
			needDay.push_back((100 - progresses[i]) / speeds[i]);
		else
			needDay.push_back((100 - progresses[i]) / speeds[i] + 1);
	}

	for (int i = 0; i < needDay.size(); i++)
		cout << needDay[i] << " ";

	int dayCount = needDay[0];
	int count = 1;

	for (int i = 1; i < needDay.size(); i++)
	{
		if (dayCount < needDay[i])
		{
			answer.push_back(count);
			count = 1;
			dayCount = needDay[i];
		}
		else
			count++;
	}
	answer.push_back(count);

	return answer;
}