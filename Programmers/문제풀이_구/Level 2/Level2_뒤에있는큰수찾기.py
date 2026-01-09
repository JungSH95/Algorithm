numbers = [2, 3, 3, 5, 1]

# 1트
def solution(numbers):
    answer = []

    for i in range(len(numbers)):
        isAppend = False

        for j in range(i + 1, len(numbers)):
            if numbers[j] > numbers[i]:
                isAppend = True
                answer.append(numbers[j])
                break
        
        if isAppend == False:
            answer.append(-1)

    return answer

print("RESULT : " + str(solution(numbers)))

# 2트
def solution2(numbers):
    answer = [-1] * len(numbers)

    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):
            if numbers[j] > numbers[i]:
                answer[i] = numbers[j]
                break

    return answer

print("RESULT : " + str(solution2(numbers)))


# 3트 딕셔너리 써보려했으나 가망 없어보임
copy = {i : numbers[i] for i in range(len(numbers))}
sorted_copy = dict(sorted(copy.items(), key=lambda item:item[1], reverse=True))
print(sorted_copy)

#for i in range(len(numbers)):
    #print(sorted_copy[i])
    #print("number[{}] : {} => ({}, {})".format(i - 1, numbers[i - 1], i, sorted_copy[i]))
#print(sorted_copy[i])

for key, value in sorted_copy.items():
    print("key : {}, value : {}".format(key, value))
print("number[{}] : {}".format(len(numbers) - 1, numbers[len(numbers) - 1]))


# 다른 사람 풀이 : 스택을 사용한 인덱스 방법
def solution3(numbers):
    stack = []
    answer = [-1] * len(numbers)
    for i in range(len(numbers)):
        while stack and numbers[stack[-1]] < numbers[i]:
            answer[stack.pop()] = numbers[i]
        stack.append(i)

    return answer

print("RESULT : " + str(solution3(numbers)))