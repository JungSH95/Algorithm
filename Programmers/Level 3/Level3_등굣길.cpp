#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0, weight[101][101] = { 0, };

	// ��
	weight[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1)
				continue;

			bool check = false;

			// ħ�� ���� üũ
			for (int k = 0; k < puddles.size(); k++)
				if (i == puddles[k].at(1) && j == puddles[k].at(0))
				{
					weight[i][j] = 0;
					check = true;
					break;
				}

			// ħ������ �ƴϸ� ���� ������ ����ġ ���ϱ�
			if (!check)
				weight[i][j] = (weight[i - 1][j] + weight[i][j - 1]) % 1000000007;
		}
	}

	answer = weight[n][m];
	return answer;
}

/*
ó�� Ǯ���� ����� DFS�� ���������� ȿ�������� ���� �����ߴ�.
�ᱹ ���� ī�װ���� ������ȹ���� ����Ͽ� �ٽ� �ڵ� ®��.
�ٵ� ������ȹ���� �ߴµ��� �ұ��ϰ� ȿ���� �׽�Ʈ � ����.

���ϱ� ��� ���ٰ� �����ϰ� ħ�� ���� üũ�ϴ� �κ��� ������ ��� ����ߴ�....
�̷� ����� �͵� ������ �� �����غ��߰ڴ�.

// �������� ���� ���� �ڵ� ----------------------------
for (int k = 0; k < puddles.size(); k++)
{
	vector<int> temp = puddles[k];
	if (i == temp.at(1) && j == temp.at(0))
	{
		weight[i][j] = 0;
	check = true;
	break;
	}
}
// --------------------------------------------------


*/