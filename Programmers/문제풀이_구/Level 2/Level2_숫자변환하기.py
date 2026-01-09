x, y, n = 10, 40, 5

# x + n, x * 2, x * 3
# y는 (x+n), x의 배수

# 1트 DFS 시도했으나 시간 초과, 경우의 수를 줄여보려 했으나 런타임 문제 발생
def dfs(num, n, y, count):
    if num > y:
        return 987654321
    if num == y:
        return count
    
    count = min(dfs(num + n, n, y, count + 1), dfs(num * 2, n, y, count + 1), dfs(num * 3, n, y, count + 1))
    return count

def solution(x, y, n):
    answer = dfs(x, n, y, 0)
    if answer == 987654321:
        return -1
    return answer

#print(solution(x, y, n))

# 2트(성공) DP 사용 3가지 연산에 대해서 진행하면서 +1만 해줌
def dp_search(x, y, n):
    dp = [ 987654321 for i in range(y + 1)]
    
    dp[x] = 0
    for i in range(x, y + 1):
        if i + n <= y:
            dp[i + n] = min(dp[i + n], dp[i] + 1)
        if i * 2 <= y:
            dp[i * 2] = min(dp[i * 2], dp[i] + 1)
        if i * 3 <= y:
            dp[i * 3] = min(dp[i * 3], dp[i] + 1)

    if dp[y] == 987654321:
        return -1

    return dp[y]

print(dp_search(x, y, n))


# 다른사람 풀이 set() 사용, 좀 더 파이썬스럽게? 풀은 방식 bfs?
# set() : 집합 자료형, 중복을 허용하지 않음
def solution_set(x, y, n):
    answer = 0
    s = set()
    s.add(x)
    while s:
        if y in s:
            return answer
        nxt = set()
        for i in s:
            if i+n <= y:
                nxt.add(i+n)
            if i*2 <= y:
                nxt.add(i*2)
            if i*3 <= y:
                nxt.add(i*3)
        s = nxt
        answer+=1

    return -1