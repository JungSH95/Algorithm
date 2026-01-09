#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool Skill_Find(string skill, char name)
{
	for (int i = 0; i < skill.size(); i++)
	{
		if (skill[i] == name)
			return true;
	}

	return false;
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int cursor = 0;

	for (int i = 0; i < skill_trees.size(); i++)
	{
		string temp = skill_trees[i];
		cursor = 0;
		bool check = true;

		for (int j = 0; j < temp.size(); j++)
		{
			// ÀÖÀ»¶§
			if (Skill_Find(skill, temp[j]))
				if (skill[cursor] != temp[j])
				{
					check = false;
					break;
				}
				else
					cursor++;
		}

		if (check)
			answer++;
	}

	return answer;
}