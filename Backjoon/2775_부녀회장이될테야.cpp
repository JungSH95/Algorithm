// 백준 부녀회장이 될테야 (https://www.acmicpc.net/problem/2775)

#include <iostream>
using namespace std;

int T;
int arr[15][15];

// a층 b호 = (a-1)층 1 ~ b호 사람의 합
void peopleCount(int k, int n) {

    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int m = 1; m <= j; m++) {
                arr[i][j] += arr[i - 1][m];
            }
        }
    }

    return;
}

int main() {
    cin >> T;

    // 아파트는 0층부터 있고 각층에는 1호부터 있다.
    // 0층의 i호에는 i명이 산다
    for (int i = 1; i < 15; i++)
        arr[0][i] = i;

    peopleCount(14, 14);

    for (int i = 0; i < T; i++) {
        // k : 층, n : 호
        int k, n;
        cin >> k >> n;
        cout << arr[k][n];
    }

    return 0;
}

// 1차 시도 : 성공