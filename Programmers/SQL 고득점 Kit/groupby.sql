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