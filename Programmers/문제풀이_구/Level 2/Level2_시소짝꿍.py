weights = [100,180,360,100,270]

result = 0
weights.sort()
for i in range(len(weights)):
    for j in range(i + 1, len(weights)):
        if weights[i] == weights[j]:
            result += 1
        if weights[j] == weights[i] * 2:
            result += 1
        if weights[j] == weights[i] * 3 / 2:
            result += 1
        if weights[j] == weights[i] * 4 / 3:
            result += 1
print(result)
'''
w[i] * (2, 3, 4) == w[j] * (2, 3, 4)
            a                   b
=> w[j] = w[i] * a / b
'''

# list의 길이가 10만이기에 2중 포문 시 시간 초과 발생했음.

# 다른 사람 풀이
# 단일 반복문으로 결과를 도출할 수 있도록 했음
def solution(weights):
    answer = 0    
    dic = {}    

    # 동일한 몸무게의 숫자 확인
    for i in weights:
        if i in dic:
            dic[i] += 1
        else:
            dic[i] = 1

    for i in dic:        
        # 동일한 몸무게의 가능한 조합의 수
        if dic[i] > 1:
            answer += (dic[i] * (dic[i]-1)) / 2
        
        # 각 시소의 거리에 대하여 dic에 존재하는지를 확인하여 쌍 확인
        if i*2 in dic:
            answer += dic[i] * dic[2*i]
        if i*2/3 in dic:
            answer += dic[i] * dic[i*2/3]
        if i*3/4 in dic:
            answer += dic[i] * dic[i*3/4]    
    
    return answer

print(solution(weights))

