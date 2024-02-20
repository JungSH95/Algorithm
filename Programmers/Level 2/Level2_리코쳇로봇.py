board = ["...D..R", ".D.G...", "....D.D", "D....D.", "..D...."]

from collections import deque

def bfs(board, r_x, r_y):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    row = len(board)
    col = len(board[0])

    visit = [[987654321 for j in range(col)] for i in range(row)]    
    
    q = deque()
    q.append((r_x, r_y))
    visit[r_x][r_y] = 0

    while q:
        x,y = q.popleft()
        base_x, base_y = x, y   # 이동전 위치

        #1차 시도 로직
        # dist = visit[x][y]
        # for i in range(4):
        #     if next_x >= 0 and next_x < row and next_y >= 0 and next_y < col and board[next_x][next_y] != 'D':
        #         if visit[next_x][next_y] > dist + 1:
        #             visit[next_x][next_y] = dist + 1
        #             q.append((next_x, next_y))

        for i in range(4):
            move_count = 0
            x, y = base_x, base_y

            # 미끄러져 끝까지 이동
            while True:
                next_x = x + dx[i]
                next_y = y + dy[i]
                
                # 끝에 박아서 멈춤
                if next_x < 0 or next_x == row or next_y < 0 or next_y == col or board[next_x][next_y] == 'D':
                    # 도착
                    if board[x][y] == 'G':
                        return visit[base_x][base_y] + 1
                    
                    # 멈춘곳, 이동한 거리 처리
                    if move_count > 0 and visit[base_x][base_y] + 1 < visit[x][y]:
                        q.append((x, y))
                        visit[x][y] = visit[base_x][base_y] + 1
                    break

                x, y = next_x, next_y
                move_count += 1

    return -1


def solution(board):
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 'R':
                return bfs(board, i, j)                
    return -1


print(solution(board))

'''
원래는 queue를 사용하여 작성하려 queue 사용법 확인중에 deque를 알게되었고,
deque가 훨씬 속도가 빠르다고 함
이유 : deque는 명령을 O(1)으로 지원하는데 Queue 모듈은 멀티쓰레드 환경을 지원하기 때문에
더 느리다고 함
-> 코테에서는 deque를 사용
'''

'''
1차 시도 실패
문제를 자세히 읽어보지 않아서 문제의 조건 중 
"게임판 위의 장애물이나 맨 끝에 부딪힐 때까지 미끄러져 이동"이라는 중요한 조건을 놓침
'''

'''
2차 시도 성공
한 방향으로 계속 이동 & 벽에 박을 때까지(while TRUE 추가)
각 상하좌우 이동하고 멈춘 부분의 x,y 지점을 q에 추가해서 bfs 순회하도록 수정
'''