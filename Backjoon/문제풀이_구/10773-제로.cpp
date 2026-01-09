#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int K;
	stack<int> s;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 0 && !s.empty())
			s.pop();
		else
			s.push(temp);
	}


	int total_money = 0;
	while (!s.empty())
	{
		total_money += (int)s.top();
		s.pop();
	}
	cout << total_money;

	return 0;
}

/*
알고리즘 공부를 시작하고 난 뒤에 처음으로 풀게된 문제다.
예전같았으면 입력의 범위와 수를 신경 쓰지 않고 문제를 풀었을 것이다.

지금은 문제를 보고 문제가 원하는 바를 파악하고
주어진 입력의 수와 해당 입력의 범위를 생각하여 코드를 작성했다.
최대 100,000개의 입력. 각 입력은 최대 1,000,000의 값을 가진다
-> 최대 크기는 100,000,000,000이다.

int의 범위는 –2,147,483,648 ~ 2,147,483,647 이므로 부족하기 때문에
longlong을 사용하여 총 합을 저장했다.
*/