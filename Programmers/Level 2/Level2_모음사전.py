word = "AEIOU"

# 1트(성공), 문제 카테고리가 완전탐색으로 주어져버려서 풀기 쉬웠음
def solution(word):
    answer = 1

    replace_word = ['A', 'E', 'I', "O", "U"]
    tmp_word = ['A']

    while True:
        if word == "".join(tmp_word):
            return answer
        
        if len(tmp_word) < 5:
            tmp_word.append('A')
        else:
            if tmp_word[-1] == 'A':
                tmp_word[-1] = 'E'
            elif tmp_word[-1] == 'E':
                tmp_word[-1] = 'I'
            elif tmp_word[-1] == 'I':
                tmp_word[-1] = 'O'
            elif tmp_word[-1] == 'O':
                tmp_word[-1] = 'U'
            elif tmp_word[-1] == 'U':                
                while tmp_word[-1] == 'U':
                    tmp_word.pop()                
                tmp_word[-1] = replace_word[replace_word.index(tmp_word[-1]) + 1]        
        answer += 1

    return answer

print(solution(word))

# 증가되는 수에 따라서 각 자리별 공식을 만들 수 있을 것 같았는데 이걸 한 사람의 풀이
'''
x 가 0이 아닐 때 : f(x) = f(x - 1) + 5^x

f(0) = 1
f(1) = 1 + 5^1 = 6
f(2) = 6 + 5^2 = 31
f(3) = 31 + 5^3 = 156
f(4) = 156 + 5^4 = 781
'''
def solution2(word):    
    answer = 0    
    arr = ['A', 'E', 'I', 'O', 'U']    
    num = [781, 156, 31, 6, 1]    
    
    for i in range(len(word)):        
        answer += arr.index(word[i]) * num[i] + 1    
    return answer
print("solution2 : " + str(solution2(word)))


# 경우의 수가 많지 않아서 아예 모든 단어를 만들고 해당 인덱스를 찾는 방법
from itertools import product 
def solution3(word):    
    word_dic = set()    

    for p in product(["", "A", "E", "I", "O", "U"], repeat = 5):
        word_dic.add("".join(p))    
    word_dic = sorted(word_dic)

    return word_dic.index(word)

print("solution3 : " + str(solution3(word)))
