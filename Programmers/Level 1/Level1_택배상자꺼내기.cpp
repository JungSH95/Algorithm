#include <iostream>
using namespace std;

int solution(int n, int w, int num) 
{
    int answer = 0;

    int count = 1;
    int x = 0, y = 0;
	int tar_x = 0, tar_y = 0;
    int parcel[100][10]{ 0, };
    
    // 상자 쌓기
    while(count <= n)
    {
        // 좌로 이동
        for (int j = 0; j < w && count <= n; j++)
        {
            if (count == num)
            {
                tar_x = x;
                tar_y = y;
            }

            parcel[y][x++] = count++;
        }

        y += 1;
        if (x == w)
            x -= 1;

        // 우로 이동
        for (int j = 0; j < w && count <= n; j++)
        {
            if (count == num)
            {
                tar_x = x;
                tar_y = y;
            }

            parcel[y][x--] = count++;
        }

        y += 1;
        if (x < 0)
            x += 1;
    }

	while (parcel[tar_y][tar_x] != 0)
    {
        answer++;
        tar_y++;
    }

    return answer;
}

// 1트 : 테스트 1, 2, 3, 4, 5, 19, 22 실패
// w가 1인경우 박스 수를 제대로 계산하지 못함

// 2트 : 성공


// 다른 사람 풀이를 확인해봄
// 1. vector를 사용하여 2차원 배열을 구현하고, stack을 사용하여 박스를 쌓는 방식을 구현하였다.
// 2. 경이로운 방법 : while(num<=n){answer++;num+=(w-1-(w+num-1)%w)*2+1;}

