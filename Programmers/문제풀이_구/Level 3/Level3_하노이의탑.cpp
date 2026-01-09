#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> answer;
void Move(int n, int from, int to)
{
	//cout << "n : " << from << "에서 " << to << "으로 이동" << endl;
	vector<int> v;
	v.push_back(from);
	v.push_back(to);

	answer.push_back(v);
}

void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
		Move(n, from, to);
	else
	{
		hanoi(n - 1, from, to, by);		// 기둥1에 있는 n-1개의 원판을 기둥2로 이동
		Move(n, from, to);				// 기둥1에 남은 원판을 기둥3으로 이동
		hanoi(n - 1, by, from, to);				// 기둥2에 있는 원판을 기둥3으로 이동
	}
}

vector<vector<int>> solution(int n) {
	hanoi(n, 1, 2, 3);
	return answer;
}


/*
유명한 알고리즘 하노이의 탑

예전에 학교에서 풀어봤던 문제지만, 다시 푸려니까 좀 헷갈렸음.
*/