data = [[2,2,6],[1,5,10],[4,2,9],[3,8,3]]
col = 2
row_begin = 1
row_end = 4

# and(&) or(|) xor(^)

# 특정 원소의 위치를 기준으로, -가 붙어있는 경우 내림차순
# 단일 조건 : sorted(data, key=lambda item:item[0])
# 다중 조건 : sorted(data, key=lambda item:(item[col - 1], -item[0]))

def solution(data, col, row_begin, row_end):
    answer = 0
    row_results = []
    sort_data = sorted(data, key=lambda item:(item[col - 1], -item[0]))
    
    for i in range(row_begin - 1, row_end):
        row_result = 0        
        for j in range(len(sort_data[i])):
            row_result += sort_data[i][j] % (i + 1)
        row_results.append(row_result)

    for i in row_results:
        answer = answer ^ i

    return answer

print(solution(data, col, row_begin, row_end))

