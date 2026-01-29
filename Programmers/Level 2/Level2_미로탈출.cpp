#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int findPath(vector<string> maps, int start_x, int start_y, int target_x, int target_y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));

    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].length(), 987654321));
    visited[start_y][start_x] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int move_count = visited[y][x];
        q.pop();

        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };
        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // 벽이 아닌 경우
            if (next_x >= 0 && next_x < maps[0].length() && next_y >= 0 && next_y < maps.size() && maps[next_y][next_x] != 'X')
            {
                // 목표 지점인경우
                if (next_x == target_x && next_y == target_y)
                    return move_count + 1;

                if(visited[next_y][next_x] > move_count + 1)
                {
                    visited[next_y][next_x] = move_count + 1;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) 
{
    int start_x = 0, start_y = 0;
    int lever_x = 0, lever_y = 0;
    int exit_x = 0, exit_y = 0;

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].length(); j++)
        {
            if (maps[i][j] == 'S')
            {
                start_x = j;
                start_y = i;
            }
            if (maps[i][j] == 'L')
            {
                lever_x = j;
                lever_y = i;
            }
            if (maps[i][j] == 'E')
            {
                exit_x = j;
                exit_y = i;
            }
        }
    }

    int path1 = findPath(maps, start_x, start_y, lever_x, lever_y);
    int path2 = findPath(maps, lever_x, lever_y, exit_x, exit_y);

    if (path1 == -1 || path2 == -1)
        return -1;

    return path1 + path2;
}


// 1차 시도 : 실패, 시간초과 발생
// 2차 시도 : 성공, visited를 사용해서 이동거리가 더 짧은 경우에만 queue에 추가하도록 수정
