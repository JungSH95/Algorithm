// 백준 소수의 연속합 (https://www.acmicpc.net/problem/1644)

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> prime;

// N의 범위가 최대 400만으로 크기 때문에 소수를 구하는 알고리즘을 찾아서 사용함
// 에라토스테네스의 체를 이용하여 소수 구하기
void makePrime() {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) 
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i])
			prime.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	if (N < 2) {
        cout << 0 << endl;
        return 0;
    }

    makePrime();

	int start = 0, end = 0, sum = 0, count = 0;
    while (true) {
        if (end >= prime.size())
            break;

        if (sum < N)
            sum += prime[end++];

        if (sum > N)
            sum -= prime[start++];

		if (sum == N) {
            count++;
            sum -= prime[start++];
        }
    }

	cout << count << endl;
    return 0;
}

// 1차 시도 : 성공
