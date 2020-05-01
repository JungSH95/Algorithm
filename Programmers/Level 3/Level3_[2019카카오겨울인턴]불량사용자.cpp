#include <string>
#include <vector>

using namespace std;

bool visit_check[8];
vector<vector<string>> ban_list;


// 같은지 확인
bool string_equal(string user, string ban)
{
	if (user.length() != ban.length())
		return false;

	for (int i = 0; i < user.size(); i++)
		if (ban[i] != '*' && (ban[i] != user[i]))
			return false;

	return true;
}

void DFS(vector<string> user_id, vector<string> banned_id, int index)
{
	// 중복된 것은 추가 안함
	if (index == banned_id.size())
	{
		vector<string> bans;
		for (int i = 0; i < 8; i++)
			if (visit_check[i])
				bans.push_back(user_id[i]);

		bool equal = false;
		for (int i = 0; i < ban_list.size(); i++)
			if (ban_list[i] == bans)
				equal = true;
		if (!equal)
			ban_list.push_back(bans);
		return;
	}

	for (int i = 0; i < user_id.size(); i++)
	{
		// 이미 탐색한 아이디 패스
		if (visit_check[i])
			continue;

		// 가능한 제재 아이디일 경우 다음 목록 탐색
		if (string_equal(user_id[i], banned_id[index]))
		{
			visit_check[i] = true;
			DFS(user_id, banned_id, index + 1);
			visit_check[i] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	DFS(user_id, banned_id, 0);
	int answer = ban_list.size();

	return answer;
}

/*
모든 경우의 수를 체크하기 위해서 dfs를 사용했다.

중복된 값이 나오는 경우가 있어서 가능한 경우의 수를 vector<vector<string>>에 저장하여
중복 값을 제외시켰다.

어려우면서도 쉽게 풀었고, 재미있는 문제였다.
*/