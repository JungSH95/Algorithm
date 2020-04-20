#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int people[9], total = 0;
	vector<int> answer;

	for (int i = 0; i < 9; i++)
	{
		cin >> people[i];
		total += people[i];
	}

	// 두명 찾기
	bool check = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			// 뺏을때 100이면
			if (total - (people[i] + people[j]) == 100)
			{
				people[i] = -1;
				people[j] = -1;
				check = true;
			}
		}
		if (check)
			break;
	}

	for (int i = 0; i < 9; i++)
		if (people[i] != -1)
			answer.push_back(people[i]);

	// 난쟁이 키 출력
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

	return 0;
}

/*
이 쉽다고 생각하고 후딱 풀다가 틀리길래 뭐지? 했던 문제..
결국 찾다 보니 멍청한 실수를 했다.
두 명 찾기할 때 찾으면 반복문을 아예 끝내야하는데
안에 있는 반복문만 break 한 실수를 했다.

bool을 사용하여 채크 후 해결
*/