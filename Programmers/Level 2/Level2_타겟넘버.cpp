#include <string>
#include <vector>

using namespace std;

void DFS(vector<int> numbers, int target, int sum, int count, int& answer)
{
	if (count == numbers.size())
	{
		if (target == sum)
			answer++;
		return;
	}

	DFS(numbers, target, sum + numbers[count], count + 1, answer);
	DFS(numbers, target, sum - numbers[count], count + 1, answer);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	DFS(numbers, target, 0, 0, answer);
	return answer;
}