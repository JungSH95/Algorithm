#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) 
{
    string answer = "";

    // 최단 거리
	int dist = abs(r - x) + abs(c - y);
	if (dist > k || (k - dist) % 2 != 0)
		return "impossible";

	// 남은 이동 횟수
	int remain = k - dist;

	// 이동 경로
	string path = "";

	// 사전순으로 가장 작은 경로를 만들기 위해
	// 먼저 아래, 왼쪽, 오른쪽, 위 순서로 이동

	// 아래로 이동
	while (x < r)
	{
		path += 'd';
		x++;
	}
	// 왼쪽으로 이동
	while (y > c) 
	{
		path += 'l';
		y--;
	}
	// 오른쪽으로 이동
	while (y < c) 
	{
		path += 'r';
		y++;
	}
	// 위로 이동
	while (x > r) 
	{
		path += 'u';
		x--;
	}

	// 남은 이동 횟수 처리
	while (remain > 0)
	{
		// 아래-위 이동			
		if (x + 1 <= n)
		{
			path += 'd';
			path += 'u';
			remain -= 2;
		}

		// 왼쪽-오른쪽 이동
		else if (y - 1 >= 1)
		{
			path += 'l';
			path += 'r';
			remain -= 2;
		}

		// 오른쪽-왼쪽 이동
		else if (y + 1 <= m)
		{
			path += 'r';
			path += 'l';
			remain -= 2;
		}

		// 위-아래 이동
		else if (x - 1 >= 1)
		{
			path += 'u';
			path += 'd';
			remain -= 2;
		}
	}

	answer = path;
    return answer;
}

string solution1(int n, int m, int x, int y, int r, int c, int k)
{
	string answer = "";

	// 최단 거리
	int dist = abs(r - x) + abs(c - y);
	
	// 불가능한 경우 처리
	if (dist > k || (k - dist) % 2 != 0)
		return "impossible";

	// d > l > rl 순서로 최대한 이동해야 사전순으로 가장 작은 경로가 됨

	// 아래 이동
	while (dist < k && x < n)
	{
		x++;
		k--;
		dist = abs(r - x) + abs(c - y);
		answer += "d";
	}

	// 왼쪽 이동
	while (dist < k && y > 1)
	{
		y--;
		k--;
		dist = abs(r - x) + abs(c - y);
		answer += "l";
	}

	// 남은 이동(rl) 처리
	while (dist < k)
	{
		k -= 2;
		answer += "rl";
	}

	// 아래로 이동
	while (x < r)
	{
		x++;
		answer += 'd';
	}
	// 왼쪽으로 이동
	while (y > c)
	{
		y--;
		answer += 'l';
	}
	// 오른쪽으로 이동
	while (y < c)
	{
		y++;
		answer += 'r';
	}
	// 위로 이동
	while (x > r)
	{
		x--;
		answer += 'u';
	}

	return answer;
}

// 1차 시도 : 실패, 테스트 4 ~ 30번까지 실패
// 너무 단순하게 생각한듯 많은 테스트 케이스를 고려하지 못함

// 2차 시도 : 성공, 최대한 사전순으로 먼저 이동하는 방법으로 변경

// 코드가 지저분하지만 다른 사람들이 풀었던 dfs나 bfs보다 속도가 빨라서 만족