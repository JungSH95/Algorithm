#include <iostream>
using namespace std;

int main(void)
{
	long A, B, V;
	cin >> A >> B >> V;

	long answer = (V - B) / (A - B);
	if ((V - B) % (A - B) != 0)
		answer++;

	cout << answer;
	return 0;
}

/*
문제 순위에 있는거 문제 이름 재미있고 정답 비율 낮아서 골랐는데
이게 왜 낮은거야;

몇개의 낮 밤 높이를 테스트 해봤을때 N을 구하는 공식이 나옴

V = A * N - B(N -1)
N = (V - B) / (A - B)
*/