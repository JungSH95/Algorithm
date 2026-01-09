#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string wheel_arr[4];				// 톱니바퀴 N/S극 정보
int wheel_rotation[4];
int pos_12[4] = { 0, };				// 12시의 위치 보유

// 해당 톱니바퀴의 왼쪽(6) 위치 반환
int getLeftNumber(int wheel_num)
{
	int temp = pos_12[wheel_num] - 2;
	if (temp < 0)
		temp += 8;

	return temp;
}

// 해당 톱니바퀴의 오른쪽(2) 위치 반환
int getRightNumber(int wheel_num)
{
	int temp = pos_12[wheel_num] + 2;
	if (temp > 7)
		temp -= 8;

	return temp;
}

int main()
{
	// 톱니바퀴 N/S극 입력
	for (int i = 0; i < 4; i++)
		cin >> wheel_arr[i];

	// 톱니바퀴 회전 수
	int rotation_count;
	cin >> rotation_count;

	for (int i = 0; i < rotation_count; i++)
	{
		int whell_number, rotation_dir;
		cin >> whell_number >> rotation_dir;
		wheel_rotation[whell_number - 1] = rotation_dir;

		// 왼쪽 방향
		for (int j = whell_number - 1; j > 0; j--)
		{
			// 회전을 안하면 다음꺼도 회전 안함
			if (wheel_rotation[j] == 0)
			{
				wheel_rotation[j - 1] = 0;
				continue;
			}

			// 같지 않으면 회전
			if (wheel_arr[j - 1][getRightNumber(j - 1)] != wheel_arr[j][getLeftNumber(j)])
				wheel_rotation[j - 1] = wheel_rotation[j] * -1;
			// 같으면 회전 안함
			else
				wheel_rotation[j - 1] = 0;
		}

		// 오른쪽 방향
		for (int j = whell_number - 1; j < 3; j++)
		{
			// 회전을 안하면 다음꺼도 회전 안함
			if (wheel_rotation[j] == 0)
			{
				wheel_rotation[j + 1] = 0;
				continue;
			}

			// 같지 않으면 회전
			if (wheel_arr[j][getRightNumber(j)] != wheel_arr[j + 1][getLeftNumber(j + 1)])
				wheel_rotation[j + 1] = wheel_rotation[j] * -1;
			// 같으면 회전 안함
			else
				wheel_rotation[j + 1] = 0;
		}

		// 회전 적용
		for (int j = 0; j < 4; j++)
		{
			if (wheel_rotation[j] == 1)
			{
				pos_12[j] -= 1;
				if (pos_12[j] < 0)
					pos_12[j] = 7;
			}
			else if (wheel_rotation[j] == -1)
			{
				pos_12[j] += 1;
				if (pos_12[j] > 7)
					pos_12[j] = 0;
			}
		}
	}

	int total_score = 0;
	for (int i = 0; i < 4; i++)
	{
		if (wheel_arr[i][pos_12[i]] == '1')
			total_score += pow(2, i);
	}
	cout << total_score;
	return 0;
}

/*
뭔가 푸는 재미가 있었던 문제
회전시키는 톱니바퀴를 기준으로 왼쪽과 오른쪽을 진행시켜 각 톱니바퀴의 회전 방향을 알아낸 후
12시를 가르키는 pos_12를 사용하여 12시의 위치를 저장하였다.
톱니바퀴의 각 왼쪽과 오른쪽을 구할 수 있는 함수를 사용하여 바로 비교하여 사용하도록 했다.
*/