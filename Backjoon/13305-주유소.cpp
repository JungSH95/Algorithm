#include <iostream>
using namespace std;

int N;

long city_dis[100000];
long city_price[100000];

int main()
{
	// ���� ��
	cin >> N;

	// �Ÿ� �Է�
	for (int i = 0; i < N - 1; i++)
		cin >> city_dis[i];

	// ������ �⸧ �� �Է�
	for (int i = 0; i < N; i++)
		cin >> city_price[i];

	// ������ ���� �������� ����
	int pos = 0;
	long long total_price = 0;
	while (pos < N - 1)
	{
		long dis = 0;
		int next_pos = 0;
		bool city_stop = false;

		// ���� ���ú��� �� �� ���ð� �ִ��� Ȯ�� & �� ���� ������ �Ÿ�
		for (int i = pos + 1; i < N; i++)
		{
			dis += city_dis[i - 1];

			// �� �� ���ð� �ִ�.
			if (city_price[pos] > city_price[i])
			{
				city_stop = true;
				next_pos = i;
				break;
			}
			else
				next_pos = i;
		}

		// ���� ��ġ������ �ʿ��� �⸧ ���� �� ���� ��ġ �̵�
		total_price += (dis * city_price[pos]);
		pos = next_pos;
	}

	cout << total_price;
	return 0;
}

/*
ó�� �õ��������� �����ߴ�. 
-> �Ÿ��� ���� ũ�⶧���� int���δ� �Ѱ谡 ����. long ���� ������ ����

�Ʒ��� �ڵ�� �ٸ������ Ǯ�� �ڵ� (���N)
https://2youngjae.tistory.com/63
- ������(���N*N) �� ���� ����̴�.

#include <stdio.h>
using namespace std;
 
long long d[100000];
long long dist[100000];
long long price[100000];
int n;
 
int main() {
	// ���� �� �Է�
    scanf("%d", &n);

	// �Ÿ� �Է�
    for (int i = 0; i < n - 1; i++)
        scanf("%d",&dist[i]);

	// ���� �⸧ ���� �Է�
    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);
    
	// ó�����ð� �������÷� �Ѿ�� ������ ������ d[0]�� ����
    d[0] = price[0] * dist[0];

	// �� ó�� ���ð� ���� ���� ���̶� ����
    long long min = price[0];

	// �� ��° ���ú��� �ڽź��� �� �⸧���� ���� ���� ã��
    for (int i = 1; i < n; i++) {
		// ������ �� �� �� �߰�
        if (price[i] < min) {
			// �ش� ��Ҹ� �ּ� �⸧������ ���
            min = price[i];
        }

		// �ּ� �⸧������ �����Ǿ� �ִ� ���� ����ؼ� �̵�
        d[i] = d[i - 1] + min * dist[i];
    }

	// ������ ���ñ����� ���� ���� ����� ���� ����
    printf("%ld\n", d[n - 1]);
}

*/