r1 = 2
r2 = 3

# r2의 원에서 생성할 수 있는 x,y좌표 수 - r1의 원에서 생성할 수 있는 x,y좌표 수
# 하면 되지 않을까?
# 반지름 1 : 내부 1개                   1
# 반지름 2 : 내부 1개 + 8개             3의 2승
# 반지름 3 : 내부 1개 + 8개 + 16개      5의 2승
# 반지름 4 :                           7의 2승
# 반지름 5 :                           9의 2승
# 반지름 n :                           (n*2 - 1) 2승
# **** 실패. 태두리에 점이 있는 경우 있음, 루트 값이 정수로 떨어지는 경우
#print(pow(r2*2 - 1, 2) - pow(r1*2 - 1, 2) + 4)

# 한 사분면에서 반지름(r2) 내에서 x가 1씩 증가하면서 올 수 있는 최대 H값을 먼저 구했음.
# 비슷한 방법으로 반지름(r1) 내에서 x가 1씩 증가하면서 올 수 있는 정수 H값을 구함
import math
answer = 0
for x in range(1, r2 + 1):
    print("{} : ".format(x), end=' ')

    MAX_H = int(math.sqrt(r2**2 - x**2))
    print("MAX_H : " + str(MAX_H), end=' // ')

    MIN_H = 0
    if x < r1:
        MIN_H = math.ceil(math.sqrt(r1**2 - x**2))
    print("MIN_H : " + str(MIN_H), end=' // ')
    print("RESULT : {}".format(MAX_H - MIN_H + 1))
    answer += MAX_H - MIN_H + 1

print("ANSWER : {}".format(answer * 4))