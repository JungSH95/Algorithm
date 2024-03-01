-- LEVEL2 : 조건에 맞는 도서와 저자 리스트 출력하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/144854)
SELECT book.BOOK_ID, author.AUTHOR_NAME, DATE_FORMAT(book.PUBLISHED_DATE, "%Y-%m-%d") AS PUBLISHED_DATE
FROM BOOK as book
JOIN AUTHOR as author on book.AUTHOR_ID = author.AUTHOR_ID
WHERE book.CATEGORY = '경제'
ORDER BY book.PUBLISHED_DATE ASC


-- LEVEL3 : 있었는데요 없었습니다
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/59043)
SELECT ins.ANIMAL_ID, ins.NAME
FROM ANIMAL_INS as ins
JOIN ANIMAL_OUTS as outs on ins.ANIMAL_ID = outs.ANIMAL_ID and ins.DATETIME > outs.DATETIME
ORDER BY ins.DATETIME ASC


-- LEVEL3 : 없어진 기록 찾기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/59042)
SELECT outs.ANIMAL_ID, outs.NAME
FROM ANIMAL_OUTS as outs
LEFT OUTER JOIN ANIMAL_INS as ins ON ins.ANIMAL_ID = outs.ANIMAL_ID
WHERE ins.ANIMAL_ID IS NULL

--- LEFT OUTER JOIN : 왼쪽 테이블의 모든 값이 출력되는 조인
--- RIGHT OUTER JOIN : 오른쪽 테이블의 모든 값이 출력되는 조인
--- FULL OUTER JOIN : 왼쪽 또는 오른쪽 테이블의 모든 값이 출력되는 조인


-- LEVEL4 : 보호소에서 중성화한 동물
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/59045)
SELECT ins.ANIMAL_ID, ins.ANIMAL_TYPE, ins.NAME
FROM ANIMAL_INS as ins
LEFT OUTER JOIN ANIMAL_OUTS as outs ON ins.ANIMAL_ID = outs.ANIMAL_ID
WHERE (ins.SEX_UPON_INTAKE LIKE 'Intact%') AND (outs.SEX_UPON_OUTCOME LIKE 'Neutered%' OR outs.SEX_UPON_OUTCOME LIKE 'Spayed%')
ORDER BY ins.ANIMAL_ID ASC

--- > 쓸데없이 복잡하게 생각했는 듯.
--- > 성별이 중성화를 하지 않는 이상 변경될 일이 없음
--- > 다른 사람의 WHERE 절임 "WHERE ins.SEX_UPON_INTAKE != outs.SEX_UPON_OUTCOME"


-- LEVEL4 : 주문량이 많은 아이스크림들 조회하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/133027)
SELECT fh.FLAVOR
FROM FIRST_HALF as fh
JOIN JULY as july ON fh.FLAVOR = july.FLAVOR
GROUP BY fh.FLAVOR
ORDER BY (SUM(fh.TOTAL_ORDER) + SUM(july.TOTAL_ORDER)) DESC
LIMIT 3


-- LEVEL4 : 그룹별 조건에 맞는 식당 목록 출력하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/131124)
-- 1트(성공)
-- 1) 가장 많이 작성한 회원을 조회하는 쿼리 작성 (WHERE에 사용한 SELECT문)
-- 2) 그 후 작성한 회원과 일치하는 것으로 JOIN 및 결과 출력함
SELECT PROFILE.MEMBER_NAME, REVIEW.REVIEW_TEXT, DATE_FORMAT(REVIEW.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
FROM REST_REVIEW AS REVIEW
INNER JOIN MEMBER_PROFILE AS PROFILE ON REVIEW.MEMBER_ID = PROFILE.MEMBER_ID
WHERE REVIEW.MEMBER_ID = (
    SELECT MEMBER_ID
    FROM REST_REVIEW
    GROUP BY MEMBER_ID
    ORDER BY COUNT(MEMBER_ID) DESC
    LIMIT 1
)
ORDER BY REVIEW.REVIEW_DATE ASC, REVIEW.REVIEW_TEXT ASC


-- LEVEL4 : 5월 식품들의 총매출 조회하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/131117)
-- 1트(성공)
SELECT FORDER.PRODUCT_ID, PRODUCT.PRODUCT_NAME, SUM(FORDER.AMOUNT) * PRODUCT.PRICE AS TOTAL_SALES
FROM FOOD_ORDER AS FORDER
JOIN FOOD_PRODUCT AS PRODUCT ON FORDER.PRODUCT_ID = PRODUCT.PRODUCT_ID
WHERE DATE_FORMAT(PRODUCE_DATE, '%Y-%m') = '2022-05'
GROUP BY FORDER.PRODUCT_ID
ORDER BY TOTAL_SALES DESC, FORDER.PRODUCT_ID ASC


-- LEVEL4 : 특정 기간동안 대여 가능한 자동차들의 대여비용 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/157339)
-- 1트(실패) : FEE의 50만원 이상 200만원 미만의 조건을 WHERE로 하려했으나 
--              표준SQL은 WHERE절에서 열 별칭(FEE)에 대한 참조를 허용하지 않는다고 한다.
SELECT CAR.CAR_ID, CAR.CAR_TYPE, ROUND(CAR.DAILY_FEE * (1 - (PLAN.DISCOUNT_RATE / 100)) * 30) AS FEE
FROM CAR_RENTAL_COMPANY_CAR AS CAR
JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS PLAN ON PLAN.CAR_TYPE = CAR.CAR_TYPE
WHERE (CAR.CAR_TYPE = '세단' or CAR.CAR_TYPE = 'SUV') and
    CAR.CAR_ID NOT in (
        SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE END_DATE > '2022-11-01' AND START_DATE < '2022-12-01'
    ) and
    PLAN.DURATION_TYPE = '30일 이상'
GROUP BY CAR.CAR_ID
ORDER BY FEE DESC, CAR.CAR_TYPE ASC, CAR.CAR_ID DESC

-- 2트(성공) : 해당 조건을 GROUP BY의 HAVING을 사용하여 거를 수 있도록 추가
SELECT CAR.CAR_ID, CAR.CAR_TYPE, ROUND(CAR.DAILY_FEE * (1 - (PLAN.DISCOUNT_RATE / 100)) * 30) AS FEE
FROM CAR_RENTAL_COMPANY_CAR AS CAR
JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS PLAN ON PLAN.CAR_TYPE = CAR.CAR_TYPE
WHERE (CAR.CAR_TYPE = '세단' or CAR.CAR_TYPE = 'SUV') and
    CAR.CAR_ID NOT in (
        SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE END_DATE > '2022-11-01' AND START_DATE < '2022-12-01'
    ) and
    PLAN.DURATION_TYPE = '30일 이상'
GROUP BY CAR.CAR_ID
HAVING FEE>=500000 AND FEE<2000000
ORDER BY FEE DESC, CAR.CAR_TYPE ASC, CAR.CAR_ID DESC
