#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> answer;
void Move(int n, int from, int to)
{
	//cout << "n : " << from << "���� " << to << "���� �̵�" << endl;
	vector<int> v;
	v.push_back(from);
	v.push_back(to);

	answer.push_back(v);
}

void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
		Move(n, from, to);
	else
	{
		hanoi(n - 1, from, to, by);		// ���1�� �ִ� n-1���� ������ ���2�� �̵�
		Move(n, from, to);				// ���1�� ���� ������ ���3���� �̵�
		hanoi(n - 1, by, from, to);				// ���2�� �ִ� ������ ���3���� �̵�
	}
}

vector<vector<int>> solution(int n) {
	hanoi(n, 1, 2, 3);
	return answer;
}


/*
������ �˰��� �ϳ����� ž

������ �б����� Ǯ��ô� ��������, �ٽ� Ǫ���ϱ� �� �򰥷���.
*/