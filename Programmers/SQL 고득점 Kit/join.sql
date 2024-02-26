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
