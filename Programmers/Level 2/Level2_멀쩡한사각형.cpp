#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

long long getGCD(int a, int b) {
    if (b == 0)
        return a;
    
    return getGCD(b, a % b);
}

long long solution(int w, int h) {
    long long answer = w * h - (w + h - getGCD(w, h));    
    return answer;
}

// 제한조건인 w, h의 최대값이 1억이므로 기울기를 사용해 좌표를 전부 확인하는건 무조건 시간 초과 발생
// 대각선 방향으로 잘려나가는 사각형들의 패턴이 일정함
// w : 8, h : 12
// 반복되는 패턴의 개수는 4개, w와 h의 최대공약수
// 대각선을 가로 지르는 경우 0,0 에서 w,h 까지의 최단 거리
// => 최대공약수 * ((w' - 1) + (h' - 1) + 1)

// 1차 시도 : 성공, 프로그래밍 실력보단 수학적 생각이 많이 필요했던 문제
