#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	

	// 예외 n개의 합보다 s가 작을 경우
	if (n > s)
		answer.push_back(-1);
	else
	{
		int num = s / n;            // 몫
		int remainder = s % n;      // 나머지

		for (int i = 0; i < n; i++)
		{
			if (remainder != 0)
			{
				remainder--;
				answer.push_back(num + 1);
			}
			else
				answer.push_back(num);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}


/*
1차 시도
- 효율성 테스트 6번만 성공, 1~5번 전부 실패 ㅠㅠ
*/



#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;

	// 예외 n개의 합보다 s가 작을 경우
	if (n > s)
		answer.push_back(-1);
	else
	{
		int num = s / n;            // 몫
		int remainder = s % n;      // 나머지

		for (int i = 0; i < n; i++)
			answer.push_back(num);
		for (int i = answer.size() - 1; i > 0 && remainder != 0; i--)
		{
			answer[i]++;
			remainder--;
		}
	}

	return answer;
}

/*
2차시도 성공
: 정렬을 빼고 순서에 맞게끔 뒤에부터 값을 증가시킴
: 생각보다 sort의 소모값이 큰 것으로 확인
*/