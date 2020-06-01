#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// N : ���� ũ��, M : ġŲ ��
int N, M;
int map[50][50];

int min_dis = 9999;

// ���� ��ġ�� ġŲ �� ��ġ ����
vector<pair<int, int>> house, chicken;
bool visit_chicken[13];

void dfs(int count)
{
	// ���� ġŲ �� �Ϸ�
	if (count == M)
	{
		int total_dis = 0;

		// ������ ���� ����� ġŲ �� ã��
		for (int j = 0; j < house.size(); j++)
		{
			int house_x = house[j].first;
			int house_y = house[j].second;
			int dis = 9999;

			for (int i = 0; i < 13; i++)
			{
				// ������ ġŲ ���̶�� �Ÿ� ���
				if (visit_chicken[i])
				{
					int chicken_x = chicken[i].first;
					int chicken_y = chicken[i].second;

					dis = min(dis, abs(house_x - chicken_x) + abs(house_y - chicken_y));
				}
			}

			// ���� ������ �� �Ÿ��� �����ְ� ���� ��
			total_dis += dis;
		}

		// ������ ġŲ ������ �Ÿ��� ���� ������ �� ����
		min_dis = min(min_dis, total_dis);
		return;
	}

	for (int i = 0; i < chicken.size(); i++)
	{
		if (visit_chicken[i])
			continue;

		visit_chicken[i] = true;
		dfs(count + 1);
		visit_chicken[i] = false;
	}
}

int main()
{
	cin >> N >> M;

	// �� �Է�
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				house.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}

	dfs(0);
	cout << min_dis;

	return 0;
}

/*
ġŲ �� M���� ����� �� ������ ġŲ �Ÿ� �ּڰ��� ���ϴ� ����.
M���� ������ ��ü ����� ���� ���� �ؾ���
DFS�� ����ϸ� ��ü ����� ���� ���Ͽ� ġŲ �Ÿ��� ���� �� ����.

ó�� �õ����� dfs�� ī��Ʈ�� �־ �õ��� �ߴµ� �ð��ʰ��� �����ߴ�.
�ð��� ���� ����� ������ ����ߴ� ������� cursor�� ������ �ߴ����� �Ѱ��־�
�ݺ����� �����Ű�� ����� ����ؼ� ����ߴ�.
*/
