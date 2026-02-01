#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] < numbers[j])
            {
                answer[i] = numbers[j];
                break;
            }
        }
    }
    return answer;
}

vector<int> solution1(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);

    int max_number = numbers[numbers.size() -1];
    int max_number_pos = numbers.size() - 1;

    for (int i = numbers.size() - 2; i >= 0; i--)
    {
        if (numbers[i] >= max_number)
        {
            max_number = numbers[i];
            max_number_pos = i;
        }
        else
        {
            for (int j = i + 1; j <= max_number_pos; j++)
            {
                if (numbers[i] < numbers[j])
                {
                    answer[i] = numbers[j];
                    break;
                }
            }
        }
    }

    return answer;
}

// 테스트 케이스 20, 22번의 시간초과를 해결할 방법이 도저히 생각나지 않아 다른 사람의 풀이
vector<int> solution2(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);

    int max_number = numbers[numbers.size() - 1];
    int max_number_pos = numbers.size() - 1;

    vector<int> nextPos(1000001, -1);

    for (int i = numbers.size() - 2; i >= 0; i--)
    {
        if (numbers[i] >= max_number)
        {
            max_number = numbers[i];
            max_number_pos = i;
            nextPos[i] = max_number_pos;

        }
        else
        {
            for (int j = i + 1; j <= max_number_pos; j++)
            {
                if (numbers[i] < numbers[j])
                {
                    answer[i] = numbers[j];
                    nextPos[i] = j;
                    break;
                }
                else
                {
                    j = nextPos[j] - 1;
                }
            }
        }
    }

    return answer;
}

// 스택을 사용한 다른 사람의 풀이, 제일 마음에 들은 방식
// 속도도 위의 방법보다 빠르며, 메모리 사용량도 더 적게 사용
vector<int> solution3(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> s;

    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        // 쌓여있는 숫자들중 낮은 숫자들 제거
        while (!s.empty() && s.top() <= numbers[i])
            s.pop();

        // 남아 있는 큰 수 처리
        if (!s.empty())
            answer[i] = s.top();

        // 현재 숫자 스택에 추가
        s.push(numbers[i]);
    }

    return answer;
}

// 1차 시도 : 실패, 시간초과 및 많은 테스트 케이스에 대한 실패

// 2차 시도 : 실패, 대체적으로 성공했으나 역시나 시간 초과 3개의 테스트 케이스에서 발생, 
// numbers의 길이가 1,000,000이기 때문

// 3차 시도 : 실패, 뒤에서 채워가는 방식으로 변경 후 시간 초과 2개의 테스트 케이스에서 발생
