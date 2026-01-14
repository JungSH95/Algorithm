#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k) 
{
    int answer = 0;

    queue<int> serverTimeCount;
	for (int i = 0; i < players.size(); i++)
	{
    	int currentPlayers = players[i];
    	// 현재 서버에서 처리 가능한 플레이어 수
  		int availableCapacity = serverTimeCount.size() * m + (m - 1);
    
	    // 현재 플레이어 수가 서버 용량을 초과하는 경우
	    if (currentPlayers >= availableCapacity) {
	        int requiredServers = (currentPlayers - availableCapacity + m - 1) / m; // 필요한 서버 수 계산

	        answer += requiredServers; // 증설한 서버 수 누적
	        for (int j = 0; j < requiredServers; j++) {
	            serverTimeCount.push(k); // 새로 증설한 서버의 시간 추가
        }
    }

    cout << "시간: " << i << ", 현재 플레이어 수: " << currentPlayers << ", 서버 수: " << serverTimeCount.size() << ", 처리 가능 플레이어 수: " << availableCapacity << endl;


    // 모든 서버의 남은 시간을 1씩 감소시키고, 시간이 다 된 서버는 제거
    int size = serverTimeCount.size();
    for (int j = 0; j < size; j++) {
        int timeLeft = serverTimeCount.front() - 1;
        serverTimeCount.pop();
        if (timeLeft > 0) {
            serverTimeCount.push(timeLeft);
        }
	}
}
    return answer;
}


// 1차 시도 : 성공, Level2 치고는 쉬웠음