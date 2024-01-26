#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());

    vector<int> report_count;               // 신고 받은 수
    vector<vector<string>> reports;         // <신고한 사람들>
    report_count.resize(id_list.size());
    reports.resize(id_list.size());

    // 중복 제거
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for (int i = 0; i < report.size(); i++) {
        string user = report[i].substr(0, report[i].find(" "));
        string report_user = report[i].substr(report[i].find(" ") + 1, report[i].length() - report[i].find(" ") - 1);

        for (int j = 0; j < id_list.size(); j++) {
            if (id_list[j].compare(report_user) == 0) {
                report_count[j] += 1;
                reports[j].push_back(user);
                break;
            }
        }
    }

    // 각 총 신고당한 수
    for (int j = 0; j < report_count.size(); j++) {
        for (int i = 0; i < reports[j].size(); i++) {
            if (k <= report_count[j]) {
                for (int m = 0; m < id_list.size(); m++) {
                    if (id_list[m].compare(reports[j][i]) == 0) {
                        answer[m] += 1;
                        break;
                    }
                }
            }
        }
    }
    
    return answer;
}

int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { 
        "muzi frodo",
        "apeach frodo",
        "frodo neo",
        "muzi neo",
        "apeach muzi"
    };
    int k = 2;

    solution(id_list, report, k);
}
