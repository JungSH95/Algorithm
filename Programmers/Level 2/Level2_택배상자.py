# 스택인데?
'''
보조 컨테이너 벨트는 앞 뒤로 이동이 가능하지만 입구 외에 다른 면이 막혀 있어서 
맨 앞의 상자만 뺄 수 있습니다 (즉, 가장 마지막에 보조 컨테이너 벨트에 보관한 상자부터 꺼내게 됩니다).
'''

order = [4, 3, 1, 2, 5]
order = [5, 4, 3, 2, 1]

# 1트(성공), 문제에서 풀이 방법을 쉽게 알려줌
def solution(order):
    answer = 0
    stack = []
    for i in range(len(order)):
        if order[answer] == (i + 1):
            answer += 1
        else:
            stack.append(i + 1)
            continue

        while stack:
            if order[answer] == stack[-1]:
                stack.pop()
                answer += 1
            else:
                break

    return answer

print("RESULT : " + str(solution(order)))