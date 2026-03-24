// 백준 제로 (https://www.acmicpc.net/problem/10773)

#include <iostream>
#include <stack>
using namespace std;

int K;

int main() {
    cin >> K;
    
    stack<int> s;
    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0 && !s.empty())
            s.pop();
        else
            s.push(tmp);
    }

    int total = 0;
    while (!s.empty()) {
        total += s.top();
        s.pop();
    }
    cout << total;

    return 0;
}

// 1차 시도 : 성공