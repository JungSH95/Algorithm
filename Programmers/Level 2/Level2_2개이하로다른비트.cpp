#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    // x에 대한 함수 f(x)
    // x보다 크고 x와 비트가 1 ~ 2개 다른 수 중에서 가장 작은 수

    // 2 : 0010
	// 4 : 0100
	// 6 : 0110
	// 짝수인 경우 : x + 1

    // 1 : 0001
    //     0010    = > 2 , 1개

	// 3 : 0011
    //     0101     5이고 2개

	// 5 : 0101
	//	   0110     6이고 2개

	// 7 : 0111
	//     1011	    11이고 2개

	for (auto number : numbers) {
        if (number % 2 == 0)
            answer.push_back(number + 1);
        else {
			long long temp = number;
			int count = 0;

            // 가장 오른쪽에 있는 0 위치 찾기
			while (temp % 2 == 1) {
                count += 1;
                temp /= 2;
            }
			
            answer.push_back(number + pow(2, count - 1));
        }
    }

    return answer;
}

// 1차 시도 : 성공
// 예시처럼 차례대로 숫자를 확인하기에는 숫자 범위가 너무 큼
// 규칙을 찾아보니 짝수는 단순했고
// 홀수는 가장 오른쪽에 있는 0 위치를 찾고, 그 위치의 1을 0으로 바꿔주고,
// 그 오른쪽은 1로 바꿔주면 되는 것을 알 수 있었음
