#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<string> board)
{
    int x_count = 0, o_count = 0;
    bool x_win = false, o_win = false;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].length(); j++)
        {
            if (board[i][j] == 'O')
                o_count += 1;
            if (board[i][j] == 'X')
                x_count += 1;
        }
    }

    // 아무것도 안둔 경우
    if (o_count == 0 && x_count == 0)
        return 1;

    // 가로 체크
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == "OOO")
            o_win = true;
        if (board[i] == "XXX")
            x_win = true;
    }

    // 세로 체크
    for (int i = 0; i < board.size(); i++)
    {
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
            o_win = true;
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            x_win = true;
    }

    // 대각 체크(우측아래, 좌측아래)
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        o_win = true;
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        x_win = true;
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
        o_win = true;
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
        x_win = true;


    // 불가능한 조건들 확인
    // 둘 다 이긴 경우
    if (o_win == true && x_win == true)
        return 0;

    // 승패가 났는데 진행한 경우
    if ((o_win == true && o_count <= x_count) || (x_win == true && o_count != x_count))
        return 0;

    // 선공보다 후공이 더 많이 둔 경우
    if (!(o_count == x_count || o_count == x_count + 1))
        return 0;

    return 1;
}


// 1차 시도 : 성공, 문제 조건 자체가 까다롭지 않아서 불가능한 조건을 확인하도록함