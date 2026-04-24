#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int minDepth = 987654321;

void dfs(int x, int y, int depth, vector<vector<int>>& maps, vector<vector<bool>>& visited) {

    if (y == maps.size() - 1 && x == maps[0].size() - 1) {
        minDepth = min(minDepth, depth);
        return;
	}
    else if (depth > minDepth)
		return;

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        // 유효 범위
        if (nextX >= 0 && nextY >= 0 && nextX < maps[0].size() && nextY < maps.size()) {

            // 벽X, 방문X
            if (maps[nextY][nextX] == 1 && !visited[nextY][nextX]) {
                visited[nextY][nextX] = true;
                dfs(nextX, nextY, depth + 1, maps, visited);
                visited[nextY][nextX] = false;
			}
        }
    }
}

int solution(vector<vector<int> > maps) {
    int answer = 0;

	vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));

	visited[0][0] = true;
	dfs(0, 0, 1, maps, visited);

    if (minDepth == 987654321)
        answer = -1;
    else
		answer = minDepth;
    return answer;
}

int solutionbfs(vector<vector<int> > maps) {
    int answer = 0;

    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    visited[0][0] = true;

	queue<pair<int, vector<int>>> q;
	q.push({ 1, { 0, 0 } });

    while (!q.empty()) {
		int depth = q.front().first;
        int x = q.front().second[0];
		int y = q.front().second[1];
        q.pop();

        if (y == maps.size() - 1 && x == maps[0].size() - 1) {
            answer = depth;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            // 유효 범위
            if (nextX >= 0 && nextY >= 0 && nextX < maps[0].size() && nextY < maps.size()) {
                // 벽X, 방문X
                if (maps[nextY][nextX] == 1 && !visited[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    q.push({ depth + 1, { nextX, nextY } });
                }
            }
        }
    }

    if (answer == 0)
		answer = -1;
    return answer;
}

// 1차 시도 : 실패, 테스트 케이스 18번, 효율성 테스트 시간 초과 발생
// 배열 접근으로 인해 문제 발생, 도착점이 막혀있는 경우에서 크기를 고려하지 않음(-2 연산)

// 2차 시도 : 성공, DFS에서 BFS로 변경
