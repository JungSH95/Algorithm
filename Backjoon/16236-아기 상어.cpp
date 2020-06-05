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
// ���� ����� ã��
int target_x = 99, target_y = 99, now_dist = 99, fish_number = -1;
bool Istarget = false;
for (int i = 0; i < fish_list.size(); i++)
{
if (fish_list[i].size >= shark_size)
break;
// ���� �� �ִ� ������̸� �Ÿ� üũ
else if (fish_list[i].size != 0)
{
// �Ÿ� ����
int dist = abs(fish_list[i].x - shark_x) + abs(fish_list[i].y - shark_y);
Istarget = true;

// �Ÿ��� ���ٸ� ���� ���� �ִ� ����� and ���� ���ʿ� �ִ� �����
if (dist == now_dist)
{
// ���� ���� �ִ� �����
if (target_x > fish_list[i].x)
{
now_dist = dist;
target_x = fish_list[i].x;
target_y = fish_list[i].y;
fish_number = i;
}
else if (target_x == fish_list[i].x)
{
// ���� ���ʿ� �ִ� �����
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

// ���� �� �ִ� ����Ⱑ ������ ����
if (!Istarget)
return time;
else
{
// ����� �Ա�
fish_list[fish_number].size = 0;
shark_eat_count++;
time += now_dist;

map[shark_x][shark_x] = 0;
map[target_x][target_y] = 9;

shark_x = target_x;
shark_y = target_y;

cout << "����" << "(" << map[target_x][target_y] << ")" << " : " << target_x << ", " << target_y << " �ð� : " << time << "������ : " << shark_eat_count<< endl;

// ũ�� ����
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
// ũ�� ������ ����
sort(fish_list.begin(), fish_list.end(), compare);
cout << "time : " << SharkEatStart() << endl;

return 0;
}
*/

/*
���� �� �� ���� .. ��

�Ʊ� ���� �ڽ��� ũ�⺸�� ū ����Ⱑ �ִ� ĭ�� ������ �� ����,
������ ĭ�� ��� ������ �� �ִ�. �Ʊ� ���� �ڽ��� ũ�⺸�� ���� ����⸸ ���� �� �ִ�.
����, ũ�Ⱑ ���� ������ ���� �� ������, �� ����Ⱑ �ִ� ĭ�� ������ �� �ִ�.
-> �� ������ �߰� ���ؼ� ����

�������� ��ǥ�� ũ�⸦ �����ؼ� ���� �� �ִ� ������ �߿� ���� ����� ���� ã�Ƽ�
���� �� �� �̵� �������� �ڽ� ���� ū ����Ⱑ �ִ� ���� �������� ���ϹǷ�
�ִ� �Ÿ��� �̵��� ���Ѵ� ������ ���� �̵��ϸ� ���� �� �����鼭 �ִ� �Ÿ��� �ִ� ���� ã�ƾ� ��

���� or �ʺ� Ž�� -> ����� ��ġ���� �а� Ž���� �ؾ� �ϹǷ� �ʺ� Ž�� �����Ͽ� ����
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
	// �Ÿ� �� ���� ����
	if (f1.dist < f2.dist)
		return true;
	else if (f1.dist == f2.dist)
	{
		// �Ÿ��� ���ٸ� ���� �ִ� �ͺ���
		if (f1.x < f2.x)
			return true;
		else if (f1.x == f2.x)
		{
			// ������ ���̿� �ִٸ� ���ʺ���
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
		// ���� ����� ã��
		vector<FishInfo> search_fish;
		memset(visit, 0, sizeof(visit));

		queue<pair<pair<int, int>, int>> q;		// bfs ����
		q.push(make_pair(make_pair(shark_x, shark_y), 0));		// ��� ��ġ �ֱ�
		visit[shark_x][shark_y] = true;
		int min_dist = -1;

		while (!q.empty())
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int dist = q.front().second;
			q.pop();

			// ã�� �� ��ġ���� �� �� �Ÿ� ã�� X
			if (min_dist == dist)
				break;

			// �����¿� �̵�
			for (int i = 0; i < 4; i++)
			{
				int next_x = x + dx[i];
				int next_y = y + dy[i];

				// �ùٸ� ���� üũ
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
				{
					// �湮���� ��
					if (!visit[next_x][next_y])
					{
						visit[next_x][next_y] = true;
						// �̵� ������ ũ�� üũ
						if (shark_size >= map[next_x][next_y])
						{
							// ��ο� �߰�
							q.push(make_pair(make_pair(next_x, next_y), dist + 1));

							// ���� �� �ִ� �������
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


		// ���� �� �ִ� ����Ⱑ ������ ����
		if (search_fish.empty())
			return time;
		else
		{
			// ����� �Ա�
			sort(search_fish.begin(), search_fish.end(), compare);
			time += search_fish[0].dist;

			// ��� �̵�
			map[search_fish[0].x][search_fish[0].y] = 9;	// ����� ��ġ�� ���
			map[shark_x][shark_y] = 0;						// ��� ��ġ�� 0
			shark_x = search_fish[0].x;
			shark_y = search_fish[0].y;

			shark_eat_count++;

			// ũ�� ����
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
�̹� ������ ���ؼ� �ʺ� Ž���� �� �� �ͼ��� ����.
�˰����� �̹� ���õǾ� �ִ� �����̱� ������ ���� ���� �� ����.
�ٸ� �ʹݿ� ������ ������ �� �� �ô� ������ ���� �ð��� ���� ���� �ƽ���.
*/