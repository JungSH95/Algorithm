#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 효율성 떨어짐, 길이가 길 때 더 클 경우에 대하여 에러 발생
/*
string solution(vector<int> numbers) {
	string answer = "";

	int cursor;
	int maxNumber = 0;
	int minNumberLength = 4;

	while (!numbers.empty())
	{
		cursor = 0;
		maxNumber = 0;
		minNumberLength = 4;

		for (int i = 0; i < numbers.size(); i++)
		{
			int num = numbers[i];
			int numberLength = 0;

			while (num / 10 != 0)
			{
				num = num / 10;
				numberLength++;
			}

			if (maxNumber < num)
				if (minNumberLength >= numberLength)
				{
					maxNumber = num;
					minNumberLength = numberLength;
					cursor = i;
				}
		}

		answer += to_string(numbers[cursor]);
		numbers.erase(numbers.begin() + cursor);
	}

	return answer;
}
*/

// 다른 사람 풀이

// 정렬에 사용 할 비교 함수 (합친 문자를 비교해서 큰 순으로 정렬)
bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> temp;

	// 문자열의 형태로 보관
	for (auto num : numbers)
		temp.push_back(to_string(num));

	// 정렬
	sort(temp.begin(), temp.end(), cmp);

	// 예외처리 처음 숫자가 0일 경우
	if (temp.at(0) == "0")
		return "0";

	// 처음부터 끝까지 문자열을 합침
	for (auto num : temp)
		answer += num;

	return answer;
}