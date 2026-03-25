// 백준 토마토 (https://www.acmicpc.net/problem/7569)

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// 상자의 크기 : M(가로) * N(세로), 상자의 수 : H(높이)
// 단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다.
int M, N, H;
int box[101][101][101];
int visited[101][101][101];

// 익은 토마토의 인접한 곳에 있는 익지 않은 토마토들은 영향을 받아 익게된다.
// 인접한 곳(6방향) : 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

queue<tuple<int, int, int>> q;

int bfs() {
    while (!q.empty()) {
        int now_h = get<0>(q.front());
        int now_n = get<1>(q.front());
        int now_m = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 6; i++) {
            int next_h = now_h + dz[i];
            int next_n = now_n + dx[i];
            int next_m = now_m + dy[i];

            // 범위 밖
            if (next_h < 1 || next_h > H || next_n < 0 || next_n >= N || next_m < 0 || next_m >= M)
                continue;

            if (box[next_h][next_n][next_m] == 0 && visited[next_h][next_n][next_m] == -1) {
                box[next_h][next_n][next_m] = 1;
                q.push(make_tuple(next_h, next_n, next_m));
                visited[next_h][next_n][next_m] = visited[now_h][now_n][now_m] + 1;
            }
        }
    }    

    int day = -1;
    for (int h = 1; h <= H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                // 안익은 토마토 확인
                if (box[h][n][m] == 0)
                    return -1;

                day = max(day, visited[h][n][m]);
            }
        }
    }

    return day;
}

int main() {
    cin >> M >> N >> H;

    // 1:익은 토마토, 0:익지 않은 토마토, -1:빈칸
    bool tomatoCheck = false;
    for (int h = 1; h <= H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> box[h][n][m];

                if (box[h][n][m] == 1) {
                    q.push(make_tuple(h, n, m));
                    visited[h][n][m] = 0;
                }
                else
                    visited[h][n][m] = -1;

                if (box[h][n][m] == 0 && !tomatoCheck)
                    tomatoCheck = true;
            }
        }
    }

    // 익지 않은 토마토가 없는 경우
    if (tomatoCheck == false) {
        cout << 0;
        return 0;
    }

    cout << bfs();
    return 0;
}

// 1차 시도 : 성공, tuple 직접 사용해본건 처음