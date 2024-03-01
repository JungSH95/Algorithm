--우유(Milk)와 요거트(Yogurt)를 동시에 구입한 장바구니가 있는지
-- 우유와 요거트를 동시에 구입한 장바구니의 아이디를 조회하는 SQL 문
-- 결과는 장바구니의 아이디 순으로

SELECT CART_ID
FROM (SELECT *
      FROM CART_PRODUCTS
      WHERE NAME IN ('Milk', 'Yogurt')
      GROUP BY CART_ID, NAME) AS FIND
GROUP BY CART_ID
HAVING COUNT(CART_ID) >= 2


-- 다른 사람 풀이(1), 캬;; 이렇게도 되네
SELECT CART_ID
FROM CART_PRODUCTS
WHERE NAME IN ('Milk','Yogurt')
GROUP BY CART_ID
HAVING COUNT(DISTINCT NAME)=2

-- 다른 사람 풀이(2), 셀프 조인. 이런것도 있구나
SELECT DISTINCT C.CART_ID
FROM CART_PRODUCTS C,CART_PRODUCTS T
WHERE C.CART_ID = T.CART_ID
      AND (C.NAME ='우유' AND T.NAME ='요거트')
ORDER BY C.CART_ID
