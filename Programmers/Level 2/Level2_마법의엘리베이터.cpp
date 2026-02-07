#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
        int digit = storey % 10;
        if (digit < 5) {
            answer += digit;
            storey /= 10;
        }
        else if (digit > 5) {
            answer += (10 - digit);
            storey = storey / 10 + 1;
        }
        else { // digit == 5
            int next_digit = (storey / 10) % 10;
            if (next_digit >= 5) {
                answer += (10 - digit);
                storey = storey / 10 + 1;
            }
            else {
                answer += digit;
                storey /= 10;
            }
        }
	}

    return answer;
}

// 1차 시도 : 성공
