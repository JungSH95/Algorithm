book_time = [["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["18:20", "21:20"]]

def timeToMinute(time):
    return int(time[0:2]) * 60 + int(time[3:])

def solution(book_time):    
    book_time.sort()
    rooms = []

    for book in book_time:
        check_in = timeToMinute(book[0])
        check_out = timeToMinute(book[1]) + 10

        print("체크 인/아웃 : {}/{}".format(check_in, check_out))
        print("ROOM TIME TABLE : " + str(rooms))

        if len(rooms) != 0:
            rooms.sort()
            if rooms[0] <= check_in:
                print("ROOM : {} / CHECKIN : {}".format(rooms[0], check_in))
                del rooms[0]
        rooms.append(check_out)

    print(rooms)
    return len(rooms)

print(solution(book_time))



# 다른 사람 풀이 : 누적합 방법 사용
# 속도 비교시에도 나의 풀이보다 상당히 빨랐다.
def solution_prefix_sum(book_time):
    answer = 0
    rooms = [0 for _ in range(24 * 60 + 11)]
    for i in book_time:
        ci = timeToMinute(i[0])
        co = timeToMinute(i[1]) + 10
        rooms[ci] += 1
        rooms[co] -= 1

    # 누적합
    for i in range(1, len(rooms)):
        rooms[i] += rooms[i - 1]
    answer = max(rooms)
    print(rooms)
    return answer
print(solution_prefix_sum(book_time))