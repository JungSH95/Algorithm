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
���� ������ �ִ°� ���� �̸� ����ְ� ���� ���� ���Ƽ� ����µ�
�̰� �� �����ž�;

��� �� �� ���̸� �׽�Ʈ �غ����� N�� ���ϴ� ������ ����

V = A * N - B(N -1)
N = (V - B) / (A - B)
*/