#include <iostream>
#include <vector>
#include <cstring> // memset()
#include <cstdlib>
using namespace std;

// �׽�Ʈ ���̽� ���� : T, ���ָ� �Ĵ� �������� ���� : N
int T, N;
int start_x, start_y, end_x, end_y;

bool state;
bool visit[100];
vector<pair<int, int>> way_point;

void dfs(int pos_x, int pos_y)
{
	// ���� ��ġ���� �������� �� �� �ֳ�?
	int dis = abs(end_x - pos_x) + abs(end_y - pos_y);
	if (dis <= 1000)
	{
		state = true;
		return;
	}

	// �̵� ������ ��� Ž��
	for (int i = 0; (long unsigned int)i < way_point.size(); i++)
	{
		// �̹� �湮�� ������ �н�
		if (visit[i])
			continue;

		int next_dis = abs(way_point[i].first - pos_x) + abs(way_point[i].second - pos_y);

		// �����ϴٸ� �ش� ���������� �̵�
		if (next_dis <= 1000)
		{
			visit[i] = true;
			dfs(way_point[i].first, way_point[i].second);
		}
	}
}

int main()
{
	cin >> T;

	// �׽�Ʈ ���̽� ��
	for (int t = 0; t < T; t++)
	{
		cin >> N;

		// ��
		cin >> start_x >> start_y;

		memset(visit, 0, sizeof(visit));
		way_point.clear();
		// ������, �佺Ƽ�� �Է�
		for (int i = 0; i < N; i++)
		{
			int x, y;
			cin >> x >> y;
			way_point.push_back(make_pair(x, y));
		}
		cin >> end_x >> end_y;

		state = false;
		dfs(start_x, start_y);

		if (state)
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}

/*
dfs ������ �������� Ǯ��鼭 ���� �ͼ�������.

ũ�� ������� �ȴ����� �ݹ� �ذ��Ͽ���.

������ ���� 
1. i < way_point.size()
- VS������ ������ �ȳ����� ���ؿ����� ������ ���� => (long unsigned int) �߰��Ͽ� �ذ�

2. memset(visit, 0, sizeof(visit));
- #include <cstring> ���߰��� ���� �߻�
*/