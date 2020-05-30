#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main()
{
	cin >> N;

	// 각 사면체의 필요한 수 구하기
	int temp = 1, total = temp;
	vector<int> tetrahedron;
	tetrahedron.push_back(total);

	// 대포알의 최대 수는 300000
	while (temp++)
	{
		total += temp * (temp + 1) / 2;
		if (total > 300000)
			break;
		tetrahedron.push_back(total);
	}

	// 탄환의 수 만큼 크기 설정
	vector<int> minSize;
	minSize.resize(300001);
	for (int i = 1; i < 300001; i++)
		minSize[i] = 300001;

	// 한번에 만들 수 있는 사면체들은 1로 변경
	for (int i = 0; i < tetrahedron.size(); i++)
		minSize[tetrahedron[i]] = 1;

	// minSize[j - tetrahedron[i]] 반복문을 통해서 각 탄환의 수로 만들 수 있는
	// 사면체의 최소 값들을 넣어준다.
	for (int i = 0; i < tetrahedron.size(); i++)
		for (int j = tetrahedron[i]; j <= N; j++)
			minSize[j] = min(minSize[j], minSize[j - tetrahedron[i]] + 1);

	cout << minSize[N];

	return 0;
}

/*
15 : 10, 4, 1 => 3개

각 층 별 필요한 개수 1, 3, 6, 10, 15
=> 증가 2, 3, 4, 5, 6 ~~~~ ==> n*(n+1) / 2
N 사면체 : 1, 4, 10, 20

최소라서 단순히 가장 큰 값부터 빼려고 했지만 불가능
50일 경우 가장 큰 값부터 한다면 35, 10, 4, 1 로 4개
다른 방법으로 한다면 20, 20, 10 으로 3개가 최적해다

어떻게 풀어야 시간 초과를 안내고 풀 수 있을지 결국 포기
아래 링크의 풀이를 사용했다.
https://ksh-code.tistory.com/106

탄환의 수 만큼의 벡터를 선언해주어 해당 배열과 동일한 탄환을 사용하는 것의 경우
1번만에 만들 수 있기 때문에 해당 값은 1로 값을 넣어준다.

minSize는 탄환의 수가 tetrahedron[i] 는 사면체에 필요한 탄환의 수가 들어가 있기 때문에
minSize[j - tetrahedron[i]]와 비교하면서 작은 값들을 넣어주면 해당 탄환의 수로
만들 수 있는 사면체의 최소 수가 들어가게 된다.
*/
