storey = 55

def solution(storey):
    answer = 0

    while storey != 0:
        storey, remainder = divmod(storey, 10)     
           
        if remainder < 5:
            answer += remainder

        elif remainder == 5:
            if storey % 10 >= 5:
                answer += 10 - remainder
                storey += 1
            else:
                answer += remainder

        else:
            answer += 10 - remainder
            storey += 1

        print("ANSWER : {}".format(answer))

    return answer

print(solution(storey))

# 최소로 가기 위한 조건
# 1의 자리 반올림/반내림화 1~4의 경우는 -1, 6~9인 경우 +1, 5인 경우 다음 자리 수를 고려해야함.
# 10의 자리 반올림/반내림 
# 100의 자리
# 1000의 자리
# n의 자리


