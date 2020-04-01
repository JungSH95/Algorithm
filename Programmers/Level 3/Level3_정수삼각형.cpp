#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	for (int i = 0; i < triangle.size() - 1; i++)
	{
		vector<int> temp = triangle[i];
		vector<int> nextLine = triangle[i + 1];

		// 다음 줄 가능한 최대 숫자로 설정
		for (int j = 0; j < temp.size() - 1; j++)
		{
			int left = nextLine[j] + temp[j];
			int right = nextLine[j + 1] + temp[j];

			if (left >= triangle[i + 1][j])
				triangle[i + 1][j] = left;
			if (right >= triangle[i + 1][j + 1])
				triangle[i + 1][j + 1] = right;

			if (answer <= left || answer <= right)
				if (left >= right)
					answer = left;
				else
					answer = right;
		}
	}

	return answer;
}


/*
동적계획법에 감히 잡힌듯 하다.
문제가 level3 치고는 쉬운 것인것 같기도 하다.
*/