#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
struct cmp
{
bool operator()(pair<int, int> a, pair<int, int> b)
{
if (a.first == b.first)
return a.second > b.second;
else
return a.first > b.first;
}
};

int main()
{
int N;
priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> pq;
cin >> N;

for (int i = 0; i < N; i++)
{
int x, y;
cin >> x >> y;
pq.push(make_pair(x, y));
}

while (!pq.empty())
{
cout << pq.top().first << " " << pq.top().second << endl;
pq.pop();
}
return 0;
}
*/
/*
�켱���� ť�� ����Ͽ� ��ǥ �Է°� ���ÿ� �ڵ����� ���� �� �� �ְ�
�Ͽ� ������ �ذ��Ϸ��� �ߴ�.... �ٵ� �ð� �ʰ�...
*/


vector<pair<int, int>> Pos;

int main()
{
	int N;
	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		Pos.push_back({ x, y });
	}

	sort(Pos.begin(), Pos.end());
	for (int i = 0; i < Pos.size(); i++)
		cout << Pos[i].first << " " << Pos[i].second << "\n";

	return 0;
}

/*
backjoon�� �̻��Ѱǰ� ���� �̻��Ѱǰ�...

�и� �Ȱ��� ���� �ҽ� �ڵ带 �����ߴµ� �ð��ʰ� �߰�
�ٽ� �ѹ� ���� �غ��� ���...?

�켱����ť�� ����Ҷ� push�� pop������ vector�� ����ؼ� push ������ �ϰ� �����ߴ�.
*/