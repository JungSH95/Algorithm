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
		// �и��ϰ�
		stringstream s(record[i]);
		s >> order;
		s >> id;
		s >> name;

		// ���� �߰� or ����
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
			answer.push_back(user_map[id] + "���� ���Խ��ϴ�.");
		else if (order == "Leave")
			answer.push_back(user_map[id] + "���� �������ϴ�.");
	}
	return answer;
}

/*
���ڿ��� �������� �߶��ִ� ������ ������ ã�ƺ����� �Ʒ��� ã�Ҵ�.

#include <sstream>
stringstream

������ �����ڷ� �и��� ���ش�. !! ����
������ ���� �ϳ� �˾Ƴ´�.
*/