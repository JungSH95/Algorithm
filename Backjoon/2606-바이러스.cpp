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
1�� �õ� ����
: ������ �ƿ� 1�� ������ �س��� ������ �Է��� 1�� �����ϴ� ���� ������ Ž���� �ȵ�
�� ���� ������ �ܹ��� �׷���

2�� �õ� -> computer[com2].push_back(com1); �� �߰��Ͽ� ��������� ����
����!!
*/
