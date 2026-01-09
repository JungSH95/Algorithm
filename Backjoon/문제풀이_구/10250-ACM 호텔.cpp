#include <iostream>
#include <cstring>
using namespace std;

/*
T : 테스트 케이스 수
H : 호텔의 층 수
W : 각 층의 방 수
N : 몇 번째 손님
*/
int T, H, W, N;
int arr[100][100];

int main()
{
	cin >> T;

	// 테스트 케이스 수 만큼 반복
	for (int i = 0; i < T; i++)
	{
		cin >> H >> W >> N;

		cin >> H >> W >> N;
		int H_result = N % H;
		int W_result = N / H;

		if (H_result > 0)
			W_result++;
		else
			H_result = H;
		cout << H_result * 100 + W_result << endl;
	}

	return 0;
}

/*
엘레베이터에 가깝도록 손님이 온 순서대로 배치하는 것.
무조건 왼쪽 1호실부터 채우면 되기 때문에 손님을 층수로 나눈 나머지로 층수를 알 수 있고
몫을 통해 몇호실인지 확인할 수 있다.
*/