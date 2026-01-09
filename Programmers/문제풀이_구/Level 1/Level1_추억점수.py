name = ["may", "kein", "kain", "radi"]
yearning = [5, 10, 1, 3]
photo = [
    ["may", "kein", "kain", "radi"],
    ["may", "kein", "brin", "deny"],
    ["kon", "kain", "may", "coni"]
]

# 내 풀이
def solution(name, yearning, photo):
    answer = []
    
    for picture in photo:
        score = 0
        for people in picture:
            if people in name:
                score += yearning[name.index(people)]
        answer.append(score)
    
    return answer

print(solution(name, yearning, photo))

# 다른 사람 풀이 (딕셔너리 사용)
def solution_dict(name, yearning, photo):
    dictionary = dict(zip(name,yearning))
    scores = []
    for pt in photo:
        score = 0
        for p in pt:
            if p in dictionary:
                score += dictionary[p]
        scores.append(score)
    return scores

print(solution_dict(name, yearning, photo))

# 다른 사람 풀이2 (예술)
def solution_얘술(이름, 점수, 사진):
    return [sum(점수[이름.index(j)] for j in i if j in 이름) for i in 사진]

print(solution_얘술(name, yearning, photo))

