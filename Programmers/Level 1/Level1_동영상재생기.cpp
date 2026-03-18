#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>
using namespace std;

/* 동영상 재생기의 3가지 기능
* prev : 10초 전으로 이동
* next : 10초 후로 이동
* 오프닝 건너뛰기 : 현재 재생 위치가 오프닝 구간인 경우 자동으로 오프닝이 끝나는 위치로 이동
* 
* 함수 인자
* video_len : 비디오 길이
* pos       : 기능 수행전 현재 재생위치
* op_start  : 오프닝 시작 시간
* op_end    : 오프닝 끝나는 시간
* commands  : 사용자 입력
*/
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int video_second = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));
    int now_second = stoi(pos.substr(0, 2)) * 60 + stoi(pos.substr(3, 2));
    int op_start_second = stoi(op_start.substr(0, 2)) * 60 + stoi(op_start.substr(3, 2));
    int op_end_second = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3, 2));

    // 오프닝 구간 체크
    if (op_start_second <= now_second && now_second <= op_end_second)
        now_second = op_end_second;

    for (auto command : commands) {
        if (command == "next") {
            now_second += 10;

            if (video_second < now_second)
                now_second = video_second;
        }
        else {
            now_second -= 10;

            if (now_second < 0)
                now_second = 0;
        }

        // 오프닝 구간 체크
        if (op_start_second <= now_second && now_second <= op_end_second)
            now_second = op_end_second;
    }

    char buffer[6];
    sprintf_s(buffer, "%02d:%02d", now_second / 60, now_second % 60);
    answer = buffer;
    return answer;
}

// 1차 시도 : 성공, 오랜만에 c에서 사용하던 문자열 처리 함수를 검색하여 적용함