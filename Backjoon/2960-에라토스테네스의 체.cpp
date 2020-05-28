/*
#include <iostream>
using namespace std;

int N, K;
int arr[1001];

int main()
{
cin >> N >> K;

for (int i = 2; i <= N; i++)
arr[i] += 1;

int count = 0, cursor = 2;
while (count != K)
{
// ���� ���� ���� ��ġ�� �̵�
if (arr[cursor] == 0)
{
cursor++;
continue;
}

for (int i = 1; i * cursor <= N; i++)
if (arr[cursor * i] != 0)
{
arr[cursor * i] = 0;
count++;

if (count == K)
cout << cursor * i;
}
}

return 0;
}
*/


/*
ù ��° �õ� �ð� �ʰ�
*/

#include <iostream>
using namespace std;

int N, K;
int arr[1001];

int main()
{
	cin >> N >> K;

	int count = 0;
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i; j <= N; j += i)
				if (arr[j] == 0)
				{
					arr[j] = -1;
					count++;

					if (count == K)
					{
						cout << j;
						break;
					}
				}
		}
	}

	return 0;
}

/*
1�� �ʱ�ȭ �ϴ� ���� �����ϰ�, �� �������� �����ϰ� �����Ͽ���.
-> ���
*/
