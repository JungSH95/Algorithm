want = ["banana", "apple", "rice", "pork", "pot"]
number = [3, 2, 2, 2, 1]
discount = ["chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot",
             "banana", "apple", "banana"]

def solution(want, number, discount):
    answer = 0
    want_dictionary = dict(zip(want, number))
    print(want_dictionary)

    for i in range(len(discount)):
        if len(discount[i:i+10]) < sum(number):
            break

        print("{}일차 = / PRODUCT : ".format(i + 1), end=' ')
        isAllFind = True
        for product in want:
            if discount[i:i+10].count(product) < want_dictionary.get(product):
                isAllFind = False
                break
            print("{}, {}".format(product, want_dictionary.get(product)), end=' ')
        print()

        if isAllFind == True:
            answer += 1

    return answer

print(solution(want, number, discount))

print(discount.count("apple"))

# 쉽게 풀은 문제


# 다른 사람 풀이, 방식은 동일하지만 코드가 마음에 들어서 긁어옴
# "Counter"사용
from collections import Counter 
def solution(want, number, discount):
    best_day = 0
    want_number = dict(zip(want, number))

    for i in range(len(discount) - 10 + 1):
        if want_number == Counter(discount[i:i + 10]):            
            best_day += 1
    return best_day
