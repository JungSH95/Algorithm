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
* plaves : 대기실 구조를 담은 배열
*   P : 응시자의 자리
*   O : 빈 테이블
*   X : 파티션
* 
*   맨해튼거리 : T1(r1,c1), T2(r2,c2) => |r1 - r2| + |c1 -c2|
*/
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    // 왼쪽    : (-2,0), (-1,0)
    // 오른쪽  : (+2,0), (+1,0)
    // 아래    : (0,+2), (0,+1)
    // 대각선  : (-1,+1), (+1,+1)
    int checkPointY[] = { -2, -1, 2, 1, 0, 0, -1, 1 };
    int checkPointX[] = { 0, 0, 0, 0, 2, 1, 1, 1 };

    for (auto place : places) {
        int success = true;

        for (int i = 0; i < place.size(); i++) {
            for (int j = 0; j < place[i].size(); j++) {
                if (place[i][j] == 'P') {
                    for (int k = 0; k < 8; k++) {
                        int otherCheckX = i + checkPointX[k];
                        int otherCheckY = j + checkPointY[k];

                        if (otherCheckX >= 0 && otherCheckX < 5 && otherCheckY >= 0 && otherCheckY < 5) {
                            if (place[otherCheckX][otherCheckY] == 'P') {
                                cout << place[otherCheckX][otherCheckY] << "(" << otherCheckX << ", " << otherCheckY << ") ";

                                // 바로 인접한 경우
                                if (k == 1 || k == 3 || k == 5) {
                                    success = false;
                                    break;
                                }

                                // 왼쪽
                                if (k == 0 && place[i][j - 1] != 'X') {
                                    success = false;
                                    break;
                                }

                                // 오른쪽
                                else if (k == 2 && place[i][j + 1] != 'X') {
                                    success = false;
                                    break;
                                }

                                // 아래
                                else if (k == 4 && place[i + 1][j] != 'X') {
                                    success = false;
                                    break;
                                }

                                // 왼쪽 대각선
                                else if (k == 6 && (place[i + 1][j] != 'X' || place[i][j - 1] != 'X')) {
                                    success = false;
                                    break;
                                }

                                // 오른쪽 대각선
                                else if (k == 7 && (place[i + 1][j] != 'X' || place[i][j + 1] != 'X')) {
                                    success = false;
                                    break;
                                }
                            }
                        }
                    }

                    // 중복확인할 필요 X
                    if (success)
                        place[i][j] = 'O';
                }

            }

            if (success == false) {
                answer.push_back(0);
                break;
            }
        }

        if (success)
            answer.push_back(1);
    }

    return answer;
}

// 1차 시도 : 성공, 코드가 더러워 보이지만  dfs bfs보다 속도가 빠르게 나와 만족
// 굳이 전체를 확인 안하더라도 하나의 아래 오른쪽으로 진행하며 확인해야할 경우의 수는 8가지 밖에 안됨