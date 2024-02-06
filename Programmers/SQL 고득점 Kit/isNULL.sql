-- LEVEL1 : 나이 정보가 없는 회원 수 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/131528)
SELECT COUNT(*) as USERS
FROM USER_INFO
WHERE USER_INFO.AGE IS NULL
