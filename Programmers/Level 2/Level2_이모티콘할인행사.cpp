#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

vector<int> discount_ratio = { 10, 20, 30, 40 };

int max_user_count = 0;
int max_price = 0;

void dfs(vector<vector<int>> users, vector<int> emoticons, vector<int> discount)
{
    if (discount.size() == emoticons.size())
    {
        int total_price = 0;
        int user_count = 0;

        for (int i = 0; i < users.size(); i++)
        {
            int price = 0;
            for (int j = 0; j < emoticons.size(); j++)
            {
                // 일정 비율 이상 할인하는 이모티콘 모두 구매
                if (users[i][0] <= discount[j])
                    price += emoticons[j] * (100 - discount[j]) / 100;
            }

            // 구매비용의 합이 일정 가격 이상이면 구매 취소 및 서비스 가입
            if (price >= users[i][1])
                user_count += 1;
            else
                total_price += price;
        }

        // 1순위. 서비스 가입자 최대한 늘리기
        // 2순위. 판매액 최대한 늘리기
        if (user_count > max_user_count)
        {
            max_user_count = user_count;
            max_price = total_price;
        }
        else if (user_count == max_user_count)
            max_price = max(max_price, total_price);

        return;
    }

    for (int i = 0; i < discount_ratio.size(); i++)
    {
        discount.push_back(discount_ratio[i]);
        dfs(users, emoticons, discount);
        discount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> discount;
    dfs(users, emoticons, discount);
    return { max_user_count, max_price };
}

// 1차 시도 : 성공
