#include <iostream>
using namespace std;

int N, M;
int arr[101][101];

void floyd() {
	for (int iter = 1; iter <= N; iter++) {
		for (int here = 1; here <= N; here++) {
			for (int there = 1; there <= N; there++) {
				int cost = arr[here][iter] + arr[iter][there];
				if (arr[here][there] > cost)
					arr[here][there] = cost;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	// 경로가 없는 경우 -1
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = 987654321;

	// 버스 노선 가격 입력
	for (int i = 0; i < M; i++)
	{
		int start, end, price;
		cin >> start >> end >> price;

		if (arr[start][end] > price)
			arr[start][end] = price;
	}

	floyd();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == 987654321)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
몇 차례의 코딩테스트를 진행하면서 느낀 것은
항상 문제를 풀때 시간이 너무 오래 걸린다는 것이다.

그래서 이번에는 1시간 타이머를 맞추고 문제 풀이를 진행했다.

시작과 도착 도시가 양방향으로 이루어져 있지 않기 때문에
vector<vector<int>> 를 사용하여 갈 수 있는 도시들을 저장하고
DFS를 사용해서 해당 도시에서 갈 수 있는 모든 경로를 찾아서 도착했을때
가장 작은 값을 넣어볼까 생각을 해봤는데 도시의 개수가 최대 100개까지 가능하고, 시간 제한이
1초다.... 아마 높은 확률로 시관초과 뜰 것이라고 생각해서 dfs 방법 폐기..

결국 타이머 울려서 ㅈㅈ...

// 문제 풀이 참고
https://kyunstudio.tistory.com/252

// 플로이드 와샬 알고리즘 설명
https://dongdd.tistory.com/107

문제의 이름과 동일한 알고리즘이 존재한다는 것을 알게됐다.
플로이드 알고리즘은 다익스트라 알고리즘과 진행이 거의 유사한 알고리즘이라고 한다.
너무나 생각보다 간단한 방법으로 모든 도시를 이동할때 방생하는 최소 비용을 구할 수 있었다.

알고리즘은 간단하다.

예를들어 2번 도시에서 1번 도시로 갈때 1번 도시에서 다른 도시들로 이동하는 것을 모두 계산하는 것이다.

// [1][1~5] = 1번도시->1번도시 비용 + 1번도시->[1~5]번도시 비용
// [2][1~5] = 2번도시->1번도시 비용 + 1번도시->[1~5]번도시 비용
// [3][1~5] = 3번도시->1번도시 비용 + 1번도시->[1~5]번도시 비용
// [4][1~5] = 4번도시->1번도시 비용 + 1번도시->[1~5]번도시 비용
// [5][1~5] = 5번도시->1번도시 비용 + 1번도시->[1~5]번도시 비용

// [1][1~5] = 1번도시->2번도시 비용 + 2번도시->[1~5]번도시 비용

즉 어떤 도시를 거치는 경우에 대하여 계산하는 방법을 사용한다.

결론적으로 문제를 어떻게 빨리 풀 수 있을지에 대하여 좀 고민을 해봐야 할 것 같다.
*/