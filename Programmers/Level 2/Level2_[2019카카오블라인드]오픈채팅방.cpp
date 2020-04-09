#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> user_map;
	string order = "", id = "", name = "";

	for (int i = 0; i < record.size(); i++)
	{
		// 분리하고
		stringstream s(record[i]);
		s >> order;
		s >> id;
		s >> name;

		// 유저 추가 or 변경
		if (order == "Enter" || order == "Change")
			user_map[id] = name;
	}

	for (int i = 0; i < record.size(); i++)
	{
		stringstream s(record[i]);
		s >> order;
		s >> id;
		s >> name;

		if (order == "Enter")
			answer.push_back(user_map[id] + "님이 들어왔습니다.");
		else if (order == "Leave")
			answer.push_back(user_map[id] + "님이 나갔습니다.");
	}
	return answer;
}

/*
문자열을 공백으로 잘라주는 좋은거 없을까 찾아보던중 아래를 찾았다.

#include <sstream>
stringstream

공백을 구분자로 분리를 해준다. !! 개꿀
좋은거 오늘 하나 알아냈다.
*/