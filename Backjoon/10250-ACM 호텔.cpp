#include <iostream>
#include <cstring>
using namespace std;

/*
T : �׽�Ʈ ���̽� ��
H : ȣ���� �� ��
W : �� ���� �� ��
N : �� ��° �մ�
*/
int T, H, W, N;
int arr[100][100];

int main()
{
	cin >> T;

	// �׽�Ʈ ���̽� �� ��ŭ �ݺ�
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
���������Ϳ� �������� �մ��� �� ������� ��ġ�ϴ� ��.
������ ���� 1ȣ�Ǻ��� ä��� �Ǳ� ������ �մ��� ������ ���� �������� ������ �� �� �ְ�
���� ���� ��ȣ������ Ȯ���� �� �ִ�.
*/