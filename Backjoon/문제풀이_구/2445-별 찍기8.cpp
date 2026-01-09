#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << "*";

		for (int j = 2 * (N - 1) - 2 * i; j > 0; j--)
			cout << " ";

		for (int j = 0; j <= i; j++)
			cout << "*";

		cout << endl;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = N - i; j > 0; j--)
			cout << "*";

		for (int j = 0; j < 2 * i; j++)
			cout << " ";

		for (int j = N - i; j > 0; j--)
			cout << "*";

		cout << endl;
	}

	return 0;
}

/*
간단 간단~
*/