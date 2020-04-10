#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 1000
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	queue<pair<int, int>> q;
	int box[100][100];

	int answer = 0;

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];

			if (box[i][j] == 1)
				q.push(make_pair(i, j));
		}

	// 익은 토마토 확인
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (nextX < 0 || nextX >= n) continue;
			if (nextY < 0 || nextY >= m) continue;

			// 0 확인 
			if (box[nextX][nextY] == 0)
			{
				box[nextX][nextY] += (box[x][y] + 1);
				q.push(make_pair(nextX, nextY));
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (answer <= box[i][j])
				answer = box[i][j];

			if (box[i][j] == 0)
			{
				answer = -1;
				cout << answer;
				return 0;
			}
		}
	}

	cout << "answer : " << answer - 1;
	return 0;
}