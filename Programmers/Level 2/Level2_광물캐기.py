# 소유중인 다이아/철/돌 곡괭이 수
picks = [0,1,1]
# 광물(3가지 종류), 광물의 최소 수 : 5, 최대 수 : 50
minerals = ["diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"]


def getFatigue(pick, mineral):
    if pick == "iron":
        if mineral == "diamond":
            return 5
    elif pick == "stone":
        if mineral == "diamond":
            return 25
        elif mineral == "iron":
            return 5
    return 1


def dfs(pick, picks, minerals, fatigue):
    if  len(minerals) == 0:
        return fatigue
        
    next_minerals = minerals
    next_picks = picks.copy()

    if len(pick) != 0:
        for mineral in minerals[0:5]:
             fatigue += getFatigue(pick, mineral)
        next_minerals = minerals[5:]

        if pick == "diamond":
            next_picks[0] -= 1
        elif pick == "iron":
            next_picks[1] -= 1
        else:
            next_picks[2] -= 1    

    if sum(next_picks) == 0:
        return fatigue
    
    #print("minerals : " + str(next_minerals) + " / " + str(next_picks) + " / " + str(fatigue))

    tmp_result = []
    if next_picks[0] > 0:
        tmp_result.append(dfs("diamond", next_picks, next_minerals, fatigue))    
    if next_picks[1] > 0:
        tmp_result.append(dfs("iron", next_picks, next_minerals, fatigue))
    if next_picks[2] > 0:
        tmp_result.append(dfs("stone", next_picks, next_minerals, fatigue))

    return min(tmp_result)


def solution(picks, minerals):
    answer = dfs("", picks, minerals, 0)
    return answer

print(solution(picks, minerals))

# 파이썬 숙련도가 많이 부족
# 리스트([])를 대입 연산자로 복사되는 것이 아니라 주소값을 가르켜서 재귀함수 동작 시 문제가 발생했었음.
# 최소값을 찾는 문제라 바로 생각났던 DFS방식이 가장 먼저 떠올라 작성했음.


# 다른 사람 풀이 과정
# 광물을 순서대로 5개 연속으로 캐야하는걸 중요시 생각하여 풀이함
# 1. 5개씩 광물을 묶은 후 각 광물의 수를 Count
# 2. 1번에서 카운트한 광물 리스트를 dia, iron, stone 순으로 정렬
# 3. 2번 결과 돌 곡괭이 기준 피로도가 높은순으로 정렬됨

# 리스트 정렬 시 다중 조건을 줄 때 다음과 같음. '-' 기호는 내림차순
# sorted(cnt_min, key=lambda x:(-x[0], -x[1], -x[2]))

# 소지한 곡괭이의 수에 따른 캘 수 있는 광물의 개수
can_job = sum(picks) * 5

# 광물 조사
cnt_min = [[0, 0, 0]for x in range(10)] # dia, iron, stone
print(cnt_min)

for i in range(len(minerals)):
    if minerals[i] == 'diamond': 
        cnt_min[i//5][0] += 1
    elif minerals[i] == 'iron': 
        cnt_min[i//5][1] += 1
    else : 
        cnt_min[i//5][2] += 1
print(cnt_min)

# 피로도가 높은 순서대로 광물 정렬
sorted_cnt_min = sorted(cnt_min, key = lambda x: (-x[0], -x[1], -x[2]))
print(sorted_cnt_min)

