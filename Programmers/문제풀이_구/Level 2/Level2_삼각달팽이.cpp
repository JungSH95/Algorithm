#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int Arr[1001][1001];

vector<int> solution(int n) {
	vector<int> answer;

	memset(Arr, 0, sizeof(Arr));

	int count = 1, pos_x = 1, pos_y = 1, dir = 0;

	for (int i = n; i > 0; i--)
	{
		// 아래로
		if (dir == 0)
		{
			for (int j = i; j > 0; j--)
				if (Arr[pos_x][pos_y] == 0)
					Arr[pos_x++][pos_y] = count++;

			dir++;
			pos_y++;
			pos_x--;
		}
		// 오른쪽으로
		else if (dir == 1)
		{
			for (int j = i; j > 0; j--)
				if (Arr[pos_x][pos_y] == 0)
					Arr[pos_x][pos_y++] = count++;

			dir++;
			pos_x--;
			pos_y -= 2;
		}
		// 위로
		else if (dir == 2)
		{
			for (int j = i; j > 0; j--)
				if (Arr[pos_x][pos_y] == 0)
					Arr[pos_x--][pos_y--] = count++;

			dir = 0;
			pos_x += 2;
			pos_y++;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (Arr[i][j] != 0)
				answer.push_back(Arr[i][j]);

	return answer;
}

/*
문제 자체는 단순했는데. 
오랜만의 알고리즘 문제를 풀어서 그런가 괜히 어렵게 생각했다.

단순하게 반복문을 돌려서 해결했다.

한번에 넣어지는 수는 n이 1만큼 감소하며 수가 채워진다
n이 6이라면 6번 채운 뒤 5번 채우고 4번 채우고 ----- 1번 채우고 끝이난다.
*/