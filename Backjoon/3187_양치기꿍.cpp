// 백준 양치기 꿍 (https://www.acmicpc.net/problem/3187)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int arr[251][251];
bool visited[251][251];

int wolf = 0, sheep = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(int start_x, int start_y) {
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	visited[start_y][start_x] = true;

	int cur_wolf = 0, cur_sheep = 0;
    while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

        if (arr[y][x] == 1)
            cur_wolf++;
        else if (arr[y][x] == 2)
			cur_sheep++;

        for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

            if (next_x >= 0 && next_y >= 0 && next_x < C && next_y < R) {
                if (visited[next_y][next_x] == false && arr[next_y][next_x] != -1) {
                    visited[next_y][next_x] = true;
					q.push({ next_x, next_y });
                }
            }
        }
    }

	if (cur_wolf >= cur_sheep)
        wolf += cur_wolf;
    else
        sheep += cur_sheep;
	return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
			cin >> c;

			// 늑대(v) : 1, 양(k) : 2, 울타리(#) : -1, 빈 칸(.) : 0
			if (c == 'v')
                arr[i][j] = 1;
            else if (c == 'k')
                arr[i][j] = 2;
			else if (c == '#')
                arr[i][j] = -1;
            else
                arr[i][j] = 0;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && arr[i][j] != -1)
                bfs(j, i);
        }
    }

	cout << sheep << " " << wolf << "\n";

    return 0;
}

// 1차 시도 : 성공
