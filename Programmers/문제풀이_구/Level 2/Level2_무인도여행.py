#maps = ["X591X","X1X5X","X231X", "1XXX1", "1XXX1"]
#maps = ["XXX","XXX","XXX"]
maps = ["X5XX5X", "111111", "XXXXXX", "111111"]

from collections import deque

def bfs(i, j, maps, visit):
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]

    q = deque()
    q.append((i, j))
    day = int(maps[i][j])
    visit[i][j] = True

    while q:
        x, y = q.pop()

        for _ in range(4):
            next_x = x + dx[_]
            next_y = y + dy[_]

            if next_x >= 0 and next_y >= 0 and next_x < len(maps) and next_y < len(maps[0]):

                if maps[next_x][next_y] != 'X' and visit[next_x][next_y] == False:
                    q.append((next_x, next_y))
                    day += int(maps[next_x][next_y])
                    visit[next_x][next_y] = True

    return day

def solution(maps):
    answer = []
    visit = [[False] * len(maps[0]) for i in range(len(maps))]

    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] != 'X' and visit[i][j] == False:
                answer.append(bfs(i, j, maps, visit))

    answer.sort()
    if len(answer) == 0:
        answer.append(-1)
    return answer

print(solution(maps))


'''
이상한 곳에서 시간을 너무 버림
안됐던 테스트 케이스 : maps = ["X5XX5X", "111111", "XXXXXX", "111111"]

1차 시도 시 숫자를 X로 변경하는 방법을 사용
maps[next_x] = maps[next_x].replace(maps[next_x][next_y], "X", 1)
* 문제가 replace 함수는 제일 먼저 찾은 문자(maps[next_x][next_y])를 기준으로 치환을 옵션(1)의 숫자만큼 변경함
ex) "111111"에서 두 번째 1이 먼저 들어온 경우 "1X1111"가 아니라 "X11111"로 잘못치환됨

-> 때문에 방문여부를 확인하는 방식으로 수정
'''