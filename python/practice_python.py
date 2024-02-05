
#answer = input("hello world 승현 : ")

# 조건문, 반복문
'''
if True:
    print("뭐하지 ? {}".format(answer))
elif False:
    print("몰라")
else:
    print("몰라 %d" % 5)

for tmp in [1,2]:
    print("숫자 출력1 : {}".format(tmp))

for tmp in range(1,2):
    print("숫자 출력2 : {}".format(tmp))

index = 5
while index >= 1:
    print("While 실행중 {}".format(index))
    index -=1
'''

# 한 줄 for문
'''
students = ["Iron man", "Thor", "I am groot"]
students = [len(i) for i in students]
print(students)
'''

'''
from random import *

tmpCount = 0
for count in range(1, 51):
    taken_time = randint(5,50)
    if 5 <= taken_time <= 15:
        tmpCount += 1
        print("[O] {}번째 손님 (소요시간 : {})".format(count, taken_time))
    else:
        print("[X] {}번째 손님 (소요시간 : {})".format(count, taken_time))

print("총 탑승 승객 : " + str(tmpCount) + "분")
'''

# 기본 함수 
'''
def open_1():
    print("열었다")

def open_2(name, age):
    print("{}의 나이는 {}이다".format(name, age))
    return age

# 함수 기본값 설정, 반환값 여러개
def open_3(age, later = 1):
    return age, age + later

open_1()
open_2("정승현", 30)
#open_2(input("이름 입력 : "), input("나이 입력 : "))
age, new_age = open_3(30, 3)
print("age : {} , later Age : {}".format(age, new_age))

# 함수 호출 시 각 변수에 값을 지정할 수 있음
open_2(age = 30, name = "정승현")
'''

# 가변인자를 통한 함수 호출
'''
def profile(name, age, *language):
    print("이름 : {}\t나이 : {}\t".format(name, age), end = " ")
    for lang in language:
        print(lang, end=" ")
    print()

profile("정승현", 30, "C/C++", "C#", "Python")
'''

# 함수에서의 전역변수 사용
'''
age = 30

def add_age(year):
    global age      # 전역 공간에 있는 age 사용
    age += year
    print("새로운 나이 : %d" % age)

print("현재 나이 : %d" % age)
add_age(10)
'''

# 표준입출력
'''
import sys
print("Python", "C/C++", "Java", sep=" , ", end="?")
print("Python", "C/C++", "Java", file=sys.stdout)
print("Python", "C/C++", "Java", file=sys.stderr)
'''

# 사전 + 출력 시 정렬
'''
scores = {"수학":0, "영어":50, "코딩":100}
for subject, score in scores.items():
    # ljust / rjust 공백 채우고 정렬
    print(subject.ljust(8), str(score).rjust(4), sep=":")
'''

# 대기번호 출력 (빈공간 0으로 채우기)
'''
for num in range(1, 11):
    print("대기번호 : " + str(num).zfill(3))
'''

# 데이터 타입 확인
### input으로 들어오는 경우 항상 문자열로 들어옴 ###
'''
print(type(10))
print(type(input("숫자 입력 : ")))
'''

# 빈 자리는 빈공간으로 두고, 오른쪽 정렬을 하되, 총 10자리 공간을 확보
#print("{0: >10}".format(500))

# 양수일 땐 +, 음수일 땐 -로 표시
#print("{0: >+10}".format(500))
#print("{0: >+10}".format(-500))

# 왼쪽 정렬, 빈칸은 '_'로 채움
#print("{0:_<10}".format(500))

# 3자리 마다 콤마를 찍어주고, +- 부호 붙이고, 자릿수 확보
#print("{0:+,}".format(1000000000))
#print("{0:+,}".format(-1000000000))

# 소수점 출력
#print("{0:f}".format(5/3))
#print("{0:.2f}".format(5/3))


# 파일 입출력
# "w" : 덮어쓰기, "a" : 이어쓰기, "r" : 읽기
'''
score_file = open("score.txt", "w1", encoding="utf8")
print("수학 : 0", file=score_file)
score_file.close()

score_file = open("score.txt", "r", encoding="utf8")

# 1: 한 번에 전부
print(score_file.read()) 

# 2: 한 줄씩 출력 및 이동
print(score_file.readline())

# 3: 한 줄씩 읽기
while True:
    line = score_file.readline()
    if not line:
        break
    print(line)

# 4: list 형태로 읽기
lines = score_file.readlines()
for line in lines:
    print(line, end="")

score_file.close()
'''

# pickle, 텍스트 상태의 데이터가 아닌 파이썬 객체 자체를 파일로 저장 
'''
import pickle

# pickle을 사용할 땐 바이너리로 작성해야함
profile_file = open("profile.picke", "wb")
profile = {"이름":"정승현", "나이":30, "취미":["클라이밍", "여행"]}
pickle.dump(profile, profile_file)  # profile에 있는 정보를 file에 저장
profile_file.close()

profile_file = open("profile.pickle", "rb")
profile = pickle.load(profile_file) # file에 있는 정보를 profile에 불러오기
print(profile)
profile_file.close()
'''

