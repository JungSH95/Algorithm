#include<iostream>
using namespace std;

char pan[50][50];
char copy_pan[8][8];

int changeColor()
{
	int count = 0;

	// 복제판 유지 위해 (시작 B, W 두 가지 경우 체크해야함)
	char new_pan[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			new_pan[i][j] = copy_pan[i][j];


	// 첫 번째 판을 기준으로 돌렸을때
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			// 이전 판과 비교
			if (new_pan[i][j - 1] == 'B' && new_pan[i][j] == 'B')
			{
				count++;
				new_pan[i][j] = 'W';
			}
			else if (new_pan[i][j - 1] == 'W' && new_pan[i][j] == 'W')
			{
				count++;
				new_pan[i][j] = 'B';
			}
		}

		// 다음 판 첫번째 변경, 가능한 범위의 판 일경우
		if (i + 1 < 8)
		{
			// 이전 판의 처음이 B이면 다음 판의 시작은 W
			if (new_pan[i][0] == 'B' && new_pan[i + 1][0] == 'B')
			{
				new_pan[i + 1][0] = 'W';
				count++;
			}
			else if (new_pan[i][0] == 'W' && new_pan[i + 1][0] == 'W')
			{
				new_pan[i + 1][0] = 'B';
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int N, M;
	cin >> N >> M;

	int min = 999;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> pan[i][j];

	// 가능한 체스판 순회
	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++)
		{
			for (int x = 0; x < 8; x++)
				for (int y = 0; y < 8; y++)
					copy_pan[x][y] = pan[i + x][j + y];

			int num1, num2;
			// 시작이 B일 경우
			if (copy_pan[0][0] == 'B')
			{
				num1 = changeColor();

				// 시작이 W로 변경했을 경우
				copy_pan[0][0] = 'W';
				num2 = changeColor() + 1;
			}
			else if (copy_pan[0][0] == 'W')
			{
				num1 = changeColor();

				// 시작이 B로 변경했을 경우
				copy_pan[0][0] = 'B';
				num2 = changeColor() + 1;
			}

			if (num1 >= num2)
			{
				if (min >= num2)
					min = num2;
			}
			else
				if (min >= num1)
					min = num1;
		}

	cout << min;
	return 0;
}



/*

처음 테스트 시 실패

원인 : 첫 문자를 기준으로 확인한다. 만약 첫번째가 W를 B로만 변경했을때 1번으로 끝나는 것을
나는 전부 변경해버림 때문에 실패

해결 : 첫글자 B기준과 W기준으로 했을때 카운트한뒤 더 작은 값을 체크

*/