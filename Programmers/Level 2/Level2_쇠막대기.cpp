#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	vector<int> laser_count;

	for (int i = 0; i < arrangement.length() - 1; i++)
	{
		// ���� ��ȣ�ϰ�� (�� or ������)
		if (arrangement[i] == '(')
		{
			// �������ϰ��
			if (arrangement[i + 1] == ')')
				for (int j = 0; j < laser_count.size(); j++)
					laser_count[j]++;
			// ���ϰ��
			else if (arrangement[i + 1] == '(')
				laser_count.push_back(0);
		}
		else if (arrangement[i] == ')')
		{
			// ���� ��
			if (arrangement[i + 1] == ')')
			{
				answer += (laser_count.back() + 1);
				laser_count.pop_back();
			}
		}
	}

	return answer;
}