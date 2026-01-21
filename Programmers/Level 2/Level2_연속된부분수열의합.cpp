#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int start = 0;
    int end = 0;
    int min_start = -1;
    int min_end = -1;
    int min_len = INT_MAX;
    int total = sequence[0];

    while (start < sequence.size() && end < sequence.size())
    {
        // 기존보다 길이가 짧다면
        if (total == k && (end - start + 1 < min_len))
        {
            min_start = start;
            min_end = end;
            min_len = end - start + 1;
        }

        if (total < k)
        {
            end += 1;
            if (end >= sequence.size())
                break;
            total += sequence[end];
        }
        else
        {
            start += 1;
            if (start >= sequence.size())
                break;
            total -= sequence[start - 1];
        }
    }

    answer.push_back(min_start);
    answer.push_back(min_end);
    return answer;
}


// 1차 시도 : 성공
// 이전에 파이썬으로 풀었던 코드가 있어서 비교해보니 예나 지금이나 생각하는 방식은 동일했다.