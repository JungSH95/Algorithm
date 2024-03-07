topping = [1, 2, 1, 3, 1, 4, 1, 2]

def toppingTypeCount(sliceCake):
    toppingCount = 0
    for i in range(1, len(sliceCake)):
        if sliceCake[i] != 0:
            toppingCount += 1
    return toppingCount

def solution(topping):
    answer = 0

    left_cake = [0] * (max(topping) + 1)
    right_cake = [0] * (max(topping) + 1)
    for to in topping:
        right_cake[to] += 1

    left_cake[topping[0]] += 1
    right_cake[topping[0]] -= 1

    left_count = toppingTypeCount(left_cake)
    right_count = toppingTypeCount(right_cake)
    if left_count == right_count:
        answer += 1
    
    for i in range(1, len(topping)):
        left_cake[topping[i]] += 1
        right_cake[topping[i]] -= 1

        if left_cake[topping[i]] == 1:
            left_count += 1
        if right_cake[topping[i]] == 0:
            right_count -= 1

        if left_count == right_count:
            answer += 1

    return answer

print(solution(topping))



# 다른 사람 풀이 중 마음에 들었던 풀이 방식 
# collections 모듈의 Counter 클래스 사용
# 코드는 매우 만족스러울 정도로 깔끔하지만 실행해 속도를 확인해본 결과
# 가장오래걸리는 테스트케이스 기준으로 내 코드가 100ms 빨랐다
from collections import Counter

def solution_counter(topping):
    dic = Counter(topping)
    set_dic = set()
    res = 0
    for i in topping:
        dic[i] -= 1
        set_dic.add(i)
        if dic[i] == 0:
            dic.pop(i)
        if len(dic) == len(set_dic):
            res += 1
    return res