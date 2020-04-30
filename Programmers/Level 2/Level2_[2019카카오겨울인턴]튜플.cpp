#include <string>
#include <vector>
#include <queue>
using namespace std;

struct compare{
	bool operator()(vector<int> job1, vector<int> job2)
	{
		return job1.size() > job2.size();
	}
};

vector<int> solution(string s) {
	vector<int> answer;
	// 사이즈가 작은 순으로
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;

	vector<int> temp;
	string num = "";
	bool bIn = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num += s[i];
			bIn = true;
			continue;
		}

		// 집합 끝(마지막 숫자)
		if (s[i] == '}' && num.size() != 0)
		{
			temp.push_back(stoi(num));
			pq.push(temp);
			temp.clear();
			num = "";
			bIn = false;
		}

		// 다음 숫자
		if (s[i] == ',' && bIn == true)
		{
			temp.push_back(stoi(num));
			num = "";
		}
	}

	while (!pq.empty())
	{
		vector<int> tuple = answer;
		temp = pq.top();
		pq.pop();

		int cursor = 0;
		for (int i = 0; i < temp.size(); i++)
			for (int j = 0; j < tuple.size(); j++)
				// 같은 값 처리
				if (temp[i] == tuple[j] && temp[i] != -1)
				{
					temp[i] = -1;
					tuple[j] = -1;
					break;
				}

		// 다른 값 위치
		for (int i = 0; i < temp.size(); i++)
			if (temp[i] != -1)
				cursor = i;

		if (temp.size() != tuple.size())
			answer.push_back(temp[cursor]);
	}

	return answer;
}

/*
어렵게 생각하는 바람에 오래걸렸던 문제.

차근차근 단계별로 풀어나가는 생각을 하도록하자.

1. 문자열 분리하여 값들 벡터에 넣기
2. size로 정렬
3. 1개씩 추가하면 끝 !
*/