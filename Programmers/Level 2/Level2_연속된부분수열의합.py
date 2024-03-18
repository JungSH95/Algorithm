sequence = [1, 1, 1, 2, 3, 4, 5]
k = 5

# 1트(시간초과), while을 통해 popleft()하는 과정이 시간을 많이 잡아먹는것 같음
from collections import deque
def solution(sequence, k):
    answer = []

    start = -1
    end = -1
    min_len = 987654321
    q = deque()
    for i in range(len(sequence)):
        if k < sequence[i]:
            break

        q.append(sequence[i])
        if start == -1:
            start = i

        totalSequence = sum(q)
        while totalSequence > k:
            q.popleft()
            start += 1
            totalSequence = sum(q)

        if totalSequence == k:
            end = start + len(q) - 1

            if len(q) < min_len:
                min_len = len(q)
                answer.clear()
                answer.append(start)
                answer.append(end)
                if min_len == 1:
                    return answer            

        print(str(q) + " / {} = {}".format(answer, min_len) )

    return answer


# 2트(성공), deque를 제거하고 직접 위치를 옮겨주는 방식으로 수정후 성공함
def solution2(sequence, k):
    start = 0
    end = 0
    result_start = -1
    result_end = -1
    min_len = 987654321
    total = sequence[0]

    while True:
        if total <= k:
            if total == k:
                if min_len > end - start + 1:
                    min_len = end - start + 1
                    result_start = start
                    result_end = end
            end += 1
            if end >= len(sequence):
                break
            total += sequence[end]
        else:
            start += 1
            total -= sequence[start - 1]

    return [result_start, result_end]


print(solution2(sequence, k))