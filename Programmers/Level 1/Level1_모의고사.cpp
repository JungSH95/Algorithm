#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int count[3] = { 0, };

	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	int arr3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	for (int i = 0; i < answers.size(); i++)
	{
		if (arr1[i % 5] == answers[i])   count[0]++;
		if (arr2[i % 8] == answers[i])   count[1]++;
		if (arr3[i % 10] == answers[i])  count[2]++;
	}

	int maxCount = -1;

	for (int i = 0; i < 3; i++)
		if (maxCount < count[i])
			maxCount = count[i];

	for (int i = 0; i < 3; i++)
		if (maxCount == count[i])
			answer.push_back(i + 1);

	return answer;
}