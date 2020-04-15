#include<iostream>
using namespace std;

int main()
{
	int answer = 0;
	int N;
	cin >> N;

	bool check = false;
	int num = N / 5;
	while (num >= 0)
	{
		int mod = N - (num * 5);
		if (mod % 3 == 0)
		{
			cout << num + (mod / 3);
			check = true;
			break;
		}
		else
			num--;
	}

	if (!check)
		cout << -1;
	return 0;
}

/*
문제 순위에 있던 문제

쉬움
*/