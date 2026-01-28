#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int getMinute(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int solution(vector<vector<string>> book_time)
{
    vector<vector<int>> int_time;
    for (int i = 0; i < book_time.size(); i++)
    {
        vector<int> time;
        // 체크인
        time.push_back(getMinute(book_time[i][0]));
        // 체크아웃 + 방 청소 시간
        time.push_back(getMinute(book_time[i][1]) + 10);
        int_time.push_back(time);
    }

    int max_room_count = 0;
    int room_count = 0;
    sort(int_time.begin(), int_time.end());

    priority_queue<int, vector<int>, greater<int>> end_time;
    for (int i = 0; i < int_time.size(); i++)
    {
        // 방 반납가능한 것 있는지 체크
        while (!end_time.empty())
        {
            if (int_time[i][0] >= end_time.top())
            {
                end_time.pop();
                room_count += 1;
            }
            else
                break;
        }

        // 입실 처리(방 카운트 +1, 방 종료 시간 추가)
        // 남은 방이 없는 경우
        if (room_count == 0)
            max_room_count += 1;
        else
            room_count -= 1;

        end_time.push(int_time[i][1]);
    }

    return max_room_count;
}


// 1차 시도 : 성공