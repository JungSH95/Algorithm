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
// ���԰� Ŀ�� ���, ������ ��ȸ������
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
// ��ǰ�� ��, ��ƿ �� �ִ� ����
cin >> N >> K;

for (int i = 0; i < N; i++)
{
int w, v;	// ����, ��ġ
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
			// ���԰� �۰ų� ���ٸ�
			if (W[i] <= j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
		}
	}

	return dp[N][K];
}

int main()
{
	// ��ǰ�� ��, ��ƿ �� �ִ� ����
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	cout << DP();

	return 0;
}

/*
1�� �õ� dfs �� ���ǵ��� ��� ������ ã�Ƴ��� ������ ���� ���������
-> �ð��ʰ�

�˰����� ã�ƺ��� ��
https://gsmesie692.tistory.com/113
Knapsack �˰����� ���ؼ� �賶�� ����� �������� �ذ��Ѵٰ� ��
Knapsack �˰����� DP�� ����ϴ� ���
*/
