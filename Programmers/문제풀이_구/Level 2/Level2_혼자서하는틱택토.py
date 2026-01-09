#board = ["O.X", ".O.", "..X"]
#board = ["OOO", "...", "XXX"]
#board = ["O..", "O..", "OXX"]
#board = ["O..", ".O.", "XXO"]
board = [
    "OOX",
    "XXO", 
    "OXO"
]

def solution(board):
    first = 0
    second = 0
    first_win = False
    second_win = False

    # 가로 체크
    for row in board:
        first += row.count("O")
        if row.count("O") == 3:
            first_win = True

        second += row.count("X")
        if row.count("X") == 3:
            second_win = True

    # 보드판이 깨끗한 상태
    if first == 0 and second == 0:
        return 1
    
    # 세로 체크    
    for i in range(3):
        first_Check = 0
        second_Check = 0

        for j in range(3):
            if board[j][i] == "O":
                first_Check += 1
            elif board[j][i] == "X":
                second_Check += 1
        
        if first_Check == 3:
            first_win = True
        elif second_Check == 3:
            second_win = True


    # 대각선 체크 (X자 모양)    
    if str(board[0][0] + board[1][1] + board[2][2]).count("O") == 3:
        first_win = True
    elif str(board[0][0] + board[1][1] + board[2][2]).count("X") == 3:
        second_win = True

    if str(board[0][2] + board[1][1] + board[2][0]).count("O") == 3:
        first_win = True
    elif str(board[0][2] + board[1][1] + board[2][0]).count("X") == 3:
        second_win = True        


    # 어느 한 쪽이 한 번 더 함, 선공 차례인데 후공이 더 둠
    if not (first == second or first == second + 1):
        return 0
    
    # 둘 다 만족한 경우 X
    if first_win and second_win:
        return 0
    
    # 누구 한 명이 승리 조건을 만족 시켰는데도 진행된 경우
    if (first_win == True and second != first - 1) or (second_win == True and first != second):
        return 0
    
    return 1


print(solution(board))


# 단순하게 경우의 수를 생각해서 작성하면 됐던 문제.
# Level2라고 하기에는 너무 쉽다


# 다른 고수의 가로/세로/대각선 확인 코드
def check_win(player, board):
    # 가로
    for i in range(3):
        if all(cell == player for cell in board[i]):
            return True
        
    # 세로
    for j in range(3):
        if all(board[i][j] == player for i in range(3)):
            return True
    
    # 대각선
    if all(board[i][j] == player for i in range(3)):
        return True
    if all(board[i][2-i] == player for i in range(3)):
        return True
    
    return False


# all 함수 : 인자로 넘어온 모든 요소가 참인경우 TRUE
