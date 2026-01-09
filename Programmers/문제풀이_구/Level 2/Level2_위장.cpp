#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, int> typeMap;

	for (int i = 0; i < clothes.size(); i++)
	{
		map<string, int>::iterator iter = typeMap.find(clothes[i][1]);

		if (iter == typeMap.end())
			typeMap.insert(make_pair(clothes[i][1], 1));
		else
			iter->second++;
	}

	map<string, int>::iterator iter;
	for (iter = typeMap.begin(); iter != typeMap.end(); ++iter)
		answer *= (iter->second + 1);
	answer -= 1;

	return answer;
}