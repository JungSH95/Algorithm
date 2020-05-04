#include <iostream>
#include <vector>
using namespace std;

int arr[101] = { 0, };
int answer_arr[101] = { 0, };
bool visit_arr[101];
int num_count = 0;
vector<int> route;

void DFS(int num)
{
	visit_arr[num] = true;
	route.push_back(num);

	// ������ �湮 �� ���̶��
	if (visit_arr[arr[num]])
	{
		// ó�� ���۰� ���� ������ �ش� ��� üũ
		if (arr[num] == route.front())
		{
			for (int i = 0; i < route.size(); i++)
				answer_arr[route[i]]++;
			num_count += route.size();
		}
	}
	else
		DFS(arr[num]);

	visit_arr[num] = false;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		if (answer_arr[i] != 0)
			continue;

		route.clear();
		DFS(i);
	}

	cout << num_count << endl;

	for (int i = 1; i <= N; i++)
		if (answer_arr[i] != 0)
			cout << i << endl;

	return 0;
}

/*
dfs�� ����Ͽ� �ش� ���� ���󰡸� route ���Ϳ� ���� ������ ��
ó�� ���� ���Ͽ� �������(��ȯ�� ���) �ش� ������ �迭�� ���� üũ�Ͽ�
�� �ش� ���� ���Ͽ� dfs�� ���ϵ����ߴ�.
*/