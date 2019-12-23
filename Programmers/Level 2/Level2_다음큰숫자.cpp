#include <string>
#include <vector>

using namespace std;

int TwoCount(int num)
{
	int count = 0;
	while (num > 0)
	{
		if (num % 2 == 1)
			count++;
		num = num / 2;
	}

	return count;
}

int solution(int n) {
	int answer = 0;

	int num = TwoCount(n);

	int i;
	for (i = n + 1; num != TwoCount(i); i++)
		;

	return answer = i;
}