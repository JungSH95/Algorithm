DEVELOPERS 테이블에서 GRADE별 개발자의 정보를 조회하려 합니다. GRADE는 다음과 같이 정해집니다.
A : Front End 스킬과 Python 스킬을 함께 가지고 있는 개발자
B : C# 스킬을 가진 개발자
C : 그 외의 Front End 개발자
GRADE가 존재하는 개발자의 GRADE, ID, EMAIL을 조회하는 SQL문을 작성
결과는 GRADE와 ID를 기준으로 오름차순 정렬

-- 어찌저찌 성공을 했음
-- 비트 연산을 처음 써봄
-- DEVELOP.ID, DEVELOP.EMAIL만 Group By할 시 Error가 발생하여 GRADE 추가
-- -> Grade값 중 null이 포함되는 문제를 확인하여 HAVING을 사용하여 제거함
SELECT CASE
        WHEN DEVELOP.SKILL_CODE & (SELECT SUM(CODE) FROM SKILLCODES WHERE CATEGORY = 'Front End') 
            AND DEVELOP.SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'Python') THEN 'A'    
        WHEN DEVELOP.SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'C#') THEN 'B'
        WHEN DEVELOP.SKILL_CODE & (SELECT SUM(CODE) FROM SKILLCODES WHERE CATEGORY = 'Front End') THEN 'C'
    END AS GRADE,
    DEVELOP.ID, DEVELOP.EMAIL
FROM DEVELOPERS AS DEVELOP
JOIN SKILLCODES AS SKILLCODE ON DEVELOP.SKILL_CODE & SKILLCODE.CODE != 0
GROUP BY GRADE, DEVELOP.ID, DEVELOP.EMAIL
HAVING GRADE IS NOT NULL
ORDER BY GRADE ASC, DEVELOP.ID ASC