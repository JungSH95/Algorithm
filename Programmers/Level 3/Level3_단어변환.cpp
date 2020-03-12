#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool WordCheck(string a, string b)
{
	int count = 0;

	for (int i = 0; i < a.length(); i++)
		if (a[i] != b[i])
			count++;

	if (count == 1)
		return true;
	else
		return false;
}

void DFS(string begin, string target, vector<string> words,
	vector<bool>& useCheck, int& answer, int count)
{
	for (int i = 0; i < words.size(); i++)
	{
		// 1개만 다른경우
		if (WordCheck(begin, words[i]) && !useCheck[i])
		{
			if (target == words[i] && answer > count + 1)
			{
				answer = count + 1;
				return;
			}
			useCheck[i] = true;
			DFS(words[i], target, words, useCheck, answer, count + 1);
			useCheck[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 51;
	vector<bool> useCheck(words.size(), false);

	sort(words.begin(), words.end());
	DFS(begin, target, words, useCheck, answer, 0);

	if (answer == 51)
		return 0;
	return answer;
}