maps = ["SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"]
maps = ["LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"]

from collections import deque

def findPath(maps, start_x, start_y, end_x, end_y):    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    row = len(maps)
    col = len(maps[0])

    distance = 0

    visit = [[987654321 for j in range(col)] for i in range(row)] 
    visit[start_x][start_y] = 0

    q = deque()
    q.append((start_x, start_y))
    
    while q:
        x, y = q.popleft()

        dist = visit[x][y]
        
        for i in range(4):                       
            next_x = x + dx[i]
            next_y = y + dy[i]

            if next_x >= 0 and next_x < row and next_y >= 0 and next_y < col and maps[next_x][next_y] != 'X':
                if next_x == end_x and next_y == end_y:
                    return dist + 1

                if visit[next_x][next_y] > dist + 1:
                    visit[next_x][next_y] = dist + 1
                    q.append((next_x, next_y))
    
    return distance


def solution(maps):
    START_X, START_Y = 0, 0
    LEVER_X, LEVER_Y = 0, 0
    EXIT_X, EXIT_Y = 0, 0

    for i in range(len(maps)):
        for j in range(len(maps[i])):
            if maps[i][j] == 'S':
                START_X, START_Y = i, j
            elif maps[i][j] == 'L':
                LEVER_X, LEVER_Y = i, j
            elif maps[i][j] == 'E':
                EXIT_X, EXIT_Y = i, j
                
    path1 = findPath(maps, START_X, START_Y ,LEVER_X, LEVER_Y)
    path2 = findPath(maps, LEVER_X, LEVER_Y, EXIT_X, EXIT_Y)
    if path1 == 0 or path2 == 0:
        return -1
    
    return path1 + path2

print(solution(maps))


# result : S -> L 가는길 + L -> E 가는길

