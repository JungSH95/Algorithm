#include <string>
#include <vector>
using namespace std;

bool schedulesCheck(int schedule, vector<int> timelog, int startday) {
    for (int i = 0; i < 7; i++) {
        if (startday > 7) 
            startday = 1;
        else if (startday == 6 || startday == 7) {
            startday += 1;
            continue;
        }        
        
        if(schedule < timelog[i])
            return false;
        
        startday += 1;
    }
    
    return true;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (int i = 0; i < schedules.size(); i++) {
        int limit = schedules[i] + 10;
        if (limit % 100 >= 60)
            limit += 100 - 60;
        
        if(schedulesCheck(limit, timelogs[i], startday))
            answer++;
    }    
    
    return answer;
}

// 1트 : 실패 (정확성35점)

// 2트 : 성공
// 제한사항을 다시 읽어보며 발견(출근 희망 시각과 실제로 출근한 시각을 100으로 나눈 나머지는 59 이하)한 예외처리 추가