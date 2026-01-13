#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> st = { "AZWQY", "CAABX", "BBDDA", "ACACA" };
vector<string> re = { "A", "BB", "A" };


bool IsCanRemoveDFS(vector<string> storage, int i, int j, char contain)
{
    bool canRemove = false;
    
	// 외곽인 경우
    if(i - 1 < 0)
		return true;
	else if (i + 1 >= storage.size())
		return true;
	else if (j - 1 < 0)
		return true;
	else if (j + 1 >= storage[i].length())
		return true;
    else
    {
        // 상하좌우가 '0'인 경우
        if (storage[i - 1][j] == '0') // 위
			canRemove = IsCanRemoveDFS(storage, i - 1, j, contain);
		else if (storage[i + 1][j] == '0') // 아래
			canRemove = IsCanRemoveDFS(storage, i + 1, j, contain);
		else if (storage[i][j - 1] == '0') // 왼쪽
			canRemove = IsCanRemoveDFS(storage, i, j - 1, contain);
		else if (storage[i][j + 1] == '0') // 오른쪽
			canRemove = IsCanRemoveDFS(storage, i, j + 1, contain);
    }

    return canRemove;
}

bool IsCanRemoveBFS(vector<string> storage, int i, int j, char contain)
{
    bool canRemove = false;

	queue <pair<int, int>> q;
	q.push({ i, j });
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;

		// 외곽인 경우
		if (x - 1 < 0 || x + 1 >= storage.size() || y - 1 < 0 || y + 1 >= storage[x].length())
		{
			canRemove = true;
			break;
		}

		// 상하좌우가 '0'인 경우
		if (storage[x - 1][y] == '0') // 위
			q.push({ x - 1, y });
		if (storage[x + 1][y] == '0') // 아래
			q.push({ x + 1, y });
		if (storage[x][y - 1] == '0') // 왼쪽
			q.push({ x, y - 1 });
		if (storage[x][y + 1] == '0') // 오른쪽
			q.push({ x, y + 1 });
	}

    return canRemove;
}

vector<string> Crane(vector<string> storage, char contain) 
{
    // 1, 2차 시도 시 사용 코드
	/*
    vector<string> tmp;
    for (int i = 0; i < storage.size(); i++)
    {
        string row = storage[i];
        for (int j = 0; j < storage[i].length(); j++)
        {
            if (storage[i][j] == contain)
            {
				// 외부에서 접근이 가능한지 확인
				if(IsCanRemoveBFS(storage, i, j, contain))
					row[j] = '0';
            }
        }
		tmp.push_back(row);
    }
	*/

	int n = storage.size();
	int m = storage[0].length();
	vector<pair<int, int>> toRemove;
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 가장자리에 있는 컨테이너가 아닌 경우 건너뜀
			if (i != 0 && i != n - 1 && j != 0 && j != m - 1) continue;

			if (storage[i][j] == contain)
			{
				toRemove.push_back({ i, j });
			}
			else if(storage[i][j] == '0')
			{
				// '0'인 경우 인접한 컨테이너 탐색
				queue <pair<int, int>> q;
				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();
					int x = cur.first;
					int y = cur.second;

					// 상하좌우 탐색
					int dx[4] = { -1, 1, 0, 0 };
					int dy[4] = { 0, 0, -1, 1 };
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						// 범위 벗어나거나 이미 방문한 경우 건너뜀
						if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
							continue;

						if (storage[nx][ny] == contain)
							toRemove.push_back({ nx, ny });
						else if (storage[nx][ny] == '0')
							q.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
	}

	for (int k = 0; k < toRemove.size(); k++)
	{
		int x = toRemove[k].first;
		int y = toRemove[k].second;
		storage[x][y] = '0';
	}

	return storage;
}

vector<string> forklift(vector<string> storage, char contain)
{
    for(int i =0; i < storage.size(); i++)
    {
        for(int j =0; j < storage[i].length(); j++)
        {
            if (storage[i][j] == contain)
                storage[i][j] = '0';
        }
	}    

    return storage;
}


int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;

    for(int i = 0; i < requests.size(); i++) 
    {
        char contain = requests[i][0];
        if (requests[i].length() == 1)
            storage = Crane(storage, contain);
        else
            storage = forklift(storage, contain);
	}

    // 남은 컨테이너 수
    for (int i = 0; i < storage.size(); i++)
    {
        for (int j = 0; j < storage[i].length(); j++)
        {
            if (storage[i][j] != '0')
                answer++;
		}
    }
    return answer;
}



// 1차 시도 : DFS를 사용했으나 대부분의 테스트 케이스에서 시간 초과 발생
// 2차 시도 : BFS로 변경하여 일부 테스트 케이스에 한하여 시간 초과 문제 해결했으나 여전히 시간 초과 발생

// 3차 시도 : 전부다 확인하는 방식이 아닌 외부에서 시작하여 접근 가능한 컨테이너만 제거하는 방식으로 변경,
//           됐었던 테스트 케이스에서도 실패

// 4차 시도 : Visited 배열을 사용하여 중복 탐색 방지, 모든 테스트 케이스 통과 성공