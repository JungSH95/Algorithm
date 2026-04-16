// 백준 헌내기는 친구가 필요해 (https://www.acmicpc.net/problem/21736)

#include <iostream>
#include <vector>
using namespace std;

int N, M;
char board[600][600];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y, int &count, vector<vector<bool>>& visited) {
    visited[y][x] = true;
    if (board[y][x] == 'P') 
        count++;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) 
            continue;
        if (visited[ny][nx] || board[ny][nx] == 'X') 
            continue;

        dfs(nx, ny, count, visited);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

	int count = 0;
	vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'I') {
                dfs(j, i, count, visited);
                break;
			}
        }
    }

    if (count == 0) 
        cout << "TT";
    else 
		cout << count;

    return 0;
}

// 1차 시도 : 성공
