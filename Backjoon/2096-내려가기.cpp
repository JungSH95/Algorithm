/*
#include <iostream>
#include <math.h>
using namespace std;

int arr[100000][3] = { 0, };
int min = 999999;
int max = 0;
int N;

void search(int depth, int total, int cursor)
{
	if (depth == N)
	{
		if (min >= total)
			min = total;
		if (max <= total)
			max = total;
		return;
	}

	switch (cursor)
	{
	case 0:
		search(depth + 1, total + arr[depth][cursor], cursor);
		search(depth + 1, total + arr[depth][cursor], cursor + 1);
		break;
	case 1:
		search(depth + 1, total + arr[depth][cursor], cursor - 1);
		search(depth + 1, total + arr[depth][cursor], cursor);
		search(depth + 1, total + arr[depth][cursor], cursor + 1);
		break;
	case 2:
		search(depth + 1, total + arr[depth][cursor], cursor - 1);
		search(depth + 1, total + arr[depth][cursor], cursor);
		break;
	}
}

void main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 3; i++)
		search(0, 0, i);

	cout << max << " " << min;

	return;
}
*/

/*
ó�� ����� dfs�� ����Ͽ� ��� ����� ���� ���Ͽ� ����Ͽ�
���� ū ���� ���� ���� ���� �����Ͽ����� ����

N�� Ŀ������ ȣ���ϴ� �Լ��� �������Ƿ� �ð� �ʰ��Ǵ� ��
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int min_arr[100000][3] = { 0, };
int max_arr[100000][3] = { 0, };
int N;


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> min_arr[i][j];
			max_arr[i][j] = min_arr[i][j];
		}
	}

	for (int i = 1; i < N; i++)
	{
		max_arr[i][0] += max(max_arr[i - 1][0], max_arr[i - 1][1]);
		max_arr[i][1] += max(max_arr[i - 1][0], max(max_arr[i - 1][1], max_arr[i - 1][2]));
		max_arr[i][2] += max(max_arr[i - 1][1], max_arr[i - 1][2]);

		min_arr[i][0] += min(min_arr[i - 1][0], min_arr[i - 1][1]);
		min_arr[i][1] += min(min_arr[i - 1][0], min(min_arr[i - 1][1], min_arr[i - 1][2]));
		min_arr[i][2] += min(min_arr[i - 1][1], min_arr[i - 1][2]);
	}

	cout << max(max_arr[N - 1][0], max(max_arr[N - 1][1], max_arr[N - 1][2]))
		<< " " << min(min_arr[N - 1][0], min(min_arr[N - 1][1], min_arr[N - 1][2]));
	return 0;
}
*/

/*
�� ��° �õ� �޸� �ʰ� �迭�� ���Ƽ� ��
*/

#include <iostream>
#include <algorithm>
using namespace std;

int input[3] = { 0, };
int min_arr[3] = { 0, };
int max_arr[3] = { 0, };
int N;

void main()
{
	cin >> N;

	for (int i = 0; i < 3; i++)
	{
		cin >> min_arr[i];
		max_arr[i] = min_arr[i];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> input[j];

		int num0 = max_arr[0], num1 = max_arr[1], num2 = max_arr[2];
		max_arr[0] = max(num0, num1) + input[0];
		max_arr[1] = max(num0, max(num1, num2)) + input[1];
		max_arr[2] = max(num1, num2) + input[2];

		num0 = min_arr[0], num1 = min_arr[1], num2 = min_arr[2];
		min_arr[0] = min(num0, num1) + input[0];
		min_arr[1] = min(num0, min(num1, num2)) + input[1];
		min_arr[2] = min(num1, num2) + input[2];
	}

	cout << max(max_arr[0], max(max_arr[1], max_arr[2]))
		<< " " << min(min_arr[0], min(min_arr[1], min_arr[2]));

	return;
}

/*
�޸𸮸� �ٿ���(�迭�� ũ�� �ٿ���) �ذ�
*/