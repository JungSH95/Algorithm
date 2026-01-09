#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	int cursor = -1;

	for (int i = 0; i < participant.size() - 1; i++)
	{
		if (participant[i] != completion[i])
		{
			cursor = i;
			break;
		}
	}

	if (cursor != -1)
		answer = participant[cursor];
	else
		answer = participant.back();

	return answer;
}