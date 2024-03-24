아직 입양을 못 간 동물 중, 
가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일을 조회하는 SQL문
보호 시작일 순으로 조회

-- 1트(성공)
SELECT NAME, DATETIME
FROM ANIMAL_INS
WHERE ANIMAL_ID NOT IN (SELECT ANIMAL_ID
                       FROM ANIMAL_OUTS)
ORDER BY DATETIME ASC
LIMIT 3

-- 항목이 JOIN으로 분류되어있길래 JOIN을 사용하여 추가로 풀어봄
SELECT INS.NAME, INS.DATETIME
FROM ANIMAL_INS AS INS
LEFT JOIN ANIMAL_OUTS AS OUTS ON INS.ANIMAL_ID = OUTS.ANIMAL_ID
WHERE OUTS.ANIMAL_ID IS NULL
ORDER BY INS.DATETIME ASC
LIMIT 3