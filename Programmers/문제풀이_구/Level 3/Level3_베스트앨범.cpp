#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	vector<pair<int, string>> genres_Count; // 재생수, 장르
	map<string, int> genres_Totall; // 장르, 토탈 재생수
	vector<pair<int, int>> temp;     // 재생수 번호

	for (int i = 0; i < genres.size(); i++)
	{
		genres_Count.push_back(make_pair(plays[i], genres[i]));
		genres_Totall[genres[i]] += plays[i];
		temp.push_back(make_pair(plays[i], i));
	}
	sort(genres_Count.begin(), genres_Count.end(), greater<pair<int, string>>());

	vector<pair<int, string>> vec_Totall;
	map<string, int>::iterator iter2;
	for (iter2 = genres_Totall.begin(); iter2 != genres_Totall.end(); iter2++)
		vec_Totall.push_back(make_pair(iter2->second, iter2->first));
	sort(vec_Totall.begin(), vec_Totall.end(), greater<pair<int, string>>());

	vector<pair<int, string>>::iterator iter;
	for (iter = vec_Totall.begin(); iter != vec_Totall.end(); iter++)
	{
		int count = 0;

		vector<pair<int, string>>::iterator iter2;
		for (iter2 = genres_Count.begin(); iter2 != genres_Count.end(); iter2++)
		{
			if (iter->second == iter2->second)
			{
				vector<pair<int, int>>::iterator iter6;

				for (iter6 = temp.begin(); iter6 != temp.end(); iter6++)
					if (iter6->first == iter2->first)
					{
						count++;
						answer.push_back(iter6->second);
						temp.erase(iter6);
						break;
					}

				if (count == 2)
					break;
			}
		}
	}

	return answer;
}