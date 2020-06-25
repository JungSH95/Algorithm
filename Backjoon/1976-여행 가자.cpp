#include <iostream>
#include <vector>
using namespace std;

int N, M;

int arr[201][201];
bool visit_city[201];
int city_route[1000];

void dfs(int next_city)
{
	visit_city[next_city] = true;

	for (int i = 1; i <= N; i++)
		// ���� �ְ�, �湮 ���� ����
		if (arr[next_city][i] == 1 && !visit_city[i])
		{
			visit_city[i] = true;
			dfs(i);
		}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	vector<int> route;
	for (int i = 0; i < M; i++)
	{
		cin >> city_route[i];
		route.push_back(city_route[i]);
	}

	// ��� Ž��
	dfs(city_route[0]);

	// ��θ� ��� �湮 �ߴ��� üũ
	bool clear = true;
	for (int i = 0; i < route.size(); i++)
		if (visit_city[route[i]] == false)
		{
			clear = false;
			break;
		}

	if (clear)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
/*
������ �߸� �����ؼ� ù �õ��� �����ߴ�.
���� ��ȹ�� 1, 2, 3�ϰ�� ������� 1 -> 2 -> 3�� �ƴϴ��� �ٸ� ���ø� ��ȴٰ� �ش�
���ÿ� �� �� �ִٸ� ������ ���ε� �� ������ ���԰� �ߴ�.

���� ��ȹ�� ���� ���õ��� ��� �� �� �ִٸ� ������ �� �� �����Ƿ� ���� dfs�� �����ߴ�.

�ᱹ���� �����ȹ�� �ִ� ��� ���ÿ��� ����ϵ� ��� �湮�� ���ľ� �����ϹǷ�
���� ��θ� ���� �����ϰ� �ش� ��θ� �湮 �ߴ��� üũ�ؼ� YES or NO �� ����ߴ�.


�ٸ� ������� ��� Ǯ���� ã�ƺôµ� ���� ��� ������� Disjoint-set Union-find �˰�����
����Ͽ� Ǯ����.

// Union-find �˰��� ����
https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html

ó���� �˰����̶� �ű��ߴ�.
Union - Find�� Ʈ�������� �̿��Ͽ� �����ϴ� ������� Disjoint-set�� ǥ���� �� ����ϴ�
�˰����̶�� �Ѵ�.

Disjoint-set�� ���� �ߺ����� �ʴ� �κ� ���յ�� ������ ���ҵ鿡 ���� ������ �����ϰ� �����ϴ�
�ڷᱸ�� ��, ���� ���Ұ� ���� �κ� ���յ�� ������ ���ҵ鿡 ���� �ڷᱸ���̴�.

�� �ڷᱸ���� ���鼭 ��� �� ������ ���� �� �ڷᱸ���� ���÷ȴ����� �� ����Ѱ� ����.
*/