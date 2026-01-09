#include <string>
#include <vector>

using namespace std;

void dfs(int n, vector<vector<int>>& computers) {
	if (computers[n][n] == 0) 
		return;
	computers[n][n] = 0;
	for (int i = 0; i < computers.size(); i++)
		if (computers[n][i] != 0)
			dfs(i, computers);
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++)
		if (computers[i][i] != 0)
		{
			dfs(i, computers);
			answer++;
		}

	return answer;
}