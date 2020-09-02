#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

bool numCheck[7];

void InitNumber(vector<int>& result, vector<int> n, string temp)
{
	for (int i = 0; i < n.size(); i++)
	{
		if (numCheck[i] == false)
		{
			numCheck[i] = true;
			string newS = temp + to_string(n[i]);
			result.push_back(atoi(newS.c_str()));
			InitNumber(result, n, newS);
			numCheck[i] = false;
		}
	}
}

bool IsPrime(int num)
{
	if (num < 2)
		return false;

	for (int i = 2; i*i <= num; i++)
		if (num % i == 0)
			return false;

	return true;
}

int solution(string numbers) {
	int answer = 0;

	vector<int> num;
	vector<int> result;

	for (int i = 0; i < numbers.length(); i++)
	{
		int temp = numbers[i] - '0';
		num.push_back(temp);
	}

	for (int i = 0; i < num.size(); i++)
	{
		string temp = to_string(num[i]);
		numCheck[i] = true;
		result.push_back(atoi(temp.c_str()));
		InitNumber(result, num, temp);
		numCheck[i] = false;
	}

	// 정렬하고 중복제거
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	// 소수 카운팅
	for (int i = 0; i< result.size(); i++)
		if (IsPrime(result[i]))
			answer++;

	return answer;
}

/*
며칠 전 소수 관련 알고리즘 공부를 했던 것이 생각나서 괜찮은 문제인것 같길래 풀어본 문제.

시간이 너무 오래 걸려버렸다.

오히려 꾸준히 문제를 풀었을때 보다 느려진 것 같기도하고.

문제 자체는 간단하게 생각해서 풀었다.

1. 만들 수 있는 모든 경우의 수의 숫자들을 만든 후
2. 중복되는 것을 제거하고
3. 소수 개수를 체크했다.
*/