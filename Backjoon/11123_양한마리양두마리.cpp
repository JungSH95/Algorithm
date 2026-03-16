// 백준 양 한마리 양 두마리 (https://www.acmicpc.net/problem/11123)

#include <iostream>
#include <queue>
using namespace std;

int T, H, W;
const int MAX = 101;
char map[MAX][MAX];
bool visit[MAX][MAX];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
int ans[MAX];
int cnt = 0;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    visit[y][x] = true;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = y + dy[i];
            int next_x = x + dx[i];

            if (next_y < 0 || next_x < 0 || next_y >= H || next_x >= W)
                continue;

            if (map[next_y][next_x] == '#' && visit[next_y][next_x] == 0) {
                q.push(make_pair(next_y, next_x));
                visit[next_y][next_x] = true;
            }
        }
    }
}

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> H >> W;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (map[i][j] == '#' && visit[i][j] == 0) {
                    bfs(j, i);
                    cnt++;
                }
            }
        }

        ans[t] = cnt;

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                visit[i][j] = 0;
            }
        }
        cnt = 0;
    }

    for (int i = 0; i < T; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

// 1차 시도 : 실패, bfs를 사용했으나 메모리 초과 발생
// 2차 시도 : 성공, bfs를 사용할 때 visit의 처리 위치 변경 후 성공