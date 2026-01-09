#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<vector<string>>& tickets, vector<bool>& visit, string start, vector<string>& answer,
	vector<string>& temp, int count)
{
	temp.push_back(start);

	if (count == tickets.size())
	{
		answer = temp;
		return;
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		if (start == tickets[i][0] && visit[i] == false)
		{
			visit[i] = true;
			DFS(tickets, visit, tickets[i][1], answer, temp, count + 1);

			if (tickets.size() == answer.size() - 1)
				return;
			visit[i] = false;
		}
	}

	temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer, temp;
	vector<bool> visit(tickets.size(), false);
	int count = 0;

	sort(tickets.begin(), tickets.end());
	DFS(tickets, visit, "ICN", answer, temp, count);

	return answer;
}