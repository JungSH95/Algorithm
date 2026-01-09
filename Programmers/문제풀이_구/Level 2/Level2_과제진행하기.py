plans = [["korean", "11:40", "30"], ["english", "12:10", "20"], ["math", "12:30", "40"]]

import time
import datetime

def solution(plans):
    answer = []

    plans.sort(key=lambda x:x[1])
    stack = []
    running = None

    datetime_format = "%H:%M"
    
    for i in range(0, len(plans)):
        if running == None:
            running = plans[i]
            continue
        
        else:
            run = datetime.datetime.strptime(running[1], datetime_format)            
            next_run = datetime.datetime.strptime(plans[i][1], datetime_format)
            
            # 다음 작업 이전 진행할 수 있는 시간
            diff = next_run - run

            # 작업을 수행한 뒤의 시간
            run += datetime.timedelta(minutes=int(running[2]))

            # 작업 도중 다음 작업이 들어온 경우
            if run > next_run:
                running[2] = str(int(running[2]) - int(diff.seconds / 60))
                print(running)
                stack.append(running)

            # 작업 완료 후 다음 작업까지의 시간이 남은 경우
            elif run < next_run:
                answer.append(running[0])

                # 빈 시간 계산
                diff = next_run - run
                rest_time = int(diff.seconds / 60)

                # 빈 시간 동안 작업 수행
                while stack:
                    tmp_run = stack.pop()
                    if int(tmp_run[2]) > rest_time:
                        tmp_run[2] = str(int(tmp_run[2]) - rest_time)
                        stack.append(tmp_run)
                        break
                    else:
                        rest_time -= int(tmp_run[2])
                        answer.append(tmp_run[0])                        

            # 현재 작업과 다음 작업이 딱 떨어지는 경우
            else:
                answer.append(running[0])

            running = plans[i]

    # 진행중이던 작업 마무리
    answer.append(running[0])

    # 나머지 작업 마무리
    while stack:
        rest_run = stack.pop()
        answer.append(rest_run[0])

    print("작업 완료 순서 : " + str(answer))
    return answer

solution(plans)




# Time 사용법 재숙지할 수 있었음.
# datetime.strptime, timedelta 사용 시 import 문제가 있었음
# datetime, timedelta는 모두 class 였음. 함수X
# 파이썬에서는 stack 자료구조를 list로 사용하나봄, 별도 stack이 없음
