// 백준 정수 삼각형 (https://www.acmicpc.net/problem/1932)

#include <iostream>
using namespace std;

int N;
int arr[500][500];
int dp[501][501];

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = N; j >= N - i; j--) {
            cin >> arr[i][N - j];
        }
    }

    dp[0][0] = arr[0][0];
    for (int i = 1; i < N; i++) {
        for (int j = N; j >= N - i; j--) {
            if (N - j == 0)
                dp[i][N - j] = dp[i - 1][N - j] + arr[i][N - j];
            else
                dp[i][N - j] = max(dp[i - 1][N - j], dp[i - 1][N - j - 1]) + arr[i][N - j];
        }
    }

    int maxNum = 0;
    for (int i = 0; i < N; i++)
        maxNum = max(dp[N - 1][i], maxNum);
    cout << maxNum;

    return 0;
}

// 1차 시도 : 성공