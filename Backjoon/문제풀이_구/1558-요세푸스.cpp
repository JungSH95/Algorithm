/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
int N, K;
cin >> N >> K;

vector<int> Josephus;
int Arr[5000] = { 0, };
int count = 0, cursor = 0;

while (Josephus.size() != N)
{
cursor++;
count++;

// 배열의 끝 도달 시
if (cursor == N + 1)
cursor = 1;

// 이동한 위치가 이미 들린 곳이라면 안들린곳으로 이동
if (Arr[cursor - 1] == 1)
for (int i = cursor; i < 5000; i++)
{
if (i == N)
i = 0;
if (Arr[i] == 0)
{
cursor = i + 1;
break;
}
}

if (count == K)
if (Arr[cursor - 1] == 0)
{
Josephus.push_back(cursor);
Arr[cursor - 1] = 1;
count = 0;
}
}

cout << "<";
for (int i = 0; i < Josephus.size(); i++)
{
cout << Josephus[i];
if (i != Josephus.size() - 1)
cout << ", ";
}
cout << ">";

return 0;
}
*/

/*
스택 사용해봤을때 시간 초과 실패
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> Josephus;
	for (int i = 1; i <= N; i++)
		Josephus.push(i);
	int count = 0;

	cout << "<";
	while (true)
	{
		count++;
		if (count == K)
		{
			cout << Josephus.front();
			Josephus.pop();
			if (Josephus.empty())
				break;
			cout << ", ";
			count = 0;
		}
		// 빠지는 것이 아니므로 맨 뒤로
		else
		{
			Josephus.push(Josephus.front());
			Josephus.pop();
		}
	}
	cout << ">";

	return 0;
}

/*
요세푸스 문제는 원형큐를 사용하기 딱 좋은 문제
괜히 스택으로 풀어보려 했다가 시간 초과
스택으로 풀어도 시간 초과안하게 할 방법 생각 필요함
*/