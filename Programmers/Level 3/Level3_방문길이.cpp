#include <string>
#include <vector>
using namespace std;

int solution(string dirs) {
	int answer = 0;

	vector<vector<int>> way;    // ������ ��� ����
	int x = 0, y = 0;

	for (int i = 0; i < dirs.length(); i++)
	{
		// ������ǥ
		vector<int> temp;
		temp.push_back(x);
		temp.push_back(y);

		// �̵���Ŵ (���� �ʰ� ��ŵ)
		switch (dirs[i])
		{
		case 'U':
			if (y == 5)
				continue;
			y++;
			break;
		case 'D':
			if (y == -5)
				continue;
			y--;
			break;
		case 'R':
			if (x == 5)
				continue;
			x++;
			break;
		case 'L':
			if (x == -5)
				continue;
			x--;
			break;
		}

		// �ش� ��ǥ�� ó���ΰ�?
		bool check = false;
		for (int j = 0; j < way.size(); j++)
			// A -> B �� B -> A �� ������
			if (way[j][0] == temp[0] && way[j][1] == temp[1] &&
				way[j][2] == x && way[j][3] == y ||
				way[j][0] == x && way[j][1] == y &&
				way[j][2] == temp[0] && way[j][3] == temp[1])
			{
				check = true;
				break;
			}

		// ������ ���� �ƴϴ�.
		if (!check)
		{
			answer++;

			temp.push_back(x);
			temp.push_back(y);
			way.push_back(temp);
		}
	}

	return answer;
}

/*
level 3 ġ��� ������.
���� �����̳ʸ� ����Ͽ� �����ǥ�� ������ǥ�� �����Ͽ� ���������� üũ�ߴ�.

üũ�Ҷ��� �� �ش���� ����ϴ� ����� �Ʒ��� ���� 2�����̹Ƿ�
A -> B
B -> A    ��ó�� �ش� ���� ��밡��

�� üũ�� 2���� �� üũ�Ͽ� Ȯ���Ͽ���.
*/