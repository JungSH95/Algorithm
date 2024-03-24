이 서비스에서는 공간을 둘 이상 등록한 사람을 "헤비 유저"라고 부릅니다.
헤비 유저가 등록한 공간의 정보를 아이디 순으로 조회하는 SQL문을 작성

-- 1트(성공), Level3이라고 하기에는 너무 쉬움
SELECT ID, NAME, HOST_ID
FROM PLACES
WHERE HOST_ID IN (SELECT HOST_ID
                 FROM PLACES
                 GROUP BY HOST_ID
                 HAVING COUNT(HOST_ID) >= 2)
ORDER BY ID ASC

