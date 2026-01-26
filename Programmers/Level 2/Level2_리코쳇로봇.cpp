#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int bfs(vector<string> board, int x, int y)
{
    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    vector<vector<int>> visited(board.size(), vector<int>(board[0].length(), 987654321));
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = 0;

    while (!q.empty())
    {
        int base_x = q.front().second;
        int base_y = q.front().first;
        q.pop();

        // 방향별 이동
        for (int i = 0; i < 4; i++)
        {
            int next_x = base_x + dx[i];
            int next_y = base_y + dy[i];
            int move_count = 0;

            while (true)
            {
                // 벽을 만난 경우
                if (next_x < 0 || next_x >= board[0].length() || next_y < 0 || next_y >= board.size() || board[next_y][next_x] == 'D')
                {
                    // 목표지점 도착한 경우
                    if (board[next_y - dy[i]][next_x - dx[i]] == 'G')
                        return visited[base_y][base_x] + 1;

                    // 이동 후 멈춘 경우
                    if (move_count > 0 && visited[base_y][base_x] + 1 < visited[next_y - dy[i]][next_x - dx[i]])
                    {
                        q.push(make_pair(next_y - dy[i], next_x - dx[i]));
                        visited[next_y - dy[i]][next_x - dx[i]] = visited[base_y][base_x] + 1;
                    }

                    break;
                }

                next_x += dx[i];
                next_y += dy[i];
                move_count += 1;
            }
        }
    }

    return -1;
}

int solution(vector<string> board)
{
    int answer = 0;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].length(); j++)
        {
            if (board[i][j] == 'R')
                answer = bfs(board, j, i);
        }
    }

    return answer;
}

// 1차 시도 : 성공