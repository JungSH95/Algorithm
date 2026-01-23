#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<string> maps, vector<vector<int>> &visited, int x, int y)
{
    int totalFood = 0;

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    while (!q.empty())
    {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        totalFood += (int)(maps[now_x][now_y] - '0');

        for (int i = 0; i < 4; i++)
        {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x >= 0 && next_x < maps.size() && next_y >= 0 && next_y < maps[0].size())
            {
                if (maps[next_x][next_y] != 'X' && visited[next_x][next_y] != 1)
                {
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = 1;
                }
            }
        }
    }

    return totalFood;
}

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;

    vector<vector<int>> numberMaps(maps.size(), vector<int>(maps[0].size()));
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size()));
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].length(); j++)
        {
            if (maps[i][j] != 'X' && visited[i][j] != 1)
                answer.push_back(bfs(maps, visited, i, j));
        }
    }

    if (answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());

    return answer;
}

// 1차 시도 : 성공, 크게 어렵지 않게 풀음