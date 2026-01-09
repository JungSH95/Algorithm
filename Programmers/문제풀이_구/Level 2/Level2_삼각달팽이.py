n = 5
# 처음 5번 아래
# 두번째 4번 오른쪽
# 세번째 3번 위
# 네번째 2번 아래
# 다섯번째 1번 오른쪽

def solution(n):
    answer = [[0 for j in range(1, i+1)] for i in range(1, n+1)]    

    number = 1
    x, y = -1, 0

    for i in range(n):
        if i % 3 == 0:
            print("아래 : ", end="")
            for j in range(n - i):
                print("{}".format(number), end=' ')
                x += 1
                answer[x][y] = number
                number += 1
                
        if i % 3 == 1:
            print("오른쪽 : ", end="")
            for j in range(n - i):
                print("{}".format(number), end=' ')
                y += 1
                answer[x][y] = number
                number += 1

        if i % 3 == 2:
            print("위 : ", end="")
            for j in range(n - i):
                print("{}".format(number), end=' ')
                x -= 1
                y -= 1
                answer[x][y] = number
                number += 1

        print()
        print(answer)
        
    print(sum(answer, []))
    return answer

solution(n)

# 이전에 C++로 풀었던 적이 있는 문제
# 각 방향별로 n -> n-1 -> n-2 번 진행되는 것을 뼈대로 삼아 작성함.
# n(n+1)/2 번 수행
