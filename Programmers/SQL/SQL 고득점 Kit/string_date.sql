-- LEVEL2 : 조건에 부합하는 중고거래 상태 조회하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/164672)
-- 1트(성공)
SELECT BOARD_ID, WRITER_ID, TITLE, PRICE,
    CASE 
        WHEN STATUS = 'SALE' THEN '판매중'
        WHEN STATUS = 'RESERVED' THEN '예약중'
        WHEN STATUS = 'DONE' THEN '거래완료'
    END AS STATUS
FROM USED_GOODS_BOARD
WHERE USED_GOODS_BOARD.CREATED_DATE = DATE('2022-10-05')
ORDER BY BOARD_ID DESC


-- LEVEL3 : 조회수가 가장 많은 중고거래 게시판의 첨부파일 조회하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/164671)
-- 1트(성공), 문자열 합치는 함수 "CONCAT()"
SELECT CONCAT('/home/grep/src/', FILE.BOARD_ID, '/', FILE.FILE_ID, 
    FILE.FILE_NAME, FILE.FILE_EXT) AS FILE_PATH
FROM USED_GOODS_BOARD AS BOARD
RIGHT JOIN USED_GOODS_FILE AS FILE ON BOARD.BOARD_ID = FILE.BOARD_ID
WHERE VIEWS IN (SELECT MAX(VIEWS)
               FROM USED_GOODS_BOARD)
ORDER BY FILE.FILE_ID DESC


-- LEVEL4 : 자동차 대여 기록 별 대여 금액 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/151141)

-- DATEDIFF(END, START) : 기간 계산 함수
-- ROUND() : 반올림 함수

-- 1트(성공했으나 마음에 안듬, 할인율을 조회했을 때의 결과로 고정해서 THEN을 박아버림)
SELECT HISTORY.HISTORY_ID, 
    ROUND((DATEDIFF(END_DATE, START_DATE) + 1) * CAR.DAILY_FEE
    * (CASE 
        WHEN DATEDIFF(END_DATE, START_DATE) + 1 < 7 THEN 1
        WHEN DATEDIFF(END_DATE, START_DATE) + 1 < 30 THEN 0.95
        WHEN DATEDIFF(END_DATE, START_DATE) + 1 < 90 THEN 0.92
        ELSE 0.85 END)) AS FEE
FROM CAR_RENTAL_COMPANY_CAR as CAR
LEFT JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY  as HISTORY ON CAR.CAR_ID = HISTORY.CAR_ID
LEFT JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN as PLAN ON CAR.CAR_TYPE = PLAN.CAR_TYPE
WHERE CAR.CAR_TYPE = '트럭'
GROUP BY HISTORY.HISTORY_ID
ORDER BY FEE DESC, HISTORY.HISTORY_ID DESC

-- 다른 사람 1번 풀이 내용 적용 (할인율 얻어오기)
CASE 
    WHEN DATEDIFF(END_DATE, START_DATE) + 1 < 7 THEN 1
    WHEN DATEDIFF(END_DATE, START_DATE) + 1 < 30 THEN 
        1 - (SELECT DISCOUNT_RATE
            FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
            WHERE CAR_TYPE = '트럭' AND DURATION_TYPE = '7일 이상') / 100
    WHEN DATEDIFF(END_DATE, START_DATE) + 1 < 90 THEN 
        1 - (SELECT DISCOUNT_RATE
            FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
            WHERE CAR_TYPE = '트럭' AND DURATION_TYPE = '30일 이상') / 100
    ELSE 
        1 - (SELECT DISCOUNT_RATE
            FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
            WHERE CAR_TYPE = '트럭' AND DURATION_TYPE = '90일 이상') / 100
END


-- LEVEL3 : 대여 기록이 존재하지 않는 자동차 리스트 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/157341)
-- 1트(성공)
SELECT HISTORY.CAR_ID
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY AS HISTORY
JOIN CAR_RENTAL_COMPANY_CAR AS CAR ON CAR.CAR_ID = HISTORY.CAR_ID
WHERE HISTORY.START_DATE BETWEEN DATE('2022-10-01') AND DATE('2022-10-31')
    AND CAR_TYPE = '세단'
GROUP BY HISTORY.CAR_ID
ORDER BY HISTORY.CAR_ID DESC

-- 중복 제거하는 다른 방법 : SELECT DISTINCT(HISTORY.CAR_ID)


-- LEVEL4 : 취소되지 않은 진료 예약 조회하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/132204)
-- 1트(성공), LEVEL4 느낌이 아님
SELECT A.APNT_NO, P.PT_NAME, P.PT_NO, A.MCDP_CD, D.DR_NAME, A.APNT_YMD
FROM APPOINTMENT AS A
LEFT JOIN DOCTOR AS D ON A.MDDR_ID = D.DR_ID
LEFT JOIN PATIENT AS P ON A.PT_NO = P.PT_NO
WHERE A.APNT_YMD LIKE '2022-04-13%' AND A.APNT_CNCL_YN = 'N' AND A.MCDP_CD = 'CS'
ORDER BY APNT_YMD ASC

