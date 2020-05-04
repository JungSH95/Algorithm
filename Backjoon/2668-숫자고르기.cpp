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

	// 다음이 방문 한 곳이라면
	if (visit_arr[arr[num]])
	{
		// 처음 시작과 값이 같으면 해당 경로 체크
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
dfs를 사용하여 해당 값을 따라가며 route 벡터에 값을 저장한 후
처음 값과 비교하여 같을경우(순환일 경우) 해당 값들을 배열에 따로 체크하여
또 해당 값에 대하여 dfs를 안하도록했다.
*/