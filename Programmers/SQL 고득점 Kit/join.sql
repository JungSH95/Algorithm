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
