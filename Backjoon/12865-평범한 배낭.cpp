#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
vector<pair<int, int>> goods;
bool visit[100];
int N, K;

int max_V = 0;

void dfs(int cursor, int total_w)
{
// 무게가 커질 경우, 끝가지 순회했을때
if (goods[cursor].first + total_w > K)
{
int total_v = 0;
for (int i = 0; i < goods.size(); i++)
if (visit[i])
total_v += goods[i].second;

if (max_V < total_v)
max_V = total_v;

return;
}

visit[cursor] = true;
total_w += goods[cursor].first;
for (int i = cursor + 1; i < goods.size(); i++)
{
if (!visit[i])
{
dfs(i, total_w);
visit[i] = false;
}
}

return;
}

int main()
{
// 물품의 수, 버틸 수 있는 무게
cin >> N >> K;

for (int i = 0; i < N; i++)
{
int w, v;	// 무게, 가치
cin >> w >> v;
goods.push_back(make_pair(w, v));
}

for (int i = 0; i < goods.size(); i++)
{
visit[i] = true;
dfs(i, 0);
visit[i] = false;
}
cout << max_V;
return 0;
}
*/

int W[101];
int V[101];
int dp[101][100001];
int N, K;

int max_V = 0;

int DP()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			dp[i][j] = dp[i - 1][j];
			// 무게가 작거나 같다면
			if (W[i] <= j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
		}
	}

	return dp[N][K];
}

int main()
{
	// 물품의 수, 버틸 수 있는 무게
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	cout << DP();

	return 0;
}

/*
1차 시도 dfs 로 물건들의 모든 조합을 찾아내서 적합한 것을 출력했으나
-> 시간초과

알고리즘을 찾아보던 중
https://gsmesie692.tistory.com/113
Knapsack 알고리즘을 통해서 배낭과 비슷한 문제들을 해결한다고 함
Knapsack 알고리즘은 DP를 사용하는 방법
*/
