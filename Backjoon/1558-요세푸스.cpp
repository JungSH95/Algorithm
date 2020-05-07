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

// �迭�� �� ���� ��
if (cursor == N + 1)
cursor = 1;

// �̵��� ��ġ�� �̹� �鸰 ���̶�� �ȵ鸰������ �̵�
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
���� ����غ����� �ð� �ʰ� ����
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
		// ������ ���� �ƴϹǷ� �� �ڷ�
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
�似Ǫ�� ������ ����ť�� ����ϱ� �� ���� ����
���� �������� Ǯ��� �ߴٰ� �ð� �ʰ�
�������� Ǯ� �ð� �ʰ����ϰ� �� ��� ���� �ʿ���
*/