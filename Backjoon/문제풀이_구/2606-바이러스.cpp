#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int com_N;
vector<vector<int>> computer;
bool visit[101];

int main()
{
	cin >> com_N;
	computer.resize(com_N + 1);

	cout << computer.size();

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int com1, com2;
		cin >> com1 >> com2;
		computer[com1].push_back(com2);
		computer[com2].push_back(com1);
	}

	int virus = 0;
	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty())
	{
		int com_num = q.front();
		q.pop();

		for (int i = 0; i < computer[com_num].size(); i++)
		{
			if (!visit[computer[com_num][i]])
			{
				visit[computer[com_num][i]] = true;
				q.push(computer[com_num][i]);
				virus++;
			}
		}
	}
	cout << virus;
	return 0;
}

/*
1차 시도 실패
: 시작을 아예 1로 고정을 해놨기 때문에 입력이 1로 시작하는 것이 없으면 탐색이 안됨
즉 지금 구조는 단방향 그래프

2차 시도 -> computer[com2].push_back(com1); 을 추가하여 양방향으로 변경
성공!!
*/
