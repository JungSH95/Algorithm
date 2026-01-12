#include <string>
#include <vector>
using namespace std;

bool isPossible(vector<int> tmp, vector<vector<int>> q, vector<int> ans) 
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 0)
            continue;

        int cnt = 0;
        for (int j = 0; j < q[i].size(); j++)
        {
            for (int k = 0; k < tmp.size(); k++)
            {
                if (tmp[k] > q[i][j])
                    break;
                else if (tmp[k] == q[i][j])
                {
                    cnt++;
                    break;
                }
            }
        }

        if (cnt != ans[i])
            return false;
    }
    return true;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    int numberCheck[31] = { 0, };
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 5)
            return 1;
        else if (ans[i] == 0) {
            for (int j = 0; j < q[i].size(); j++)
                numberCheck[q[i][j]] = -1;
        }
    }

    // 첫 번째 원소
    for (int a = 1; a <= n - 4; a++) 
    {
        if (numberCheck[a] == -1)
            continue;

        // 두 번째 원소
        for (int b = a + 1; b <= n - 3; b++) 
        {
            if (numberCheck[b] == -1)
                continue;

            // 세 번째 원소
            for (int c = b + 1; c <= n - 2; c++)
            {
                if (numberCheck[c] == -1)
                    continue;

                // 네 번째 원소
                for (int d = c + 1; d <= n - 1; d++)
                {
                    if (numberCheck[d] == -1)
                        continue;

                    // 다섯 번째 원소
                    for (int e = d + 1; e <= n; e++)
                    {
                        if (numberCheck[e] == -1)
                            continue;

                        vector<int> cand = { a, b, c, d, e };
                    
                        if (isPossible(cand, q, ans))
                        {
                            //cout << cand[0] << ", " << cand[1] << ", " << cand[2] << ", " << cand[3] << ", " << cand[4] << endl;
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}


// 1트 성공
// 첫 도전에 바로 성공했으나 코드 작성에 있어서 시간을 너무 사용함.

// 처음에는 가장 많이 일치하는 경우를 기준으로 배열들을 생성하여 하려 했으나 좋은 알고리즘이 생각나지 않음.
// 결국 모든 경우의 수를 생성하는 방법으로 변경
// 조금이나마 단축하기 위해 확실하게 제거할 수 있는 경우의 수인 ans가 0인 경우에 대하여 추가함.

// 총 테스트 케이스 20개 중에서 13번 케이스에서 가장 시간이 오래 걸렸으며 30.61ms 소요됨