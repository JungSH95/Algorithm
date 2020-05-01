#include <string>
#include <vector>

using namespace std;

bool visit_check[8];
vector<vector<string>> ban_list;


// ������ Ȯ��
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
	// �ߺ��� ���� �߰� ����
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
		// �̹� Ž���� ���̵� �н�
		if (visit_check[i])
			continue;

		// ������ ���� ���̵��� ��� ���� ��� Ž��
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
��� ����� ���� üũ�ϱ� ���ؼ� dfs�� ����ߴ�.

�ߺ��� ���� ������ ��찡 �־ ������ ����� ���� vector<vector<string>>�� �����Ͽ�
�ߺ� ���� ���ܽ��״�.

�����鼭�� ���� Ǯ����, ����ִ� ��������.
*/