#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> recordList;
    for (int i = 0; i < records.size(); i++)
    {
        string record = records[i];
        string time = record.substr(0, 5);
        string carNumber = record.substr(6, 4);
        string status = record.substr(11, 2);
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        int totalMinutes = hours * 60 + minutes;

		recordList[carNumber] += (status == "IN") ? - totalMinutes : totalMinutes;
    }

    for (auto& record : recordList)
    {
        string carNumber = record.first;
        int totalMinutes = record.second;

		// 입차하고 출차하지 않은 경우, 23:59에 출차한 것으로 간주
		if (totalMinutes <= 0)
            totalMinutes += 23 * 60 + 59;

        if (totalMinutes <= fees[0])
            answer.push_back(fees[1]);

        // 기본요금 + (총 주차 시간 - 기본 시간) / 단위 시간 * 단위 요금
        else
            answer.push_back(fees[1] + ceil((double)(totalMinutes - fees[0]) / fees[2]) * fees[3]);
	}

    return answer;
}

// 1차 시도 : 성공, 올림 함수 기억이 안나서 검색해서 사용했음.
