targets = [[4,8],[4,5],[10,14],[11,13],[5,12],[3,7],[1,4]]

def solution(targets):
    answer = 0    
    targets.sort()
    print(targets)
    return answer

# 탐욕법을 생각했으나 기준을 잡기가 모호했음.
# 도저히 방법이 감이 잡히지 않아 결국 다른 사람의 풀이 확인
# 그리드 방식을 사용하여 문제 풀이를 진행해야 했었음

missile_Count = 0
s, e = 0, 0

targets.sort(key=lambda x: [x[1], x[0]])
print(targets)

for target in targets:
    # 겹치는 부분을 벗어난 경우 : 겹치지 않기 때문에 무조건 새로운 미사일을 발사해야함.
    if target[0] >= e:
        missile_Count += 1
        e = target[1]
print(missile_Count)

# ** 미사일의 x좌표 범위를 판단할때 시작 지점을 기준으로 생각을 했는데 아니였음.
