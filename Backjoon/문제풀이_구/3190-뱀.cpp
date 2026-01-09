#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int board[101][101];

deque<pair<int, int>> snake;
vector<pair<int, char>> next_dir;

int dir = 0;					// 뱀 방향

int main()
{
	// 보드 크기 입력
	int N;
	cin >> N;

	// 사과 개수 입력
	int K;
	cin >> K;

	board[1][1] = 9;		// 뱀
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}

	// 맨 처음 뱀의 위치
	snake.push_back(make_pair(1, 1));

	// 뱀의 방향 변환 횟수
	int L;
	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int time;
		char new_dir;
		cin >> time >> new_dir;
		next_dir.push_back(make_pair(time, new_dir));
	}

	bool isEnd = false;
	int game_time = 0, cursor = 0;

	// 뱀 이동 시작
	while (true)
	{
		game_time++;

		// 머리
		int x = snake.front().first;
		int y = snake.front().second;

		// 뱀의 방향에 따라 다음 위치 이동 0:동, 1:남, 2:서, 3:북
		switch (dir)
		{
		case 0:
			y++;
			break;
		case 1:
			x++;
			break;
		case 2:
			y--;
			break;
		case 3:
			x--;
			break;
		}

		// 범위 확인 -> 벽 충돌?
		if (x > 0 && x <= N && y > 0 && y <= N)
		{
			// 자기 자신의 몸이면 게임 끝
			if (board[x][y] == 9)
				break;
			// 사과라면 꼬리 축소 X
			else if (board[x][y] == 1)
			{
				// 머리 이동
				snake.push_front(make_pair(x, y));
				board[x][y] = 9;
			}
			else
			{
				snake.push_front(make_pair(x, y));
				board[x][y] = 9;

				// 꼬리 위치 변경
				board[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
		}
		else
			break;

		// 방향전환이 남아있다면
		if (cursor < next_dir.size() && game_time == next_dir[cursor].first)
		{
			switch (next_dir[cursor].second)
			{
			case 'L':
				dir--;
				if (dir < 0)
					dir = 3;
				break;
			case 'D':
				dir++;
				if (dir > 3)
					dir = 0;
				break;
			}
			cursor++;
		}
	}
	cout << game_time;
	return 0;
}


/*
Deque는 머리와 꼬리를 접근하여 넣고 빼기가 편하기 때문에 
뱀이 이동하며 변경 되는 머리와 꼬리를 Deque를 사용하여 뱀을 이동시켰다.

사과를 먹을 경우 꼬리의 길이가 늘어나므로 pop하지 않고 머리만 추가되면서 뱀의 길이가 길어진다.
사과가 없을 경우 꼬리를 빼면 그 다음의 몸통이 꼬리가 되고 머리는 새로운 위치가
front에 삽입된다.
*/
