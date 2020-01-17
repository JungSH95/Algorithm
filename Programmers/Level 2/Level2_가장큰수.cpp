#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ȿ���� ������, ���̰� �� �� �� Ŭ ��쿡 ���Ͽ� ���� �߻�
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

// �ٸ� ��� Ǯ��

// ���Ŀ� ��� �� �� �Լ� (��ģ ���ڸ� ���ؼ� ū ������ ����)
bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> temp;

	// ���ڿ��� ���·� ����
	for (auto num : numbers)
		temp.push_back(to_string(num));

	// ����
	sort(temp.begin(), temp.end(), cmp);

	// ����ó�� ó�� ���ڰ� 0�� ���
	if (temp.at(0) == "0")
		return "0";

	// ó������ ������ ���ڿ��� ��ħ
	for (auto num : temp)
		answer += num;

	return answer;
}