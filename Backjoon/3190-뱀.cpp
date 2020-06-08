#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int board[101][101];

deque<pair<int, int>> snake;
vector<pair<int, char>> next_dir;

int dir = 0;					// �� ����

int main()
{
	// ���� ũ�� �Է�
	int N;
	cin >> N;

	// ��� ���� �Է�
	int K;
	cin >> K;

	board[1][1] = 9;		// ��
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}

	// �� ó�� ���� ��ġ
	snake.push_back(make_pair(1, 1));

	// ���� ���� ��ȯ Ƚ��
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

	// �� �̵� ����
	while (true)
	{
		game_time++;

		// �Ӹ�
		int x = snake.front().first;
		int y = snake.front().second;

		// ���� ���⿡ ���� ���� ��ġ �̵� 0:��, 1:��, 2:��, 3:��
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

		// ���� Ȯ�� -> �� �浹?
		if (x > 0 && x <= N && y > 0 && y <= N)
		{
			// �ڱ� �ڽ��� ���̸� ���� ��
			if (board[x][y] == 9)
				break;
			// ������ ���� ��� X
			else if (board[x][y] == 1)
			{
				// �Ӹ� �̵�
				snake.push_front(make_pair(x, y));
				board[x][y] = 9;
			}
			else
			{
				snake.push_front(make_pair(x, y));
				board[x][y] = 9;

				// ���� ��ġ ����
				board[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
		}
		else
			break;

		// ������ȯ�� �����ִٸ�
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
Deque�� �Ӹ��� ������ �����Ͽ� �ְ� ���Ⱑ ���ϱ� ������ 
���� �̵��ϸ� ���� �Ǵ� �Ӹ��� ������ Deque�� ����Ͽ� ���� �̵����״�.

����� ���� ��� ������ ���̰� �þ�Ƿ� pop���� �ʰ� �Ӹ��� �߰��Ǹ鼭 ���� ���̰� �������.
����� ���� ��� ������ ���� �� ������ ������ ������ �ǰ� �Ӹ��� ���ο� ��ġ��
front�� ���Եȴ�.
*/
