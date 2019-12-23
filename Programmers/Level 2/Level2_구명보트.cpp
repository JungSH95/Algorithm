#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());

	int startCursor = 0;
	int endCursor = people.size() - 1;

	// �ּ� + @ �� limit ���� ũ�� +@ �� ȥ�� ��Ʈ
	while (startCursor <= endCursor)
	{
		if (people[startCursor] + people[endCursor] > limit)
		{
			endCursor--;
			answer++;
		}
		else
		{
			startCursor++;
			endCursor--;
			answer++;
		}
	}

	return answer;
}