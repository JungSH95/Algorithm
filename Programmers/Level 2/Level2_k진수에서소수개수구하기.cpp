#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int solution(int n, int k) {
    int answer = 0;

	stack <int> s;
    while (n != 0)
    {
        int remainder = n % k;
		s.push(remainder);
        n /= k;
    }

	string converted = "";
	while (!s.empty())
	{
		converted += to_string(s.top());
		s.pop();
	}

	vector<string> candidates;
	int start = 0;
	for (int i = 0; i < converted.size(); i++)
	{
		if (converted[i] == '0')
		{
			if (start < i)
			{
				candidates.push_back(converted.substr(start, i - start));
			}

			start = i + 1;
		}
	}

	if (start < converted.size())
		candidates.push_back(converted.substr(start));

	for (const string& candidate : candidates)
	{
		long long num = stoll(candidate);
		if (num < 2)
			continue;

		bool isPrime = true;
		for (long long i = 2; i <= sqrt(num); i++)
		{
			if (num % i == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			answer++;
	}

    return answer;
}

// 1차 시도 : 성공
