#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
	}
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int maxGcdArrayA = 0;
    int maxGcdArrayB = 0;

    for (auto num : arrayA) {
        maxGcdArrayA = gcd(maxGcdArrayA, num);
        if (maxGcdArrayA == 1) {
            maxGcdArrayA = 0;
            break;
        }
    }

    for (auto num : arrayB) {
        maxGcdArrayB = gcd(maxGcdArrayB, num);
        if (maxGcdArrayB == 1) {
            maxGcdArrayB = 0;
            break;
        }
    }

    if (maxGcdArrayA == 0 && maxGcdArrayB == 0)
		return 0;

    if (maxGcdArrayA != 0) {
        for (auto num : arrayB) {
            if (num % maxGcdArrayA == 0) {
                maxGcdArrayA = 0;
                break;
            }
        }
    }

    if (maxGcdArrayB != 0) {
        for (auto num : arrayA) {
            if (num % maxGcdArrayB == 0) {
                maxGcdArrayB = 0;
                break;
            }
        }
    }

    return max(maxGcdArrayA, maxGcdArrayB);
}

// 1차 시도 : 실패, 테스트 케이스 20, 26, 27번 실패

// 2차 시도 : 성공, 1 처리 방식 수정, 최적화 위해서 둘 다 0인 경우 0 반환
