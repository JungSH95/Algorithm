#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
	long long answer = 0;

	int min = 0, max = 0;

	if (a == b)
		return a;
	else if (b > a)
	{
		min = a;
		max = b;
	}
	else
	{
		min = b;
		max = a;
	}

	for (int i = min; i <= max; i++)
		answer += i;

	return answer;
}