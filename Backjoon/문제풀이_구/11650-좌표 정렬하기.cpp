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
우선순위 큐를 사용하여 좌표 입력과 동시에 자동으로 정렬 할 수 있게
하여 문제를 해결하려고 했다.... 근데 시간 초과...
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
backjoon이 이상한건가 내가 이상한건가...

분명 똑같은 위의 소스 코드를 제출했는데 시간초과 뜨고
다시 한번 제출 해보니 통과...?

우선순위큐를 사용할때 push와 pop과정을 vector를 사용해서 push 과정만 하게 변경했다.
*/