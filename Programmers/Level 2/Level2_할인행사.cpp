#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

/*
    vector<string> want         원하는 제품 목록
    vector<int> number          원하는 제품의 수량
    vector<string> discount     할인하는 제품 목록
*/
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

	map<string, int> wantMap;
    for (int i = 0; i < want.size(); i++) 
        wantMap[want[i]] = number[i];
	
	for (int i = 0; i < discount.size(); i++) 
    {
        if(wantMap.find(discount[i]) != wantMap.end())
			wantMap[discount[i]]--;

        if (i >= 9) 
        {
            bool isMatch = true;
            for (const auto& item : wantMap) 
            {
                if (item.second > 0) 
                {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) 
                answer++;

            // 10일이 지난 후에는 할인하는 제품이 다시 구매 가능
            if(wantMap.find(discount[i - 9]) != wantMap.end())
                wantMap[discount[i - 9]]++;
		}
	}

    return answer;
}

// 1차 시도 : 성공
