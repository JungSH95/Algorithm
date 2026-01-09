병사 = 7
무적권 = 3
몬스터들 = [4,2,4,5,3,3,1]
마지막라운드 = 0

def solution(n, k, enemy):
    if k > len(enemy):
        return len(enemy)
    dfs(0, n, k, enemy)
    global 마지막라운드
    return 마지막라운드

def dfs(라운드, 병사, 무적권, 몬스터들):
    if 병사 < 0:
        global 마지막라운드
        마지막라운드 = max(마지막라운드, 라운드 - 1)
        return
    
    if 라운드 >= len(몬스터들):
        마지막라운드 = len(몬스터들)
        return

    if 무적권 != 0:
        dfs(라운드 + 1, 병사, 무적권 - 1, 몬스터들)
    dfs(라운드 + 1, 병사 - 몬스터들[라운드], 무적권, 몬스터들)
    return

solution(병사, 무적권, 몬스터들)
print("마지막 라운드 : " + str(마지막라운드))

# 방법이 도저히 생각안나서 병사의 수(n), 무적권(k), enemy의 크기가 크기 때문에
# DFS로 풀어도 시간 초과가 될 것이 예상 됐지만 일단 DFS로 풀어봄.

# 확인한 문제점
# 1. 당연하게도 시간 초과가 발생함
# 2. 런타임 에러가 발생했음. 조사해보니 파이썬에서는 recursion limit가 존재하며
#   기본적으로 파이썬 기본 limit는 작게(1000) 설정되어있음. 런타임 에러가 발생한 것
import sys
print("재귀의 한계 횟수 : " + str(sys.getrecursionlimit()))


# 다른 사람 풀이 방법 : 우선순위 큐 사용
# 우선순위 큐를 사용하면 가지고 있는 값들 중 가장 큰 k개의 값들에 대하여
# 무적권을 사용하려는 대상을 알 수 있다.
import heapq

def solution_pq(n, k, enemy):
    if k >= len(enemy):
        return len(enemy)
    
    priority_queue = []
    for i in range(len(enemy)):
        heapq.heappush(priority_queue, enemy[i])
        print(priority_queue)
        if len(priority_queue) > k:
            last = heapq.heappop(priority_queue)
            print(str(priority_queue) + " / " + str(last))
            if last > n:
                return i
            n -= last            

    return len(enemy)


print("solution_pq: " + str(solution_pq(병사, 무적권, 몬스터들)))
