#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
struct FishInfo
{
int x;
int y;
int size;

FishInfo(int _x, int _y, int _size)
: x(_x), y(_y), size(_size){}
};

bool compare(const FishInfo fi1, const FishInfo fi2)
{
if (fi1.size < fi2.size)
return true;
else
return false;
}

int map[20][20];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int shark_size = 2, shark_eat_count = 0;
int shark_x, shark_y;

vector<FishInfo> fish_list;

int SharkEatStart()
{
int time = 0;

while (true)
{
// 먹을 물고기 찾기
int target_x = 99, target_y = 99, now_dist = 99, fish_number = -1;
bool Istarget = false;
for (int i = 0; i < fish_list.size(); i++)
{
if (fish_list[i].size >= shark_size)
break;
// 먹을 수 있는 물고기이면 거리 체크
else if (fish_list[i].size != 0)
{
// 거리 측정
int dist = abs(fish_list[i].x - shark_x) + abs(fish_list[i].y - shark_y);
Istarget = true;

// 거리가 같다면 가장 위에 있는 물고기 and 가장 왼쪽에 있는 물고기
if (dist == now_dist)
{
// 가장 위에 있는 물고기
if (target_x > fish_list[i].x)
{
now_dist = dist;
target_x = fish_list[i].x;
target_y = fish_list[i].y;
fish_number = i;
}
else if (target_x == fish_list[i].x)
{
// 가장 왼쪽에 있는 물고기
if (target_y > fish_list[i].y)
{
now_dist = dist;
target_x = fish_list[i].x;
target_y = fish_list[i].y;
fish_number = i;
}
}
}
else if (dist < now_dist)
{
now_dist = dist;
target_x = fish_list[i].x;
target_y = fish_list[i].y;
fish_number = i;
}
}
}

// 먹을 수 있는 물고기가 없으면 종료
if (!Istarget)
return time;
else
{
// 물고기 먹기
fish_list[fish_number].size = 0;
shark_eat_count++;
time += now_dist;

map[shark_x][shark_x] = 0;
map[target_x][target_y] = 9;

shark_x = target_x;
shark_y = target_y;

cout << "먹자" << "(" << map[target_x][target_y] << ")" << " : " << target_x << ", " << target_y << " 시간 : " << time << "먹은수 : " << shark_eat_count<< endl;

// 크기 증가
if (shark_size == shark_eat_count)
{
shark_size++;
shark_eat_count = 0;
}
}
}
}

int main() {

int N;
cin >> N;

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
{
cin >> map[i][j];

if (map[i][j] == 9)
{
shark_x = i;
shark_y = j;
}
else if (map[i][j] != 0)
{
FishInfo newFish(i, j, map[i][j]);
fish_list.push_back(newFish);
}
}

cout << endl << endl;
// 크기 순으로 정렬
sort(fish_list.begin(), fish_list.end(), compare);
cout << "time : " << SharkEatStart() << endl;

return 0;
}
*/

/*
문제 잘 좀 읽자 .. ㅠ

아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고,
나머지 칸은 모두 지나갈 수 있다. 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.
따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
-> 이 조건을 추가 안해서 실패

물고기들의 좌표와 크기를 저장해서 먹을 수 있는 물고기들 중에 가장 가까운 것을 찾아서
먹은 후 상어를 이동 시켰으나 자신 보다 큰 물고기가 있는 곳은 지나가지 못하므로
최단 거리로 이동을 못한다 때문에 길을 이동하며 먹을 수 있으면서 최단 거리에 있는 것을 찾아야 함

깊이 or 너비 탐색 -> 상어의 위치에서 넓게 탐색을 해야 하므로 너비 탐색 선택하여 수정
*/

struct FishInfo
{
	int x;
	int y;
	int dist;

	FishInfo(int _x, int _y, int _dist)
		: x(_x), y(_y), dist(_dist){}
};

bool compare(const FishInfo f1, const FishInfo f2)
{
	// 거리 순 오름 차순
	if (f1.dist < f2.dist)
		return true;
	else if (f1.dist == f2.dist)
	{
		// 거리가 같다면 위에 있는 것부터
		if (f1.x < f2.x)
			return true;
		else if (f1.x == f2.x)
		{
			// 동일한 높이에 있다면 왼쪽부터
			if (f1.y < f2.y)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int N;
int map[20][20];
bool visit[20][20];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int shark_size = 2, shark_eat_count = 0;
int shark_x, shark_y;

int SharkEatStart()
{
	int time = 0;

	while (true)
	{
		// 먹을 물고기 찾기
		vector<FishInfo> search_fish;
		memset(visit, 0, sizeof(visit));

		queue<pair<pair<int, int>, int>> q;		// bfs 시작
		q.push(make_pair(make_pair(shark_x, shark_y), 0));		// 상어 위치 넣기
		visit[shark_x][shark_y] = true;
		int min_dist = -1;

		while (!q.empty())
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int dist = q.front().second;
			q.pop();

			// 찾은 곳 위치보다 더 먼 거리 찾기 X
			if (min_dist == dist)
				break;

			// 상하좌우 이동
			for (int i = 0; i < 4; i++)
			{
				int next_x = x + dx[i];
				int next_y = y + dy[i];

				// 올바른 범위 체크
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
				{
					// 방문안한 곳
					if (!visit[next_x][next_y])
					{
						visit[next_x][next_y] = true;
						// 이동 가능한 크기 체크
						if (shark_size >= map[next_x][next_y])
						{
							// 경로에 추가
							q.push(make_pair(make_pair(next_x, next_y), dist + 1));

							// 먹을 수 있는 물고기라면
							if (map[next_x][next_y] != 0 && shark_size > map[next_x][next_y])
							{
								FishInfo fish(next_x, next_y, dist + 1);
								search_fish.push_back(fish);
								min_dist = dist + 1;
							}
						}
					}
				}
			}
		}


		// 먹을 수 있는 물고기가 없으면 종료
		if (search_fish.empty())
			return time;
		else
		{
			// 물고기 먹기
			sort(search_fish.begin(), search_fish.end(), compare);
			time += search_fish[0].dist;

			// 상어 이동
			map[search_fish[0].x][search_fish[0].y] = 9;	// 물고기 위치에 상어
			map[shark_x][shark_y] = 0;						// 상어 위치에 0
			shark_x = search_fish[0].x;
			shark_y = search_fish[0].y;

			shark_eat_count++;

			// 크기 증가
			if (shark_size == shark_eat_count)
			{
				shark_size++;
				shark_eat_count = 0;
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 9)
			{
				shark_x = i;
				shark_y = j;
			}
		}

	cout << SharkEatStart();
	return 0;
}

/*
이번 문제를 통해서 너비 탐색에 좀 더 익숙해 졌다.
알고리즘은 이미 제시되어 있는 문제이기 때문에 쉬운 편인 것 같다.
다만 초반에 문제의 조건을 잘 못 봤던 것으로 인해 시간을 날린 것이 아쉽다.
*/