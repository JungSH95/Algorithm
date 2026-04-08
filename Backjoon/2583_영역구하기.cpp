// 백준 영역 구하기 (https://www.acmicpc.net/problem/2583)

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int board[101][101];
int visited[101][101];
vector<int> area_sizes;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(int start_x, int start_y) {
    int area_size = 1;
    queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	visited[start_y][start_x] = 1;

    while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
        q.pop();


        for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
                continue;
            
			if (visited[next_y][next_x] == 1 || board[next_y][next_x] == 1)
                continue;

			q.push({ next_x, next_y });
            area_size += 1;
			visited[next_y][next_x] = 1;
        }
    }

	//cout << "area_size: " << area_size << endl;
	return area_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
		int left_top_x, left_top_y, right_bottom_x, right_bottom_y;
		cin >> left_top_x >> left_top_y >> right_bottom_x >> right_bottom_y;

        for (int x = left_top_x; x < right_bottom_x; x++) {
            for (int y = left_top_y; y < right_bottom_y; y++) {
                board[y][x] = 1;
            }
		}
    }

	for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
			if (visited[y][x] == 1 || board[y][x] == 1)
                continue;

			area_sizes.push_back(bfs(x, y));
        }
    }

	cout << area_sizes.size() << endl;
	sort(area_sizes.begin(), area_sizes.end());
	for (auto area_size : area_sizes) {
        cout << area_size << " ";
    }

    return 0;
}

// 1차 시도 : 성공
