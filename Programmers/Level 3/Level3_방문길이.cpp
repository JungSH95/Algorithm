#include <string>
#include <vector>
using namespace std;

int solution(string dirs) {
	int answer = 0;

	vector<vector<int>> way;    // 지나간 경로 저장
	int x = 0, y = 0;

	for (int i = 0; i < dirs.length(); i++)
	{
		// 시작좌표
		vector<int> temp;
		temp.push_back(x);
		temp.push_back(y);

		// 이동시킴 (범위 초과 스킵)
		switch (dirs[i])
		{
		case 'U':
			if (y == 5)
				continue;
			y++;
			break;
		case 'D':
			if (y == -5)
				continue;
			y--;
			break;
		case 'R':
			if (x == 5)
				continue;
			x++;
			break;
		case 'L':
			if (x == -5)
				continue;
			x--;
			break;
		}

		// 해당 좌표가 처음인가?
		bool check = false;
		for (int j = 0; j < way.size(); j++)
			// A -> B 와 B -> A 는 같은길
			if (way[j][0] == temp[0] && way[j][1] == temp[1] &&
				way[j][2] == x && way[j][3] == y ||
				way[j][0] == x && way[j][1] == y &&
				way[j][2] == temp[0] && way[j][3] == temp[1])
			{
				check = true;
				break;
			}

		// 지나간 곳이 아니다.
		if (!check)
		{
			answer++;

			temp.push_back(x);
			temp.push_back(y);
			way.push_back(temp);
		}
	}

	return answer;
}

/*
level 3 치고는 쉬웠다.
백터 컨테이너를 사용하여 출발좌표와 도착좌표를 저장하여 지나간길을 체크했다.

체크할때는 총 해당길을 사용하는 방법은 아래와 같이 2가지이므로
A -> B
B -> A    이처럼 해당 길을 사용가능

길 체크를 2가지 다 체크하여 확인하였다.
*/