# with, 자원을 획득하고, 사용하고, 반납할때 주로 사용
# 파이썬의 컨텍스트 매니저는 "with"절 내에서만 액세스가 가능하고 블록을 나가는 경우 어떤 이유든간에 리소스를 해제
'''
with open("profile.pickle", "rb") as profile_file:
    print(pickle.load(profile_file))

with open("study.txt", "w", encoding="utf8") as study_file:
    study_file.write("파이썬 언어 학습중")

with open("study.txt", "r", encoding="utf8") as study_file:
    print(study_file.read())
'''

# class
class Unit:
    def __init__(self, name, hp):
        self.name = name
        self.hp = hp

    def move(self, location):
        print("{}로 걷다".format(location))
    
class AttackUnit(Unit):
    def __init__(self, name, hp, damage):
        Unit.__init__(self, name, hp)
        self.damage = damage

    def attack(self, location):
        print("{0} : {1} 방향으로 적군을 공격 [공격력 {2}]"\
              .format(self.name, location, self.damage))
        
    def damaged(self, damage):
        print("{} : {} 데미지를 입음".format(self.name, damage))
        self.hp -= damage
        print("{0} : 현재 체력은 {1}임".format(self.name, self.hp))

'''
marine1 = Unit("마린", 40, 5)
marine2 = Unit("마린", 40, 5)
print("이름 : {}, 공격력 : {}".format(marine1.name, marine1.damage))
'''

# 파이썬에서는 class에 선언되지 않은 변수를 외부에서 선언하여 사용할 수 있음
'''
marine1.isCanStim = True
if marine1.isCanStim == True:
    print("TEMP Stim")
'''

# 하지만 선언한 특정 변수에서만 해당 변수가 추가되는 것이므로 다른 class 객체에선 사용X
'''
 if marine2.isCanStim == True:
     print("TEMP Stim")
'''

# 다중 상속, 메소드 오버라이딩(move)
class Flyable:
    def __init__(self, flying_speed):
        self.flying_speed = flying_speed

    def fly(self, location):
        print("{}로 날다".format(location))

class FlyableAttackUnit(AttackUnit, Flyable):
    def __init__(self, name, hp, damage, flying_speed):
        AttackUnit.__init__(self, name, hp, damage)
        Flyable.__init__(self, flying_speed)

    # Unit move() 재정의
    def move(self, location):
       self.fly(location)

'''
marine1 = AttackUnit("마린", 40, 5)
marine1.move("11시")
battlecruiser = FlyableAttackUnit("배틀크루저", 500, 25, 3)
battlecruiser.move("9시")
'''

# pass
'''
class BuildingUnit(Unit):
    def __init__(self, name, hp, location):
        pass        # 했다고 치고 넘어감

supply_depot = BuildingUnit("서플라이 디폿", 500, "7시")
'''

# super
class BuildingUnit(Unit):
    def __init__(self, name, hp, location):
        #Unit.__init__(self, name, hp, 0)
        super().__init__(name, hp)
        self.location = location

# 다중상속 시 super를 사용한다면 앞에 상속 받은 class(AttackUnit)만 초기화가 됨
'''
class FlyableAttackUnit(AttackUnit, Flyable):
    def __init__(self, name, hp, damage, flying_speed):
        super().__init__(name, hp, damage)
'''


# 예외처리 (try ~ except)
'''
try:
    nums = []
    nums.append(int(input("숫자 입력 : ")))
    nums.append(int(input("숫자 입력 : ")))
    #nums.append(int(nums[0]/nums[1]))
    print("{} / {} = {}".format(nums[0], nums[1], nums[2]))

except ValueError:
    print("[ERROR] 잘못된 값 입력")

except ZeroDivisionError as err:
    print("[ERROR] Info : {}".format(err))

except Exception as err:
    print("[ERROR] 알 수 없는 에러 발생, {}".format(err))
'''

# 에러 발생시키기 (raise)
'''
try:
    num1 = int(input("숫자 입력 : "))
    num2 = int(input("숫자 입력 : "))

    if num2 == 0:
        raise ZeroDivisionError
    
except ZeroDivisionError as err:
    print("[ERROR] Info : {}".format(err))
'''

# 사용자 정의 예외처리
class BigNumberError(Exception):
    def __init__(self, msg):
        self.msg = msg
    
    def __str__(self):
        return self.msg

try:
    num1 = int(input("숫자 입력 : "))
    num2 = int(input("숫자 입력 : "))
    if num1 >= 10 or num2 >= 10:
        raise BigNumberError("입력값 : {}, {}".format(num1, num2))
    
except BigNumberError as arr:
    print("한 자리 숫자만 입력해라. Detail : {}".format(arr))

# finally는 에러가 발생해도 항상 실행 됨
finally:
    print("TRY문 끝")


