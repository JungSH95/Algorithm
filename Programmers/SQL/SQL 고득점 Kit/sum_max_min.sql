-- LEVEL1 : 최댓값 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/59415)
SELECT MAX(DATETIME) AS '시간'
FROM ANIMAL_INS


-- LEVEL1 : 최솟값 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/59038)
SELECT MIN(DATETIME) AS '시간'
FROM ANIMAL_INS


-- LEVEL1 : 가장 비싼 상품 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/131697)
SELECT MAX(PRICE) AS 'MAX_PRICE'
FROM PRODUCT


-- LEVEL2 : 동물 수 구하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/59406)
SELECT COUNT(ANIMAL_ID) AS 'count'
FROM ANIMAL_INS


-- LEVEL2 : 중복 제거하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/59408)
-- * COUNT() : 함수 사용 시 칼럼의 이름을 사용하면 그 칼럼의 NULL 값을 제외한 개수가 반환됨
-- * DISTINCT : 중복 제거
SELECT COUNT(DISTINCT NAME) as 'count'
FROM ANIMAL_INS


-- LEVEL2 : 가격이 제일 비싼 식품의 정보 출력하기
-- (link : https://school.programmers.co.kr/learn/courses/30/lessons/131115)
SELECT *
FROM FOOD_PRODUCT
WHERE PRICE = (SELECT max(PRICE) FROM FOOD_PRODUCT)