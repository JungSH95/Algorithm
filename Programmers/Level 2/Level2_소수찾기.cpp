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

	// �����ϰ� �ߺ�����
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	// �Ҽ� ī����
	for (int i = 0; i< result.size(); i++)
		if (IsPrime(result[i]))
			answer++;

	return answer;
}

/*
��ĥ �� �Ҽ� ���� �˰��� ���θ� �ߴ� ���� �������� ������ �����ΰ� ���淡 Ǯ� ����.

�ð��� �ʹ� ���� �ɷ����ȴ�.

������ ������ ������ Ǯ������ ���� ������ �� ���⵵�ϰ�.

���� ��ü�� �����ϰ� �����ؼ� Ǯ����.

1. ���� �� �ִ� ��� ����� ���� ���ڵ��� ���� ��
2. �ߺ��Ǵ� ���� �����ϰ�
3. �Ҽ� ������ üũ�ߴ�.
*/