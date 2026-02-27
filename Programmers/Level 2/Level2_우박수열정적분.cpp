#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<pair<int, int>> collatz;
    vector<double> extent;

    int n = 0;
    collatz.push_back(make_pair(n, k));
    while (k > 1) {
        if (k % 2 == 0)
            k /= 2;
        else
            k = 3 * k + 1;

        n += 1;
        collatz.push_back(make_pair(n, k));

        double tmp = double(min(k, collatz[n - 1].second)) + double(abs(k - collatz[n - 1].second) / 2.0);
        extent.push_back(tmp);
    }

    for (int i = 0; i < ranges.size(); i++) {

        int range = n + ranges[i][1];
        if (ranges[i][0] > range) {
            answer.push_back(-1);
            continue;
        }

        double totalExtent = 0;
        for (int j = ranges[i][0]; j < range; j++)
            totalExtent += extent[j];

        answer.push_back(totalExtent);
    }

    return answer;
}

// 1차 시도 : 성공, 문제에서 제시한 순서를 따라하기만 되는 쉬운 문제