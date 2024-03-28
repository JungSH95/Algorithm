대장균 개체의 ID(ID)와 자식의 수(CHILD_COUNT)를 출력하는 SQL 문을 작성
자식이 없다면 자식의 수는 0으로 출력
결과는 개체의 ID 에 대해 오름차순 정렬

-- 1트(성공), 쪼오끔 생각이 필요했던 문제
SELECT A.ID, COUNT(B.ID) AS CHILD_COUNT
FROM ECOLI_DATA as A
LEFT JOIN ECOLI_DATA as B ON A.ID = B.PARENT_ID
GROUP BY A.ID
ORDER BY A.ID ASC
