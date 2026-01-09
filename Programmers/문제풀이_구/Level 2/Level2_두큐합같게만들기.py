'''
[1, 2, 1, 2]	[1, 10, 1, 2]	7
6		14	20(10)
[10],		[1, 2, 1, 2, 1, 2, 1]
[10, 1, 2, 1, 2, 1, 2, 1]
[1, 2, 1, 2, 1, 10, 1, 2]


[1, 1]	[1, 5]	-1
2	6	8(4)
[1, 1, 1, 5]

원형큐?
'''

q1 = [1, 2, 1, 2]
q2 = [1, 10, 1, 2]

q1 = [3, 2, 7, 2]
q2 = [4, 6, 5, 1]

from collections import deque

# 1트(실패) : 테스트11,28번 시간 초과
# 2트(성공) : 한 바퀴 돌았을 경우 종료하도록 추가
def solution(queue1, queue2):
    answer = 0

    merge_q = queue1 + queue2
    queue1 = deque(queue1)
    queue2 = deque(queue2)
    sum_q1 = sum(queue1)
    sum_q2 = sum(queue2)
    limit = len(queue1) * 4

    if sum_q1 == sum_q2:
        return 0
    elif max(merge_q) > (sum(merge_q) / 2) or sum(merge_q) % 2 != 0:
        return -1

    while True:
        if answer >= limit:
            return -1
        
        if sum_q1 > sum_q2:
            tmp = queue1.popleft()
            queue2.append(tmp)
            sum_q1 -= tmp
            sum_q2 += tmp
            answer += 1
        elif sum_q1 < sum_q2:
            tmp = queue2.popleft()
            queue1.append(tmp)
            sum_q1 += tmp
            sum_q2 -= tmp
            answer += 1
        else:
            break
    return answer


print("RESULT : " + str(solution(q1, q2)))
