#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> number;

	// �� �ڸ��� �� ���ϱ�
	while (N)
	{
		number.push_back(N % 10);
		N /= 10;
	}

	sort(number.begin(), number.end(), greater<>());
	for (int i = 0; i < number.size(); i++)
		cout << number[i];

	return 0;
}


/*
������ ������� �����ʾ� ���������� �����ϰ� �ٷ� Ǯ �� �ִ� ������ �Ӹ��� Ǯ����.
���ڸ� �Է� ������ �� ���ڸ� ���� �������� �ٽ� ����ϴ� ������.

���� �� �ڸ� ���� ���� ���� ���Ϳ� ���� �־� �����صΰ� ���� �Լ��� sort() ����Ͽ�
������������ �����Ͽ���.
*/
