#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int solution(vector<vector<int>> signals) {
    int answer = -1;    

    // {2, 1, 2}
    //  2x + 2(x - 1) + 1x              => 5x - 2
    // x:1  => 0 + 2 + 1 => 3
    // x:2  => 2 + 4 + 2 => 8

    // {5, 1, 1}
    // 5x + 1(x - 1) + 1x               => 7x - 1
    // x:1  => 5 + 0 + 1    => 6
    // x:2  => 10 + 1 + 2   => 13
    
    // {2, 3, 2}
    // 7x - 2
    // x:1 => 5
    // x:2 => 12

    // {G, Y, R}
    // (G + Y + R)X - Y

    map<int, int> yellowLightCount;
    for (int i = 1; i <= 100000; i++) {

        for (auto signal : signals) {
            int yellowPos = (signal[0] + signal[1] + signal[2]) * i - signal[2];

            //cout << i << " / signal :" << yellowPos << endl;

            for (int j = signal[1]; j > 0; j--) {
                yellowLightCount[yellowPos] += 1;
                yellowPos -= 1;
            }
        }

    }

    for (auto count: yellowLightCount) {
        if (count.second >= signals.size()) {
            //cout << "TIME : " << count.first << endl;
            answer = count.first;
            break;
        }
    }

    return answer;
}

// 1차 시도 : 성공, 탐색 범위를 어떤식으로 찾아야할지 생각나지 않아 100000초까지 수행하도록 함(동작 수행 시간이 오래걸림)


// 다른 사람의 탐색 한계치를 구하는 방법
// 해당 방법을 적용했을때 분명히 빠른 부분도 존재하나 
// 테스트 케이스 18번 이후로는 나의 경우가 빨랐음
/*
// 최대공약수(GCD) 구하는 함수
long long getGcd(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 최소공배수(LCM) 구하는 함수
long long getLcm(long long a, long long b) {
    return (a / getGcd(a, b)) * b;
}

long long max_time = 1;
// 1. 모든 신호등 주기의 최소공배수(탐색 한계치) 구하기
for (int i = 0; i < signals.size(); i++) {
    long long cycle = signals[i][0] + signals[i][1] + signals[i][2];
    max_time = getLcm(max_time, cycle);
}
*/