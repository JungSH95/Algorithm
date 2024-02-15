-- LEVEL1 : 과일로 만든 아이스크림 고르기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/133025)
SELECT A.FLAVOR
FROM FIRST_HALF A, ICECREAM_INFO B
WHERE A.FLAVOR = B.FLAVOR AND A.TOTAL_ORDER > 3000 AND B.INGREDIENT_TYPE = 'fruit_based'
ORDER BY TOTAL_ORDER DESC


-- LEVEL1 : 조건에 맞는 도서 리스트 출력하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/144853)
SELECT BOOK_ID, DATE_FORMAT(PUBLISHED_DATE, "%Y-%m-%d") AS PUBLISHED_DATE
FROM BOOK
WHERE CATEGORY='인문' AND YEAR(PUBLISHED_DATE) = 2021
ORDER BY PUBLISHED_DATE ASC


-- LEVEL1 : 12세 이하인 여자 환자 목록 출력하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/132201)
SELECT PT_NAME, PT_NO, GEND_CD, AGE, IFNULL(TLNO, 'NONE') AS TLNO
FROM PATIENT
WHERE AGE <= 12 AND GEND_CD = 'W'
ORDER BY AGE DESC, PT_NAME ASC


-- LEVEL2 : 3월에 태어난 여성 회원 목록 출력하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/131120)
SELECT MEMBER_ID, MEMBER_NAME, GENDER, DATE_FORMAT(DATE_OF_BIRTH, "%Y-%m-%d") AS DATE_OF_BIRTH
FROM MEMBER_PROFILE
WHERE TLNO IS NOT NULL AND MONTH(DATE_OF_BIRTH) = 3 AND GENDER = 'W'
ORDER BY MEMBER_ID ASC


-- LEVEL2 : 재구매가 일어난 상품과 회원 리스트 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/131536)
SELECT USER_ID, PRODUCT_ID
FROM ONLINE_SALE
GROUP BY USER_ID, PRODUCT_ID
HAVING COUNT(PRODUCT_ID) > 1
ORDER BY USER_ID ASC, PRODUCT_ID DESC

