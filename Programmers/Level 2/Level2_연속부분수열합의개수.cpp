#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> elements) 
{    
	int n = 0;
	//map<int, int> numberMap;
	set<int> numberSet;
    while (n < elements.size())
    {
        n++;

        for (int i = 0; i < elements.size(); i++)
        {
            int sum = 0;

            for (int j = 0; j < n; j++)
                sum += elements[(i + j) % elements.size()];

			//numberMap[sum]++;
			numberSet.insert(sum);
		}
    }
    return numberSet.size();
}

// 1차 시도 : 성공, 테스트 케이스들의 시간이 오래걸림
// 다른 사람들의 풀이를 보니 시간복잡도가 O(n^2)인 풀이들이 많았음
// map 대신 set을 사용한 풀이들이 있었음, 시간 차이는 크지 않았음

