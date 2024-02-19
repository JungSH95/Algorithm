-- LEVEL2 : 자동차 종류 별 특정 옵션이 포함된 자동차 수 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/151137)
SELECT CAR_TYPE, count(CAR_TYPE) as CARS
FROM CAR_RENTAL_COMPANY_CAR
WHERE OPTIONS LIKE '%시트%'
GROUP BY CAR_TYPE
ORDER BY CAR_TYPE ASC


-- LEVEL3 : 대여 횟수가 많은 자동차들의 월별 대여 횟수 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/151139)

-- 내가 풀었던 방식인데 채점 시 계속 실패함
-- SELECT MONTH(START_DATE) as MONTH, CAR_ID, COUNT(*) AS RECORDS
-- FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
-- WHERE CAR_ID IN 
--     (SELECT CAR_ID
--         FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
--         WHERE YEAR(START_DATE) = 2022 AND 8 <= MONTH(START_DATE) <= 10
--         GROUP BY CAR_ID
--         HAVING COUNT(CAR_ID) >= 5)
-- GROUP BY MONTH, CAR_ID
-- HAVING RECORDS > 0
-- ORDER BY MONTH ASC, CAR_ID DESC

-- 추가 학습 내용 : GROUP BY 사용 시 여러 개인 경우 첫 번째 칼럼으로 먼저 그룹이 묶이고, 두 번째 칼럼으로 집계
-- + WHERE CAR_ID IN (...)이 외에도 추가로 AND를 해줘야 했다.
-- ex) (...)에 해당됐던 CAR_ID 중에 8~10월이 아닌 케이스가 포함된 경우

-- 다른 사람 풀이를 보니 기간 확인을 "START_DATE BETWEEN '2022-08-01' AND '2022-10-31'" 이 방식을 사용함
-- 이 방식으로 교체하니 성공함.
-- "YEAR(START_DATE) = 2022 AND MONTH(START_DATE) IN (8, 9, 10)" 이 방식으로 교체 시 성공함
-- "DATE('2022-08-01') <= START_DATE AND START_DATE <= DATE('2022-10-31')" 이것도 가능
SELECT MONTH(START_DATE) as MONTH, CAR_ID, COUNT(*) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE CAR_ID IN 
    (SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
        GROUP BY CAR_ID
        HAVING COUNT(CAR_ID) >= 5)
    AND START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
GROUP BY MONTH, CAR_ID
HAVING RECORDS > 0
ORDER BY MONTH ASC, CAR_ID DESC

-- "8 <= MONTH(START_DATE) <= 10" 이 방식이 안됐던 것임
-- "8 <= MONTH(START_DATE) AND MONTH(START_DATE) <= 10"로 변경 후 성공함



-- LEVEL3 : 자동차 대여 기록에서 대여중 / 대여 가능 여부 구분하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/157340)
SELECT CAR_ID,
    CASE 
        WHEN CAR_ID IN (SELECT CAR_ID
                        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                        WHERE '2022-10-16' BETWEEN START_DATE AND END_DATE) THEN '대여중'
        ELSE '대여 가능'
    END  AS 'AVAILABILITY'
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
ORDER BY CAR_ID DESC
-- 특정 조건에 해당 유무에 따라서 대여가능/대여중으로 표기하는 방법인
-- CASE문을 학습 및 처음 적용해봄



-- LEVEL3 : 즐겨찾기가 가장 많은 식당 정보 출력하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/131123)

-- 1트(실패)
-- 원인 : 스시사카우스(일식	230)가 아닌 하이가쯔네로 검색됨
SELECT FOOD_TYPE, REST_ID, REST_NAME, MAX(FAVORITES) as 'FAVORITES'
FROM REST_INFO
GROUP BY FOOD_TYPE
ORDER BY FOOD_TYPE DESC

-- 2트(성공)
SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM REST_INFO
WHERE FAVORITES IN 
    (SELECT MAX(FAVORITES)
    FROM REST_INFO
    GROUP BY FOOD_TYPE)
GROUP BY FOOD_TYPE
ORDER BY FOOD_TYPE DESC


-- LEVEL3 : 조건에 맞는 사용자와 총 거래금액 조회하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/164668)
-- 1트(성공)
SELECT USER.USER_ID, USER.NICKNAME, SUM(BOARD.PRICE) AS TOTAL_SALES
FROM USED_GOODS_USER AS USER
JOIN USED_GOODS_BOARD AS BOARD ON USER.USER_ID = BOARD.WRITER_ID
WHERE BOARD.STATUS = 'DONE'
GROUP BY USER.USER_ID
HAVING SUM(BOARD.PRICE) >= 700000
ORDER BY TOTAL_SALES ASC


-- LEVEL3 : 카테고리 별 도서 판매량 집계하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/144855)
SELECT BOOK.CATEGORY, SUM(SALES.SALES) AS TOTAL_SALES
FROM BOOK AS BOOK
JOIN BOOK_SALES AS SALES ON BOOK.BOOK_ID = SALES.BOOK_ID
WHERE DATE_FORMAT(SALES.SALES_DATE, '%Y-%m') = '2022-01'
GROUP BY BOOK.CATEGORY
ORDER BY BOOK.CATEGORY ASC

